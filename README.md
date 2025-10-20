# pipex
A UNIX project written in C that recreates the shell pipe behavior. Executes commands like &lt; file1 cmd1 | cmd2 > file2 using processes, pipes, and file descriptors. Focused on mastering inter-process communication and system calls.

## Overview
This project aims to help you understand **inter-process communication**, **pipes**, and **system calls** in UNIX.  
You’ll learn how the shell connects multiple programs using input/output redirection.

## How It Works
The program must be executed as:
```bash
./pipex file1 cmd1 cmd2 file2
```
It behaves exactly like:
```bash
< file1 cmd1 | cmd2 > file2
```
### Example:
```bash
./pipex infile "ls -l" "wc -l" outfile
# Equivalent to:
< infile ls -l | wc -l > outfile
```

## Features
- Executes two commands connected by a pipe  
- Manages file descriptors and process creation with `fork`, `pipe`, and `dup2`  
- Proper error handling for invalid files or commands  
- No memory leaks, no segmentation faults

## Learning Goals
- Understand how UNIX pipes connect processes  
- Work directly with system calls  
- Manage file I/O redirection and process control  
- Strengthen low-level C programming and debugging skills  

## Author
**Rayan Khaled**  
[rayannkhaled@outlook.com] 
[rayan-khaled]
