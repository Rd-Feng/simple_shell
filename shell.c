#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "myShell.h"
#include "holberton.h"
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
	char *pth;
	char *execStr;

	int i, cond;

	argc += 1;
	env += 1;
	while (1)
	{
		_printf("($) ");
		cond = _getline(&bufPtr, &buf_size);
		if (cond == EOF)
			return (0);
		if (fflush(stdin) == EOF)
		{
			write(1, "Error: unable to flush stdin\n", 29);
			exit(98);
		}
		args = process_string(bufPtr);
		/* TODO - implement exit to check memory leak */
		pid = fork();
		if (pid < 0)
		{
			exit(98);
		}
		else if (pid == 0)/* in child process */
		{
			pth = getenv("PATH");
			execStr = strtok(pth, ":");
			while (execStr)
			{
				execStr = str_concat(execStr, "/");
				execStr = str_concat(execStr, args[0]);
				execve(execStr, args, NULL);
				free(execStr);
				execStr = strtok(NULL, ":");
			}
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
