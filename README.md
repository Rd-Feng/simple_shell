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
| signal_handler.c | handles ctrl-C and other signals |
| str.c | string utilities |
| str2.c | string utilities, cont'd |
| strtok.c | breaks a string into separate tokens using a variable set of delimiters |

## Installation

1. Clone the repository:
```
https://github.com/Rd-Feng/simple_shell.git
```

2. Change directory into project directory:
```
cd simple_shell/
```

3. Compile with all `.c` files
```
gcc -std=c90 -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Begin shell by calling `./hsh`

## Example

Interactive Mode
```
($) ls -l
total 420
-rw-rw-r-- 1 thrownblown thrownblown   151 Aug 29 23:25 AUTHORS
-rw-rw-r-- 1 thrownblown thrownblown  3378 Aug 30 08:07 README.md
-rw-rw-r-- 1 thrownblown thrownblown  2512 Aug 30 07:32 alias.c
-rw-rw-r-- 1 thrownblown thrownblown  1837 Aug 30 07:32 cd.c
-rw-rw-r-- 1 thrownblown thrownblown   936 Aug 30 07:32 exit.c
-rw-rw-r-- 1 thrownblown thrownblown   471 Aug 30 07:22 free_params.c
-rw-rw-r-- 1 thrownblown thrownblown   699 Aug 29 23:25 get_arg.c
-rw-rw-r-- 1 thrownblown thrownblown   622 Aug 30 07:46 get_builtin.c
-rw-rw-r-- 1 thrownblown thrownblown   417 Aug 30 07:44 get_env.c
-rw-rw-r-- 1 thrownblown thrownblown  1306 Aug 30 07:22 get_file.c
-rw-rw-r-- 1 thrownblown thrownblown   591 Aug 30 07:22 get_line.c
-rw-rw-r-- 1 thrownblown thrownblown  2517 Aug 29 23:25 get_sp.c
-rw-rw-r-- 1 thrownblown thrownblown  1740 Aug 29 23:25 get_sp2.c
-rw-rw-r-- 1 thrownblown thrownblown  1525 Aug 30 07:22 holberton.h
-rwxrwxr-x 1 thrownblown thrownblown 50128 Aug 30 08:08 hsh
-rw-rw-r-- 1 thrownblown thrownblown  1629 Aug 30 07:22 linkedlist.c
-rw-rw-r-- 1 thrownblown thrownblown   682 Aug 29 23:25 lists.h
-rw-rw-r-- 1 thrownblown thrownblown  1723 Aug 29 23:25 man_1_simple_shell
-rw-rw-r-- 1 thrownblown thrownblown   594 Aug 30 07:32 printenv.c
-rw-rw-r-- 1 thrownblown thrownblown  2862 Aug 29 23:25 printf.c
-rw-rw-r-- 1 thrownblown thrownblown  1531 Aug 30 07:22 process_string.c
-rw-rw-r-- 1 thrownblown thrownblown   766 Aug 30 07:16 realloc.c
-rw-rw-r-- 1 thrownblown thrownblown   716 Aug 30 07:45 run_command.c
-rw-rw-r-- 1 thrownblown thrownblown    30 Aug 29 23:25 scr
-rw-rw-r-- 1 thrownblown thrownblown  1800 Aug 30 07:32 setenv.c
-rw-rw-r-- 1 thrownblown thrownblown  2753 Aug 30 07:22 shell.c
-rw-rw-r-- 1 thrownblown thrownblown  2021 Aug 30 07:44 shell.h
-rw-rw-r-- 1 thrownblown thrownblown   172 Aug 29 23:25 signal_handler.c
-rw-rw-r-- 1 thrownblown thrownblown  2411 Aug 29 23:25 str.c
-rw-rw-r-- 1 thrownblown thrownblown  1601 Aug 30 07:22 str2.c
-rw-rw-r-- 1 thrownblown thrownblown  1295 Aug 30 07:22 strtok.c
($)
```

Non-Interactive Mode
```
($) echo "ls -l" | ./hsh
total 420
-rw-rw-r-- 1 thrownblown thrownblown   151 Aug 29 23:25 AUTHORS
-rw-rw-r-- 1 thrownblown thrownblown  3378 Aug 30 08:07 README.md
-rw-rw-r-- 1 thrownblown thrownblown  2512 Aug 30 07:32 alias.c
-rw-rw-r-- 1 thrownblown thrownblown  1837 Aug 30 07:32 cd.c
-rw-rw-r-- 1 thrownblown thrownblown   936 Aug 30 07:32 exit.c
-rw-rw-r-- 1 thrownblown thrownblown   471 Aug 30 07:22 free_params.c
-rw-rw-r-- 1 thrownblown thrownblown   699 Aug 29 23:25 get_arg.c
-rw-rw-r-- 1 thrownblown thrownblown   622 Aug 30 07:46 get_builtin.c
-rw-rw-r-- 1 thrownblown thrownblown   417 Aug 30 07:44 get_env.c
-rw-rw-r-- 1 thrownblown thrownblown  1306 Aug 30 07:22 get_file.c
-rw-rw-r-- 1 thrownblown thrownblown   591 Aug 30 07:22 get_line.c
-rw-rw-r-- 1 thrownblown thrownblown  2517 Aug 29 23:25 get_sp.c
-rw-rw-r-- 1 thrownblown thrownblown  1740 Aug 29 23:25 get_sp2.c
-rw-rw-r-- 1 thrownblown thrownblown  1525 Aug 30 07:22 holberton.h
-rwxrwxr-x 1 thrownblown thrownblown 50128 Aug 30 08:08 hsh
-rw-rw-r-- 1 thrownblown thrownblown  1629 Aug 30 07:22 linkedlist.c
-rw-rw-r-- 1 thrownblown thrownblown   682 Aug 29 23:25 lists.h
-rw-rw-r-- 1 thrownblown thrownblown  1723 Aug 29 23:25 man_1_simple_shell
-rw-rw-r-- 1 thrownblown thrownblown   594 Aug 30 07:32 printenv.c
-rw-rw-r-- 1 thrownblown thrownblown  2862 Aug 29 23:25 printf.c
-rw-rw-r-- 1 thrownblown thrownblown  1531 Aug 30 07:22 process_string.c
-rw-rw-r-- 1 thrownblown thrownblown   766 Aug 30 07:16 realloc.c
-rw-rw-r-- 1 thrownblown thrownblown   716 Aug 30 07:45 run_command.c
-rw-rw-r-- 1 thrownblown thrownblown    30 Aug 29 23:25 scr
-rw-rw-r-- 1 thrownblown thrownblown  1800 Aug 30 07:32 setenv.c
-rw-rw-r-- 1 thrownblown thrownblown  2753 Aug 30 07:22 shell.c
-rw-rw-r-- 1 thrownblown thrownblown  2021 Aug 30 07:44 shell.h
-rw-rw-r-- 1 thrownblown thrownblown   172 Aug 29 23:25 signal_handler.c
-rw-rw-r-- 1 thrownblown thrownblown  2411 Aug 29 23:25 str.c
-rw-rw-r-- 1 thrownblown thrownblown  1601 Aug 30 07:22 str2.c
-rw-rw-r-- 1 thrownblown thrownblown  1295 Aug 30 07:22 strtok.c
($)
```
## Builtin Functions

| Builtin | Description | Usage |
| ------- | ----------- | ----- |
| cd | changes the present working directory | ```($) cd [path to dir]``` |
| alias | prints and sets aliases for commands | ```($) alias [name[='value'] ...]``` |
| env | prints all the environment variables | ```($) env``` |
| setenv | sets an environment variable | ```($) setenv VARIABLE VALUE``` |
| unsetenv | removes specified environment variable | ```($) unsetenv VARIABLE``` |
| exit | exits the shell with a specified exit code | ```($) exit [int status]``` |

