# EC2 to EC2 File Transfer Program

## Overview

This project demonstrates how to transfer files between two AWS EC2 instances using **TCP sockets in Python**.

One EC2 instance acts as the **server**, listening for incoming connections, while the second EC2 instance acts as the client, connecting to the server and sending a file.

The server receives the file, saves it with a new filename, and verifies the file integrity using a **SHA-256 checksum**.

---

## Features
* TCP socket communication between EC2 instances
* File transfer using private IP addresses
* File integrity verification with SHA-256 checksum
* Handles files up to 10 MB
* Error handling for: Connection failures, Missing files, and Oversized files
* Saves received files with a new filename

---

## Project Structure
```
.
├── server.py              # Server program
├── client.py              # Client program
├── file1.txt              # Example file to transfer
├── received_file1.txt     # File received by server
```
---

## How It Works
1. The server starts and listens on TCP port 2222.
2. The client connects to the server using the server’s private IP address.
3. The client sends:
* Filename length
* Filename
* File size
* SHA-256 checksum
* File contents

4. The server receives the file and saves it with the prefix:
```
received_
```
5. The server verifies the checksum to ensure the file was transferred correctly.

---

## AWS Configuration

Both EC2 instances must:

* Be in the same VPC
* Have security group rules allowing TCP traffic on port 2222
* Allow outbound traffic

Example inbound rule:
```
Custom TCP | Port 2222 | Source 0.0.0.0/0
```

---

## How to Run
Start the Server

On the server EC2 instance:
```
python3 server.py
```
Expected output:
```
Server listening on port 2222...
```

---

## Create a Test File

On the client EC2 instance:
```
echo "Hello from client EC2" > file1.txt
```

---

## Send the File

Run the client program using the server’s private IP address:
```
python3 client.py 172.31.39.199 file1.txt
```
Expected output:
```
File sent successfully.
```

---

## Verify the File

On the server EC2 instance:
```
cat received_file1.txt
```
Expected output:
```
Hello from client EC2
```

---

## Technologies Used
* Python 3
* TCP sockets
* AWS EC2
* SHA-256 hashing
