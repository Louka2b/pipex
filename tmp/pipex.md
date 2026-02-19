GDG Louka2b
louka2b__
Ne pas déranger

GDG Louka2b
 — 
23/01/2026 12:07
https://en.wikipedia.org/wiki/Flood_fill
Flood fill
Flood fill, also called seed fill, is a flooding algorithm that determines and alters the area connected to a given node in a multi-dimensional array with some matching attribute. It is used in the "bucket" fill tool of paint programs to fill connected, similarly colored areas with a different color, and in games such as Go and Minesweeper for d...
Flood fill
pour so_long
benjilalegende
 — 
27/01/2026 16:18
Type de fichier joint : unknown
libmlx.a
104.27 KB
Type de fichier joint : unknown
libmlx_Linux.a
104.27 KB
les minilibx compile pour ceux qui travaillent de la maison
jaynuine
 — 
28/01/2026 09:51
oui faut juste compiler pour c99 et prier que xwayland fonctionne
benjilalegende
 — 
28/01/2026 13:02
Je crois louka a fini par trouver comment faire 
Jishuashi
 — 
28/01/2026 13:14
https://harm-smits.github.io/42docs/libs/minilibx
42 Docs
MiniLibX
Find code examples, optimization tricks, and much more.
C'est les commande la dessus

sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

Josephine
 — 
04/02/2026 13:55

## Table of Contents

