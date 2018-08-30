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
Rui Feng https://github.com/Rd-Feng

Alex Fariioletti https://github.com/thrownblown

## Project Requirements
* Must be able to compile with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All files should follow Betty style and document guidelines
* No more than 5 functions per file
* Header files should be include guarded

## Files Included In This Repository

| File | Description |
| ---- | ----------- |
| AUTHORS | Details contributors |
| README.md | You're reading it |
| man_1_simple_shell | manual page |
| scr | ... |
| shell.h | shell function and utility header |
| lists.h | linked list utilities header |
| holberton.h | printf and string utilities |
| alias.c | handles alias builtin for setting and displaying aliases |
| cd.c | handles cd builtin for changing directories |
| exit.c | handles exit builtin to close shell program |
| free_params.c | frees all memory for our state struct |
| get_arg.c | gets the variadic arguments for _printf |
| get_builtin.c | takes a command and retrieves the appropo builtin function |
| get_env.c | gets a specified environment variable |
| get_file.c | gets a specified file to execute |
| get_line.c | gets the command line from stdin |
| get_sp.c | utility functions for _printf |
| get_sp2.c | utility functions for _printf |
| linkedlist.c | utility functions for a singly linked list data structure |
| printenv.c | prints all the environment variables |
| printf.c | prints formatted strings with variables for many types |
| process_string.c | parses the command line string for tokens, arguments, builtins and programs |
| realloc.c | memory reallocation utility |
| run_command.c | checks if command is a builtin and if not tries to execute a command in the PATH |
| setenv.c | utility functions for setting and unsetting environment variables |
| shell.c | our main shell function |
| signal_handler.c | handles ctrl-C and ot |
| str.c | string utilities |
| str2.c | string utilities, cont'd |
| strtok.c | breaks a string into separate tokens using a variable set of delimiters |

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
| get_builtin | desc | args | retval | eaxmple |
| _myExit | desc | args | retval | eaxmple |
