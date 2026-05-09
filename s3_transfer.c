#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    const char *bucket = "michelle-ec2-project-bucket";
    const char *local_file = "output.txt";
    const char *downloaded_file = "downloaded_output.txt";

    FILE *file = fopen(local_file, "w");
    if (file == NULL) {
        perror("Error creating output.txt");
        return 1;
    }

    time_t now = time(NULL);
    struct utsname systemInfo;
    uname(&systemInfo);

    fprintf(file, "EC2 to S3 Transfer Test\n");
    fprintf(file, "Timestamp: %s", ctime(&now));
    fprintf(file, "System: %s\n", systemInfo.sysname);
    fprintf(file, "Node Name: %s\n", systemInfo.nodename);
    fprintf(file, "Machine: %s\n", systemInfo.machine);

    fclose(file);

    printf("Created file: %s\n", local_file);

    char command[512];

    snprintf(command, sizeof(command),
             "aws s3 cp %s s3://%s/%s",
             local_file, bucket, local_file);

    printf("Uploading file to S3...\n");
    if (system(command) != 0) {
        printf("Upload failed.\n");
        return 1;
    }

    snprintf(command, sizeof(command),
             "aws s3 ls s3://%s",
             bucket);

    printf("\nListing bucket contents:\n");
    if (system(command) != 0) {
        printf("Listing failed.\n");
        return 1;
    }

    snprintf(command, sizeof(command),
             "aws s3 cp s3://%s/%s %s",
             bucket, local_file, downloaded_file);

    printf("\nDownloading file from S3...\n");
    if (system(command) != 0) {
        printf("Download failed.\n");
        return 1;
    }

    printf("Downloaded file as: %s\n", downloaded_file);

    return 0;
}