1. [Understanding fork()](#understanding-fork)

1. [The fork() Basics](#the-fork-basics)
2. [Pipes Explained](#pipes-explained)... (13Korestants)

message.txt
63 Ko
cours sur es concepts importants de pipex
﻿

## Table of Contents

1. [Understanding fork()](#understanding-fork)

1. [The fork() Basics](#the-fork-basics)
2. [Pipes Explained](#pipes-explained)
3. [File Descriptors](#file-descriptors)
4. [The fork() and Pipes Code Example](#the-fork-and-pipes-code-example)
5. [Reference Counting in Pipes](#reference-counting-in-pipes)
6. [File Descriptor Lifecycle Stages](#file-descriptor-lifecycle-stages)
7. [Why Concurrency Matters](#why-concurrency-matters)
8. [Real-World Examples](#real-world-examples)
9. [Web Server Architecture](#web-server-architecture)
10. [Everything is a File](#everything-is-a-file)
11. [Devices and Sockets](#devices-and-sockets)

---

## Understanding fork()

### The Concept

`fork()` is a system call that creates a new process by **duplicating the calling process**. After `fork()` is called:

- One process becomes two
- Both processes execute from the point after `fork()`
- Each process has its own memory space

### Why fork() Returns Two Values

The key insight: **`fork()` returns two different values — one to the parent and one to the child.**

```
┌─────────────────────────────────────────────────────────┐
│                   BEFORE fork()                         │
│              One Process Executes                       │
│                 pid = fork();                           │
│                   ONE VALUE                             │
└─────────────────────────────────────────────────────────┘
                        │
                        │ fork() called
                        ▼
┌─────────────────────────────────────────────────────────┐
│                   AFTER fork()                          │
│            TWO SEPARATE PROCESSES                       │
│                                                         │
│  PARENT PROCESS          │      CHILD PROCESS           │
│  ├─ pid = 1001           │      ├─ pid = 0              │
│  │ (child's PID)         │      │ (always 0)            │
│  └─ Own memory space     │      └─ Own memory space     │
│                          │                              │
│ Each process gets        │     Each process has         │
│ its OWN pid variable!    │     its OWN pid variable!    │
└─────────────────────────────────────────────────────────┘
```

**Critical Understanding**: The two processes each have their own `pid` variable in their own memory. They're not sharing the same variable. The parent's `pid` variable holds the child's process ID (e.g., 1001), while the child's `pid` variable holds 0.

### How exit() Works

When execution finishes in a child process, you can use `exit()` for clarity and to prevent accidental parent code execution:

```c
if(pid == 0) {
    // CHILD process
    printf("Child\n");
    exit(EXIT_SUCCESS);  // Explicitly exit the child
}
else if(pid > 0) {
    // PARENT process
    printf("Parent\n");
    wait(NULL);  // Wait for child
}
```

While processes terminate automatically when `main()` returns, using `exit()` is best practice because it:

- Makes intent explicit
- Prevents child from accidentally executing parent-only code
- Signals intentional termination

---

## The fork() Basics

### Example: 8 Prints from 3 fork() Calls

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    fork();      // 1st fork: 2 processes
    fork();      // 2nd fork: 4 processes
    fork();      // 3rd fork: 8 processes
    
    printf("Hello world!\n");  // All 8 processes print
    return 0;
}
```

**Why 8 prints?** After `n` fork calls, you have $2^n$ processes. So $2^3 = 8$.

```
            Process 0
           /         \
      P1(fork)       C1(fork)
      /    \         /    \
  P2(fork)C2(fork)P3(fork)C3(fork)
  /  \    /  \    /  \    /  \
P4  C4  P5  C5  P6  C6  P7  C7
```

Each terminal process prints "Hello world!" once, giving 8 total prints.

### Use Cases for fork()

1. **Server handling multiple clients** - Fork a child for each client
2. **Running programs in background** - Shell forks for each command
3. **Protecting against crashes** - If a child crashes, parent survives
4. **Parallel processing** - Multiple tasks run simultaneously
5. **Process isolation** - Each child is independent

---

## Pipes Explained

### What is a Pipe?

A **pipe** is a **one-way communication channel** between processes. Data flows in one direction:

- Write end (write-only)
- Read end (read-only)
- **Cannot send data backwards through the same pipe**

### Why Two Pipes are Needed

For bidirectional communication, you need **two pipes** (one for each direction):

```
Pipe 1 (fd1): Parent → Child
  - Parent writes to fd1[1]
  - Child reads from fd1[0]

Pipe 2 (fd2): Child → Parent
  - Child writes to fd2[1]
  - Parent reads from fd2[0]
```

**Analogy**: Imagine two people passing notes. You need two envelopes—one for each direction of communication.

### Why Pipes are Better than Sequential Processing

```
WITHOUT pipes (sequential):
cat file.txt > temp.txt       # Wait 5 seconds
grep "ERROR" temp.txt         # Then wait 3 seconds
Total: 8 seconds

WITH pipes (parallel/streaming):
cat file.txt | grep "ERROR"   # Both run simultaneously
Total: ~5 seconds

Timeline with pipes:
cat:   [==== writing to pipe ====]
grep:     [==== reading from pipe ====]
          ↑ OVERLAP! Both running at once
```

Pipes allow **streaming** - grep starts reading while cat is still writing, rather than waiting for all data to be written first.

---

## File Descriptors

### What is a File Descriptor?

A **file descriptor (fd)** is a **process-specific index** that points to a kernel object. It's an abstraction layer:

```
USER PROCESS (User Space)
┌──────────────────────────┐
│ File Descriptor Table    │
├──────────────────────────┤
│ fd 0 → stdin             │
│ fd 1 → stdout            │
│ fd 2 → stderr            │
│ fd 3 → My Object         │
│ fd 4 → My Object         │
└──────────────────────────┘
        │
        ▼ (syscall boundary)

KERNEL SPACE
┌──────────────────────────┐
│ Kernel Objects           │
├──────────────────────────┤
│ Inode 42 (file)          │
│ Socket 157 (connection)  │
│ Pipe 203 (communication) │
│ Device /dev/zero         │
└──────────────────────────┘
```

**Important**: Each process has its OWN file descriptor table. The same fd number (e.g., fd 3) in different processes can point to **different kernel objects**.

### File Descriptor Numbers After fork()

When you `fork()`, the child gets a **copy** of the parent's file descriptor table:

```
PARENT's FD Table         CHILD's FD Table (copy)
┌──────────────────┐     ┌──────────────────┐
│ fd 3 → Pipe 203  │     │ fd 3 → Pipe 203  │
│ fd 4 → Pipe 204  │     │ fd 4 → Pipe 204  │
└──────────────────┘     └──────────────────┘
        │                       │
        └─────────┬─────────────┘
                  │
        Both point to SAME kernel objects!
```

The fd numbers are the same, but they're **independent copies** of the table. However, both point to the same underlying kernel objects, which is how communication happens.

### How the Kernel Knows Read vs. Write

The kernel tracks **metadata** for each file descriptor entry:

```
Process's FD Table:
├─ fd[0] = 3 → Pipe A, mode: READ
└─ fd[1] = 4 → Pipe A, mode: WRITE

When you call write(fd[0], ...):
1. Kernel looks up fd[0]
2. Finds: "mode: READ"
3. Rejects with error ✗

When you call write(fd[1], ...):
1. Kernel looks up fd[1]
2. Finds: "mode: WRITE"
3. Allows write ✓
```

The `pipe()` function has this **hardcoded convention**:

- `fd[0]` = read end (always)
- `fd[1]` = write end (always)

This is a POSIX standard, so all Unix systems follow it.

---

## The fork() and Pipes Code Example

### Full Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int fd1[2];  // Pipe 1: Parent → Child
    int fd2[2];  // Pipe 2: Child → Parent
    char fixed_str[] = "forgeeks.org";
    char input_str[100];
    pid_t p;

    pipe(fd1);
    pipe(fd2);
    scanf("%s", input_str);
    p = fork();

    if (p < 0) {
        fprintf(stderr, "fork Failed");
        return 1;
    }

    // Parent process
    else if (p > 0) {
        char concat_str[100];

        close(fd1[0]);  // Close reading end of Pipe 1
        write(fd1[1], input_str, strlen(input_str) + 1);
        close(fd1[1]);  // Close writing end of Pipe 1

        wait(NULL);  // Wait for child

        close(fd2[1]);  // Close writing end of Pipe 2
        read(fd2[0], concat_str, 100);
        printf("Concatenated string %s\n", concat_str);
        close(fd2[0]);
    }

    // Child process
    else {
        close(fd1[1]);  // Close writing end of Pipe 1
        char concat_str[100];
        read(fd1[0], concat_str, 100);

        int k = strlen(concat_str);
        for (int i = 0; i < strlen(fixed_str); i++)
            concat_str[k++] = fixed_str[i];

        concat_str[k] = '\0';

        close(fd1[0]);  // Close both reading ends
        close(fd2[0]);

        write(fd2[1], concat_str, strlen(concat_str) + 1);
        close(fd2[1]);

        exit(0);
    }
}
```

### Why This Pattern?

- **Pipe 1 (fd1)**: Sends data from parent to child
    - Parent: writes to fd1[1], closes fd1[0]
    - Child: reads from fd1[0], closes fd1[1]
- **Pipe 2 (fd2)**: Sends data from child to parent
    - Child: writes to fd2[1], closes fd2[0]
    - Parent: reads from fd2[0], closes fd2[1]

### Why Close Unused File Descriptors?

1. **Resource management** - FDs are limited (~1024 per process)
2. **Clarity** - Makes code intent explicit
3. **EOF detection** - Pipe returns EOF only when ALL writers close
4. **Prevents bugs** - Stops accidental reads from wrong end

**Critical for EOF**: A pipe only signals EOF when reference count of writers reaches 0. If you don't close unused ends, the system thinks there might still be a writer.

---

## Reference Counting in Pipes

### How Reference Counting Works

The kernel tracks **how many open references** exist to each pipe:

```
Initial state (after fork):
  Parent has fd1[1] → Pipe A  [Reference count = 1]
  Child has fd1[1] → Pipe A   [Reference count = 1]
  Total references = 2

Parent closes fd1[1]:
  Parent's reference gone       [Reference count -= 1]
  Child still has fd1[1] → Pipe A [Reference count = 1]
  Pipe STAYS OPEN (because child still has it)

Child closes fd1[1]:
  Child's reference gone        [Reference count -= 1]
  No more references            [Reference count = 0]
  Pipe is DESTROYED
```

**Analogy**: Like a library book:

- 2 people check it out (2 references)
- Person 1 returns it → book still available (1 reference)
- Person 2 returns it → book shelved away (0 references)

### Why Each Process Must Close Its Own Copy

**File descriptors are copied, not shared.** When you `fork()`:

```
Before fork():
Parent has fd1[1] (its own copy)

After fork():
Parent has fd1[1] (parent's copy)
Child has fd1[1] (child's copy - INDEPENDENT!)

When Parent closes fd1[1]:
Only the parent's copy closes
Child's fd1[1] is still open!

Both must independently close their copies
for the pipe to be truly closed.
```

---

## File Descriptor Lifecycle Stages

### Stage 1: Before fork() - Pipes created

```
┌─────────────────────────────────────────────────────────┐
│                        SINGLE PROCESS                   │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  pipe(fd1) and pipe(fd2) called:                        │
│  ┌──────────────────┐                                    │
│  │ Process FD Table │                                    │
│  ├──────────────────┤                                    │
│  │ fd1[0] = 3 READ  │                                    │
│  │ fd1[1] = 4 WRITE │                                    │
│  │ fd2[0] = 5 READ  │                                    │
│  │ fd2[1] = 6 WRITE │                                    │
│  └──────────────────┘                                    │
│                                                          │
│         ┌──────────────────────────────────────┐         │
│         │  KERNEL SPACE - Pipe 1 & Pipe 2      │         │
│         ├──────────────────────────────────────┤         │
│         │ Pipe 1:                              │         │
│         │  ├─ Read refs:  1 (process)          │         │
│         │  └─ Write refs: 1 (process)          │         │
│         │ Pipe 2:                              │         │
│         │  ├─ Read refs:  1 (process)          │         │
│         │  └─ Write refs: 1 (process)          │         │
│         └──────────────────────────────────────┘         │
│                                                          │
└─────────────────────────────────────────────────────────┘
```

### Stage 2: After fork() - FD tables duplicated

```
┌────────────────────────────────────────────────────────────────┐
│                   PARENT & CHILD CREATED                       │
├────────────────────────────────────────────────────────────────┤
│                                                                  │
│  PARENT PROCESS              │      CHILD PROCESS              │
│  ┌──────────────────┐        │      ┌──────────────────┐       │
│  │ Parent FD Table  │        │      │ Child FD Table   │       │
│  ├──────────────────┤        │      ├──────────────────┤       │
│  │ fd1[0] = 3 READ  │        │      │ fd1[0] = 3 READ  │       │
│  │ fd1[1] = 4 WRITE │        │      │ fd1[1] = 4 WRITE │       │
│  │ fd2[0] = 5 READ  │        │      │ fd2[0] = 5 READ  │       │
│  │ fd2[1] = 6 WRITE │        │      │ fd2[1] = 6 WRITE │       │
│  └──────────────────┘        │      └──────────────────┘       │
│                              │                                  │
│         ┌──────────────────────────────────────┐               │
│         │  KERNEL SPACE - Reference Counts     │               │
│         ├──────────────────────────────────────┤               │
│         │ Pipe 1:                              │               │
│         │  ├─ Read refs:  Parent(1) + Child(1) = 2            │
│         │  └─ Write refs: Parent(1) + Child(1) = 2            │
│         │ Pipe 2:                              │               │
│         │  ├─ Read refs:  Parent(1) + Child(1) = 2            │
│         │  └─ Write refs: Parent(1) + Child(1) = 2            │
│         └──────────────────────────────────────┘               │
│                                                                  │
│         (PARENT EXECUTES FIRST until wait() call)             │
│                                                                  │
└────────────────────────────────────────────────────────────────┘
```

### Stage 3: Parent closes fd1[0]

```
┌────────────────────────────────────────────────────────────────┐
│         PARENT: close(fd1[0])  (doesn't need to read)          │
├────────────────────────────────────────────────────────────────┤
│                                                                  │
│  PARENT PROCESS              │      CHILD PROCESS              │
│  ┌──────────────────┐        │      ┌──────────────────┐       │
│  │ Parent FD Table  │        │      │ Child FD Table   │       │
│  ├──────────────────┤        │      ├──────────────────┤       │
│  │ fd1[0] = CLOSED ✗│        │      │ fd1[0] = 3 READ  │       │
│  │ fd1[1] = 4 WRITE │        │      │ fd1[1] = 4 WRITE │       │
│  │ fd2[0] = 5 READ  │        │      │ fd2[0] = 5 READ  │       │
│  │ fd2[1] = 6 WRITE │        │      │ fd2[1] = 6 WRITE │       │
│  └──────────────────┘        │      └──────────────────┘       │
│                              │                                  │
│         ┌──────────────────────────────────────┐               │
│         │  KERNEL SPACE - Reference Counts     │               │
│         ├──────────────────────────────────────┤               │
│         │ Pipe 1:                              │               │
│         │  ├─ Read refs:  Parent(0) + Child(1) = 1 ↓          │
│         │  └─ Write refs: Parent(1) + Child(1) = 2            │
│         │ Pipe 2:                              │               │
│         │  ├─ Read refs:  Parent(1) + Child(1) = 2            │
│         │  └─ Write refs: Parent(1) + Child(1) = 2            │
│         └──────────────────────────────────────┘               │
│                                                                  │
└────────────────────────────────────────────────────────────────┘
```

### Stage 4: Parent writes to fd1[1] and closes it

```
┌────────────────────────────────────────────────────────────────┐
│  PARENT: write(fd1[1], input_str, ...) then close(fd1[1])     │
├────────────────────────────────────────────────────────────────┤
│                                                                  │
│  PARENT PROCESS              │      CHILD PROCESS              │
│  ┌──────────────────┐        │      ┌──────────────────┐       │
│  │ Parent FD Table  │        │      │ Child FD Table   │       │
│  ├──────────────────┤        │      ├──────────────────┤       │
│  │ fd1[0] = CLOSED  │        │      │ fd1[0] = 3 READ  │       │
│  │ fd1[1] = CLOSED ✗│        │      │ fd1[1] = 4 WRITE │       │
│  │ fd2[0] = 5 READ  │        │      │ fd2[0] = 5 READ  │       │
│  │ fd2[1] = 6 WRITE │        │      │ fd2[1] = 6 WRITE │       │
│  └──────────────────┘        │      └──────────────────┘       │
│                              │                                  │
│         ┌──────────────────────────────────────┐               │
│         │  KERNEL SPACE                        │               │
│         ├──────────────────────────────────────┤               │
│         │ Pipe 1:                              │               │
│         │  ├─ Data in buffer: "hello"          │               │
│         │  ├─ Read refs:  Parent(0) + Child(1) = 1            │
│         │  └─ Write refs: Parent(0) + Child(1) = 1 ↓          │
│         │ Pipe 2:                              │               │
│         │  ├─ Read refs:  Parent(1) + Child(1) = 2            │
│         │  └─ Write refs: Parent(1) + Child(1) = 2            │
│         └──────────────────────────────────────┘               │
│                                                                  │
│  KEY: Pipe 1 write refs = 1 (only Child has it now)           │
│                                                                  │
└────────────────────────────────────────────────────────────────┘
```

### Stage 5: Parent calls wait(NULL) - CHILD NOW EXECUTES

```
┌────────────────────────────────────────────────────────────────┐
│  PARENT: wait(NULL) ← PARENT BLOCKED, CHILD EXECUTION BEGINS  │
├────────────────────────────────────────────────────────────────┤
│                                                                  │
│  PARENT PROCESS              │      CHILD PROCESS              │
│  ┌──────────────────┐        │      ┌──────────────────┐       │
│  │ Parent FD Table  │        │      │ Child FD Table   │       │
│  ├──────────────────┤        │      ├──────────────────┤       │
│  │ fd1[0] = CLOSED  │        │      │ fd1[0] = 3 READ  │       │
│  │ fd1[1] = CLOSED  │        │      │ fd1[1] = CLOSED ✗│       │
│  │ fd2[0] = 5 READ  │        │      │ fd2[0] = 5 READ  │       │
│  │ fd2[1] = 6 WRITE │        │      │ fd2[1] = 6 WRITE │       │
│  └──────────────────┘        │      └──────────────────┘       │
│  (BLOCKED)                   │                                  │
│                              │      CHILD: close(fd1[1])       │
│                              │                                  │
│         ┌──────────────────────────────────────┐               │
│         │  KERNEL SPACE - Reference Counts     │               │
│         ├──────────────────────────────────────┤               │
│         │ Pipe 1:                              │               │
│         │  ├─ Read refs:  Parent(0) + Child(1) = 1            │
│         │  └─ Write refs: Parent(0) + Child(0) = 0 ↓↓         │
│         │     ⚠ ALL WRITERS CLOSED!             │               │
│         │ Pipe 2:                              │               │
│         │  ├─ Read refs:  Parent(1) + Child(1) = 2            │
│         │  └─ Write refs: Parent(1) + Child(1) = 2            │
│         └──────────────────────────────────────┘               │
│                                                                  │
│  CRITICAL: Now Child's read() will get EOF when data consumed  │
│                                                                  │
└────────────────────────────────────────────────────────────────┘
```

### Stage 6: Child reads from fd1[0] and processes

```
┌────────────────────────────────────────────────────────────────┐
│  CHILD: read(fd1[0], ...) → processes string → closes fd1[0]  │
├────────────────────────────────────────────────────────────────┤
│                                                                  │
│  PARENT PROCESS              │      CHILD PROCESS              │
│  ┌──────────────────┐        │      ┌──────────────────┐       │
│  │ Parent FD Table  │        │      │ Child FD Table   │       │
│  ├──────────────────┤        │      ├──────────────────┤       │
│  │ fd1[0] = CLOSED  │        │      │ fd1[0] = CLOSED ✗│       │
│  │ fd1[1] = CLOSED  │        │      │ fd1[1] = CLOSED  │       │
│  │ fd2[0] = 5 READ  │        │      │ fd2[0] = CLOSED ✗│       │
│  │ fd2[1] = 6 WRITE │        │      │ fd2[1] = 6 WRITE │       │
│  └──────────────────┘        │      └──────────────────┘       │
│  (BLOCKED on wait)           │      concat_str =               │
│                              │      "helloforgeeks.org"        │
│                              │                                  │
│         ┌──────────────────────────────────────┐               │
│         │  KERNEL SPACE - Reference Counts     │               │
│         ├──────────────────────────────────────┤               │
│         │ Pipe 1:                              │               │
│         │  ├─ Read refs:  Parent(0) + Child(0) = 0 ↓↓        │
│         │  └─ Write refs: Parent(0) + Child(0) = 0            │
│         │     PIPE 1 COMPLETELY CLOSED                         │
│         │ Pipe 2:                              │               │
│         │  ├─ Read refs:  Parent(1) + Child(0) = 1 ↓          │
│         │  └─ Write refs: Parent(1) + Child(1) = 2            │
│         └──────────────────────────────────────┘               │
│                                                                  │
└────────────────────────────────────────────────────────────────┘
```

### Stage 7: Child writes to fd2[1] and closes it

```
┌────────────────────────────────────────────────────────────────┐
│  CHILD: write(fd2[1], concat_str, ...) then close(fd2[1])     │
├────────────────────────────────────────────────────────────────┤
│                                                                  │
│  PARENT PROCESS              │      CHILD PROCESS              │
│  ┌──────────────────┐        │      ┌──────────────────┐       │
│  │ Parent FD Table  │        │      │ Child FD Table   │       │
│  ├──────────────────┤        │      ├──────────────────┤       │
│  │ fd1[0] = CLOSED  │        │      │ fd1[0] = CLOSED  │       │
│  │ fd1[1] = CLOSED  │        │      │ fd1[1] = CLOSED  │       │
│  │ fd2[0] = 5 READ  │        │      │ fd2[0] = CLOSED  │       │
│  │ fd2[1] = 6 WRITE │        │      │ fd2[1] = CLOSED ✗│       │
│  └──────────────────┘        │      └──────────────────┘       │
│  (BLOCKED on wait)           │      → exit(0)                  │
│                              │                                  │
│         ┌──────────────────────────────────────┐               │
│         │  KERNEL SPACE - Reference Counts     │               │
│         ├──────────────────────────────────────┤               │
│         │ Pipe 1:                              │               │
│         │  [DESTROYED - all refs = 0]          │               │
│         │ Pipe 2:                              │               │
│         │  ├─ Data in buffer: "helloforgeeks.org"             │
│         │  ├─ Read refs:  Parent(1) + Child(0) = 1            │
│         │  └─ Write refs: Parent(1) + Child(0) = 1 ↓          │
│         │     ⚠ ALL CHILD WRITERS CLOSED!      │               │
│         └──────────────────────────────────────┘               │
│                                                                  │
│  RESULT: Child exits → Parent's wait() RETURNS                │
│                                                                  │
└────────────────────────────────────────────────────────────────┘
```

### Stage 8: Parent continues after wait() returns

```
┌────────────────────────────────────────────────────────────────┐
│  PARENT: wait() returns → close(fd2[1]) then read(fd2[0])     │
├────────────────────────────────────────────────────────────────┤
│                                                                  │
│  PARENT PROCESS              │      CHILD PROCESS              │
│  ┌──────────────────┐        │      ┌──────────────────┐       │
│  │ Parent FD Table  │        │      │ Child FD Table   │       │
│  ├──────────────────┤        │      ├──────────────────┤       │
│  │ fd1[0] = CLOSED  │        │      │ (ALL CLOSED)     │       │
│  │ fd1[1] = CLOSED  │        │      │                  │       │
│  │ fd2[0] = 5 READ  │        │      │                  │       │
│  │ fd2[1] = CLOSED ✗│        │      │                  │       │
│  └──────────────────┘        │      └──────────────────┘       │
│      ↓                        │      (Process terminated)        │
│  read(fd2[0]) →              │                                  │
│  "helloforgeeks.org"          │                                  │
│                              │                                  │
│         ┌──────────────────────────────────────┐               │
│         │  KERNEL SPACE - Reference Counts     │               │
│         ├──────────────────────────────────────┤               │
│         │ Pipe 1:                              │               │
│         │  [DESTROYED - not needed anymore]    │               │
│         │ Pipe 2:                              │               │
│         │  ├─ Read refs:  Parent(1) + Child(0) = 1            │
│         │  └─ Write refs: Parent(0) + Child(0) = 0 ↓↓         │
│         │     ALL WRITERS CLOSED - NO MORE DATA                │
│         └──────────────────────────────────────┘               │
│                                                                  │
│  printf("Concatenated string helloforgeeks.org\n");           │
│                                                                  │
└────────────────────────────────────────────────────────────────┘
```

### Stage 9: Parent cleanup and exit

```
┌────────────────────────────────────────────────────────────────┐
│           PARENT: close(fd2[0]) then exit(EXIT_SUCCESS)        │
├────────────────────────────────────────────────────────────────┤
│                                                                  │
│  PARENT PROCESS              │      CHILD PROCESS              │
│  ┌──────────────────┐        │      ┌──────────────────┐       │
│  │ Parent FD Table  │        │      │ (ALL CLOSED)     │       │
│  ├──────────────────┤        │      ├──────────────────┤       │
│  │ fd1[0] = CLOSED  │        │      │ (Process dead)   │       │
│  │ fd1[1] = CLOSED  │        │      └──────────────────┘       │
│  │ fd2[0] = CLOSED ✗│        │                                  │
│  │ fd2[1] = CLOSED  │        │                                  │
│  └──────────────────┘        │                                  │
│  → exit(EXIT_SUCCESS)        │                                  │
│                              │                                  │
│         ┌──────────────────────────────────────┐               │
│         │  KERNEL SPACE - Reference Counts     │               │
│         ├──────────────────────────────────────┤               │
│         │ Pipe 1:                              │               │
│         │  [DESTROYED]                         │               │
│         │ Pipe 2:                              │               │
│         │  ├─ Read refs:  Parent(0) + Child(0) = 0 ↓↓         │
│         │  └─ Write refs: Parent(0) + Child(0) = 0             │
│         │     PIPE 2 DESTROYED                                 │
│         └──────────────────────────────────────┘               │
│                                                                  │
│  ✓ PROGRAM COMPLETE                                            │
│  ✓ ALL RESOURCES FREED                                         │
│                                                                  │
└────────────────────────────────────────────────────────────────┘
```

### Reference Count Format

**Reference count format**: `Process A(X) + Process B(Y) = Total`

- When **Parent(0) + Child(1) = 1**: Only child has it open
- When **Parent(1) + Child(0) = 1**: Only parent has it open
- When **Parent(0) + Child(0) = 0**: Nobody has it → Pipe destroyed
- **Write refs = 0** means no more writers → subsequent reads get EOF

---

## Why Concurrency Matters

### Performance Gain with Parallelism

**Sequential execution (no fork)**:

```
Task 1 [=========] 5 seconds
Task 2          [=========] 5 seconds
Task 3                     [=========] 5 seconds
Total:                                    15 seconds
```

**Parallel execution (with fork)**:

```
Task 1 [=========]
Task 2 [=========]
Task 3 [=========]
Total: 5 seconds (all run simultaneously!)
```

### Why fork() vs Threading?

| Aspect | fork() | Threading |
| --- | --- | --- |
| **Memory** | Separate memory space | Shared memory |
| **Overhead** | Heavy (creating new process) | Light (threads share resources) |
| **Isolation** | High (processes isolated) | Low (shared memory = risks) |
| **Communication** | Hard (need pipes, files) | Easy (direct access) |
| **Performance** | Slower to create | Faster to create |

**When to use fork()**: Want isolation, can afford overhead

**When to use threading**: Want lightweight concurrency, need shared data

---

## Real-World Examples

### 1. Shell command pipelines

```bash
$ cat file.txt | grep "ERROR" | sort
```

Behind the scenes:

```
Parent (shell)
  ├─ fork() → Child 1: runs `cat file.txt`
  ├─ fork() → Child 2: runs `grep "ERROR"`
  └─ fork() → Child 3: runs `sort`

Pipes connect them:
  cat output → pipe1 → grep input
  grep output → pipe2 → sort input
```

### 2. Web server handling multiple clients

The server forks a child for each client connection, allowing simultaneous handling of multiple requests.

### 3. Build system parallel compilation

```bash
$ make -j4  # Compile 4 files in parallel
```

Make forks 4 children, each compiling one file simultaneously.

### 4. Log processing pipeline

```bash
$ tail -f app.log | grep ERROR | mail -s "Alert" admin@company.com
```

Real-time error detection and automatic alerting.

### 5. Data processing (image resizing)

```
1000 photos to resize
  ├─ fork() → Child 1: resize images 1-250
  ├─ fork() → Child 2: resize images 251-500
  ├─ fork() → Child 3: resize images 501-750
  └─ fork() → Child 4: resize images 751-1000
```

Results combined when all done.

### 6. Database replication

Main server handles queries while forked children handle replication to backup servers.

### 7. Git operations

`git push` forks children to:

- Compress objects
- Calculate checksums
- Send to server

All in parallel.

---

## Web Server Architecture

### How a Web Server Works

```c
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_socket = socket(...);
    bind(server_socket, ...);
    listen(server_socket, 5);
    
    while (1) {
        // PARENT waits here
        int client_socket = accept(server_socket, ...);
        printf("Parent: New client connected!\n");
        
        pid_t pid = fork();
        
        if (pid == 0) {
            // CHILD process
            printf("Child %d: Handling client\n", getpid());
            
            char response[] = "HTTP/1.1 200 OK\r\n\r\nHello World!";
            write(client_socket, response, strlen(response));
            
            close(client_socket);
            exit(0);
        } 
        else {
            // PARENT process
            close(client_socket);  // Parent doesn't need this
            // Immediately loop back to accept new clients
        }
    }
    
    return 0;
}
```

### Timeline: Multiple clients connecting

```
TIME  PARENT                    CLIENT 1        CLIENT 2        CLIENT 3
────────────────────────────────────────────────────────────────────────
T0:   listening...

T1:   accept() → client1 ──────────────
      fork()
      └─ CHILD 1 handling...

T2:   back to listening ──────────────→ [sends "Hello"]
                                        [reads response]
      accept() → client2 ──────────────────────────
      fork()
      └─ CHILD 2 handling...

T3:   back to listening ──────────────→ [closes connection]
                                        [CHILD 1 exits]
                                        ──────────────→ [sends "Hello"]
                                                       [reads response]
      accept() → client3 ──────────────────────────────────
      fork()
      └─ CHILD 3 handling...

T4:   waiting for next ───────────────────────────────────→ [closes]
                                                            [CHILD 2 exits]
      [still waiting...]                                   ──────────→ [ready to close]
```

### Process tree visualization

```
            PARENT (PID: 1000)
            listening on port 8080
            waiting for clients
            │
    ┌───────┼───────┐
    │       │       │
fork()   fork()  fork()
    │       │       │
    ▼       ▼       ▼
CHILD 1 CHILD 2 CHILD 3
(PID:1001) (PID:1002) (PID:1003)
handles   handles   handles
Client A  Client B  Client C
```

### Advantages of this design

✅ **Concurrency**: Handle multiple clients simultaneously

✅ **Isolation**: If one client sends bad request and crashes child, others keep running

✅ **Simple logic**: Each child only needs to handle ONE client

✅ **Automatic cleanup**: When child exits, OS frees all resources

### Potential issues and solutions

**Problem**: Too many children (10,000+ concurrent clients)

- Memory intensive
- CPU intensive (too many context switches)

**Solutions**:

1. **Thread pool**: Reuse limited number of worker threads
2. **Event-driven** (like Nginx): Single process handles many clients
3. **Connection limits**: Only accept N connections at a time

---

## Everything is a File

### The Abstraction

**"Everything is a file" means** the kernel abstracts different types of objects and presents them all through the **same interface**: `open()`, `read()`, `write()`, `close()`

```
┌─────────────────────────────────────────────────────────┐
│         USER PERSPECTIVE (What you code with)          │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  UNIFORM INTERFACE:                                     │
│  ┌──────────────────────────────────────────────────┐  │
│  │ int fd = open(something)                         │  │
│  │ read(fd, buffer, size)                           │  │
│  │ write(fd, data, size)                            │  │
│  │ close(fd)                                        │  │
│  └──────────────────────────────────────────────────┘  │
│                                                         │
│  Works the SAME way for:                               │
│  • Regular files                                       │
│  • Directories                                         │
│  • Pipes                                               │
│  • Sockets (networks)                                  │
│  • Devices                                             │
│                                                         │
└─────────────────────────────────────────────────────────┘
             ▲
             │ This is the ABSTRACTION
             │
┌────────────┴─────────────────────────────────────────────┐
│     KERNEL IMPLEMENTATION (What actually happens)        │
├─────────────────────────────────────────────────────────┐
│                                                         │
│  Regular File:          Directory:      Pipe:         │
│  ├─ Inode on disk       ├─ Inode        ├─ Buffer    │
│  ├─ Read from disk      ├─ Read dir     ├─ FIFO      │
│  └─ Complex logic       ├─ entries      └─ Simple    │
│                         └─ Different                  │
│                                                         │
│  Socket:                Device:                       │
│  ├─ Network protocol    ├─ Driver code              │
│  ├─ TCP/UDP stack       ├─ Hardware I/O              │
│  └─ Complex routing     └─ Completely different      │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

### Same code, different objects

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void read_from_something(const char *path) {
    int fd = open(path,... (13 Ko restants)

message.txt
63 Ko
