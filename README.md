# 0x15. C - Simple Shell
This is a shell interpreter project written in C.

## Goals of this project
At the end of this project, we are expected to be able to explain to anyone, without the help of Google:
* That Ken Thompson designed and implemented the original Unix operating system..
* And wrote the first version of the UNIX shell...
* And invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson? ^^^
* A PID is a Process ID and a PPID is a Parent Process ID, the PID of the process that started it. 
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / "end-of-file"?

## Contributors
Ray Feng https://github.com/Rd-Feng
Alex Fariioletti https://github.com/thrownblown

## Project Requirements
* Must be able to compile with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All files should follow Betty style and document guidelines
* No more than 5 functions per file
* Header files should be include guarded

## Files Included In This Repository

| File | Description |
| ---- | ----------- |
| README.md | You are soaking in it |
| myshell.h | ... |
| myShell.h | ... |
| holberton.h | ... |
| lists.h | ... |
| 100-realloc.c | ... |
| _myExit.c | ... |
| _printenv.c | ... |
| _printf.c | ... |
| _setenv.c | ... |
| get_arg.c | ... |
| get_buildin.c | ... |
| get_env.c | ... |
| get_file.c | ... |
| get_line.c | ... |
| get_sp.c | ... |
| get_sp2.c |  ... |
| linkedlist.c | ... |
| process_string.c | ... |
| run_command.c | ... |
| shell.c | ... |
| signal_handler.c | ... |
| str.c | ... |
| str2.c | ... |
| strtok.c | ... |


## Function Descriptions

| Function | Description | Arguments | Return Value | Example |
| -------- | ----------- | --------- | ------------ | ------- |
| main | Function to feed text commands to OS | args | retval | eaxmple |
| get_char | desc | args | retval | eaxmple |
| get_string | desc | args | retval | eaxmple |
| get_number | desc | args | retval | eaxmple |
| get_arg | desc | args | retval | eaxmple |
| get_binary | desc | args | retval | eaxmple |
| get_rev | desc | args | retval | eaxmple |
| get_rot13 | desc | args | retval | eaxmple |
| str_concat | desc | args | retval | eaxmple |
| string_nconcat | desc | args | retval | eaxmple |
| _strlen | desc | args | retval | eaxmple |
| _printf | desc | args | retval | eaxmple |
| _strchr | desc | args | retval | eaxmple |
| _putchar | desc | args | retval | eaxmple |
| print_list | desc | args | retval | eaxmple |
| list_len | desc | args | retval | eaxmple |
| add_node | desc | args | retval | eaxmple |
| add_node_end | desc | args | retval | eaxmple |
| free_list | desc | args | retval | eaxmple |
| _setenv | desc | args | retval | eaxmple |
| process_string | desc | args | retval | eaxmple |
| _strdup | desc | args | retval | eaxmple |
| _strcpy | desc | args | retval | eaxmple |
| _getline | desc | args | retval | eaxmple |
| _strcmp | desc | args | retval | eaxmple |
| _strtok | desc | args | retval | eaxmple |
| run_command | desc | args | retval | eaxmple |
| _realloc | desc | args | retval | eaxmple |
| _printenv | desc | args | retval | eaxmple |
| sigint_handler | desc | args | retval | eaxmple |
| _atoi | desc | args | retval | eaxmple |
| _getenv | desc | args | retval | eaxmple |
| get_file | desc | args | retval | eaxmple |
| get_buildin | desc | args | retval | eaxmple |
| _myExit | desc | args | retval | eaxmple |
