*This project has been created as part of the 42 curriculum by ldeplace.*

#PIPEX

## Description:
pipex is a C project that focuses on handling UNIX pipes. This project will allow you to explore a UNIX mechanism in detail, one that you are already familiar with, by implementing it in your program. The goal is to replicate exactly the behavior of the following shell command: < file1 cmd1 | cmd2 > file2.

## Instruction:
### compilation:
This project includes a Makefile to automate the compilation process. It must not perform unnecessary relinking and contains the required rules: NAME, all, clean, fclean, and re. To compile the program run the following command in your terminal:
```make```

## Usage:
To run the program, it must be executed with exactly 4 arguments . file1 and file2 are file names . cmd1 and cmd2 are shell commands with their parameters.
```./pipex file1 cmd1 cmd2 file2``` 

### example:
```./pipex infile "ls -l" "wc -l" outfile Its behavior should be equivalent to: < infile ls -l | wc -l > outfile ```

### Project Features:
Handling of pipes and inter-process communication.
File descriptor manipulation using authorized functions like dup2 and execve.
Process creation and management using fork and waitpid.
Clean memory management (all heap-allocated memory is properly freed, no leaks).
Protection against unexpected terminations (segmentation fault, bus error, double free, etc.).

## Resources:
GeeksforGeeks - Pipe System Call:
https://www.geeksforgeeks.org/pipe-system-call/

Linux manual pages - System calls documentation:
https://man7.org/linux/man-pages/

## IA USAGE:
I used AI to help me structure this README file and find relevant resources.	