# Interactive C Shell with Static & Shared Libraries
## Overview

This project demonstrates how to create and use both **static (.a)** and **shared (.so)** libraries in C.

The program is a custom Brennan-style shell interface that allows users to execute commands such as reversing a string, multiplying numbers, and finding square roots using functions stored in a reusable C library.

---

## Features
* Reverse a string
* Multiply two numbers
* Find the square root of a number
* Brennan-style shell prompt
* Static library ```(.a)```
* Shared library ```(.so)```
* Dynamic linking at runtime

---

## Project Structure
```
.
├── mylib.c          # Library implementation
├── mylib.h          # Library header file
├── shell.c          # Brennan-style shell program
├── Makefile         # Builds static and shared libraries
├── libmylib.a       # Static library
├── libmylib.so      # Shared library
├── shell            # Compiled executable
├── README.md        # Project documentation
```

---

## Shell Commands

The shell supports the following commands:
```
reverse hello
multiply 5 3
sqrt 25
help
exit
```
Example:
```
myshell> multiply 5 3
15.00

myshell> reverse hello
olleh

myshell> sqrt 25
5.00
```

---

## Building the Project

Compile the project using:
```
make
```
This generates:

* ```libmylib.a```: Static library
* ```libmylib.so```: Shared library
* ```shell```: Executable program

---

## Running the Program

Before running the shell, set the shared library path:
```
export LD_LIBRARY_PATH=.
```
Run the shell:
```
./shell
```
Or run both commands together:
```
LD_LIBRARY_PATH=. ./shell
```

---

## Makefile Targets

Build everything:
```
make
```
Run the shell:
```
make run
```
Clean generated files:
```
make clean
```

---

## Example Output
```
Welcome to Michelle's C Shell!
Type 'help' to see available commands.

myshell> help

Custom C Shell Commands:
  reverse <text>
  multiply <a> <b>
  sqrt <number>
  help
  exit
```
