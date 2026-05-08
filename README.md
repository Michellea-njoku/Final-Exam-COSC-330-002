# C Library Menu Program

## Overview

This project demonstrates how to create and use both **static (.a)** and **shared (.so)** libraries in C.
The program provides a simple **menu-driven interface** that allows users to perform basic mathematical operations using functions from a custom reusable library.

---

## Features

* Add two numbers
* Multiply two numbers
* Divide two numbers
* Menu-driven user interface

---

## Project Structure

```
.
├── mylib.c        # Library implementation
├── mylib.h        # Library header file
├── shell.c        # Menu-driven program
├── Makefile       # Builds static and shared libraries
├── libmylib.a     # Static library (generated)
├── libmylib.so    # Shared library (generated)
```

---

## How to Build

Compile everything using the Makefile:

```
make
```

This will generate:

* Static library: `libmylib.a`
* Shared library: `libmylib.so`
* Executable: `shell`

---

## How to Run

Before running, set the shared library path:

```
export LD_LIBRARY_PATH=.
./shell
```

---

## Author

Michelle Njoku
COSC 330-002
