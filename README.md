# systemd Service Demo with Custom C Shell

## Overview

This project demonstrates how to use systemd to manage a custom C shell program as a background service on a Linux system or AWS EC2 instance.

The shell program from Part 1 was configured to run through a custom ```service file ```using systemd. The project shows how Linux services can be started, stopped, monitored, and managed automatically.

---

### Features
* Demonstrates how systemd works in Linux
* Runs a custom C shell program as a service
* Uses systemctl to manage the service
* Uses journalctl to view service logs
* Demonstrates Linux service management on EC2

---

## Project Structure
```
.
├── shell                 # Compiled shell executable
├── libmylib.so           # Shared library used by shell
├── myshell.service       # systemd service file
├── README.md             # Project documentation
```
## myshell.service File
```
[Unit]
Description=My Custom Shell Service
After=network.target

[Service]
Type=simple
WorkingDirectory=/home/ec2-user
ExecStart=/home/ec2-user/shell
Environment=LD_LIBRARY_PATH=/home/ec2-user
Restart=no

[Install]
WantedBy=multi-user.target
```
## Structure of the ```.service``` File
```
[Unit]
```
Contains general information about the service.

* ```Description=``` gives the service a readable name
* ```After=network.target``` starts the service after networking is available
```
[Service]
```
Defines how the program runs.

* ```Type=simple``` runs a single foreground process
* ```WorkingDirectory=``` sets the working folder
* ```ExecStart=``` specifies the executable to launch
* ```Environment=``` sets environment variables
* ```Restart=no``` disables automatic restart
```
[Install]
```
Controls when the service starts.

* ```WantedBy=multi-user.target``` allows the service to run during normal system startup

---

## Service Management Commands
Reload systemd
```
sudo systemctl daemon-reload
```
Start the service
```
sudo systemctl start myshell.service
```
Stop the service
```
sudo systemctl stop myshell.service
```
Enable service at boot
```
sudo systemctl enable myshell.service
```
Disable service
```
sudo systemctl disable myshell.service
```
Check service status
```
sudo systemctl status myshell.service
```

---

## Viewing Logs with journalctl

View logs:
```
journalctl -u myshell.service
```
Follow logs live:
```
journalctl -u myshell.service -f
```

---

## Example Output
```
Started myshell.service - My Custom Shell Service.
Welcome to Michelle's C Shell!
Type 'help' to see available commands.
myshell>
```
