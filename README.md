*This project has been created as part of the 42 curriculum by ldeplace.*

---

# PIPEX

## Description

Pipex is a C project focused on handling UNIX pipes and inter-process communication. This project deepens your understanding of a fundamental UNIX mechanism by implementing it from scratch. The goal is to replicate the exact behavior of the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

## Instructions

### Compilation

This project includes a Makefile to automate the compilation process. The Makefile contains all required rules: `NAME`, `all`, `clean`, `fclean`, and `re`, and avoids unnecessary relinking.

To compile the program, run:

```bash
make
```

## Usage

The program requires exactly 4 arguments:
- `file1` - Input file name
- `cmd1` - First shell command with parameters
- `cmd2` - Second shell command with parameters
- `file2` - Output file name

### Command Syntax

```bash
./pipex file1 cmd1 cmd2 file2
```

### Example

```bash
./pipex infile "ls -l" "wc -l" outfile
```

This is equivalent to:

```bash
< infile ls -l | wc -l > outfile
```

## Project Features

- Handling of pipes and inter-process communication
- File descriptor manipulation using `dup2()` and `execve()`
- Process creation and management using `fork()` and `waitpid()`
- Clean memory management with proper heap deallocation and no memory leaks
- Protection against unexpected terminations (segmentation faults, bus errors, double frees, etc.)

## Resources

- [GeeksforGeeks - Pipe System Call](https://www.geeksforgeeks.org/pipe-system-call/)
- [Linux Manual Pages - System Calls Documentation](https://man7.org/linux/man-pages/)

## AI Usage

AI was used to help structure this README file and find relevant resources.
