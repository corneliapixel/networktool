# Network Tool (C & Python)

## Description
This project is a network tool implemented in both C and Python.  
It provides a command-line interface where the user can validate IP addresses and ports, view a log of previous validations, and track total validations.

## Features
- Validate IPv4 addresses (format X.X.X.X, range 0–255)
- Validate port numbers (1–65535)
- Store validation results in a runtime log
- Display validation history with numbering
- Show total number of validations on exit

## Technologies
- Python
- C
- CLI (Command Line Interface)

---

## How to run

### Python
Requires Python 3:
```bash
python3 networktool.py
```

### C 
Compile and run:
```bash 
gcc networktool.c -o ccode
``` 

Run the program:
```bash
./ccode
```
The output binary is named `ccode`.

## Key Learnings

Developing the same tool in both C and Python highlighted key differences between high-level and low-level programming.

### Input handling

Python simplifies input handling, while C requires careful management of data types and input validation.

Using `scanf` caused issues, which led to switching to `fgets` for more robust handling.

### Memory and data structures

Python uses dynamic structures (lists), while C requires fixed-size arrays and manual tracking.

### String handling

Python provides built-in methods like `.strip()`, while C requires manual implementation (e.g. removing newline characters and whitespace).

### Control and structure

C requires more planning (function declarations, memory management), but provides deeper understanding of how programs work internally.

## Summary

Python allowed faster development, while C provided greater control and insight into low-level program behavior.

This project improved my understanding of input validation, program structure, and differences between programming languages.
