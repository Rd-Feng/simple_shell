#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "myShell.h"
#include "holberton.h" /* for _printf */
#define BUFFER_SIZE 1024
/**
 * main - entry point for simple shell
 * @argc: argument count
 * @argv: Null terminated argument list
 * @env: Null terminated environment variables list
 *
 * Return: 0 on success
 */
int main(int argc, char **argv, char **env)
{
	pid_t pid;
	size_t buf_size = BUFFER_SIZE;
	char buffer[BUFFER_SIZE] = {0};
	char *bufPtr = buffer;
	char **args = NULL;
	int i, cond;

	argc += 1;
	env += 1;
	while (1)
	{
		_printf("($) ");
		cond = getline(&bufPtr, &buf_size, stdin);
		if (cond == EOF)
			return (0);
		if (fflush(stdin) == EOF)
		{
			_printf("Error: fail to flush stdin\n");
			exit(98);
		}
		args = process_string(bufPtr);
		if (_strcmp(args[0], "exit") == 0)
		{
			free(args);
			return (0);
		}
		pid = fork();
		if (pid < 0)
		{
			exit(98);
		}
		else if (pid == 0)/* in child process */
		{
			execve(args[0], args, NULL);
			_printf("%s: No such file or directory\n", argv[0]);
		}
		else
		{
			wait(NULL);
			for (i = 0; i < BUFFER_SIZE; i++)
				buffer[i] = 0;
			free(args);
		}
	}
}
