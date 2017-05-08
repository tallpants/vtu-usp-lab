## Instructions

### 1. Install CMake

```
$ sudo apt install cmake
```

### 2. Building

```
$ git clone https://github.com/areyoureddy/vtu-usp-lab
$ cd vtu-usp-lab
$ cmake .
$ make
```

### 3. Running

The executables are in the `bin/` directory. Run them from there.

```
$ ./bin/q1

sysconf
========
_SC_OPEN_MAX: The maximum number of files that a process can open is 65536
_SC_CLK_TCK: The number of clock ticks per second is 100
_SC_CHILD_MAX: The maximum number of child processes is 23016

pathconf
=========
_PC_NAME_MAX: The maximum length of a filename in directory '/' is 255
_PC_PATH_MAX: The maximum length of a relative pathname when '/' is the current working directory is: 4096

```

### Question 12

Since q12 is a Yacc program you need to install Yacc (or Bison) and Lex (or Flex) and build it manually:

```
$ yacc src/q12.y
$ cc y.tab.c -o bin/q12
$ ./bin/q12
```