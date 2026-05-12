# EC2 to S3 Communication Program
## Overview

This project demonstrates communication between an EC2 instance and an Amazon S3 bucket using a C program and the AWS CLI.
The program creates a text file containing system information, uploads the file to an S3 bucket, lists the contents of the bucket, and downloads the file back to the EC2 instance.

---

## Features

* Create a file with timestamp and system information
* Upload a file from EC2 to Amazon S3
* List contents of the S3 bucket
* Download the file back to EC2
* Uses IAM roles instead of hardcoded AWS credentials

---

## Project Structure
.
├── s3_transfer.c            # Main C program
├── output.txt               # Generated file uploaded to S3
├── downloaded_output.txt    # File downloaded from S3

---

## Requirements
* AWS EC2 instance
* AWS CLI installed
* GCC compiler installed
* IAM role with S3 permissions attached to EC2

---

## IAM Permissions Used
s3:PutObject – upload files to S3
s3:ListBucket – list bucket contents
s3:GetObject – download files from S3

---

## How to Build
Compile the program using GCC:

gcc s3_transfer.c -o s3_transfer

---

## How to Run

Run the executable:

./s3_transfer

---

## Example Output
Created file: output.txt
Uploading file to S3...
Listing bucket contents:
output.txt
Downloading file from S3...
Downloaded file as: downloaded_output.txt

---

## Temporary AWS Credentials

The EC2 instance obtains temporary credentials through an IAM role attached to the instance. AWS provides these credentials using the Instance Metadata Service (IMDS), allowing secure access to S3 without storing access keys in the source code.

---

## Author

Michelle Njoku
COSC 330-002
