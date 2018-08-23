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
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	pid_t pid;
	size_t i, buf_size = BUFFER_SIZE, count = 10;
	char buffer[BUFFER_SIZE] = {0};
	char *bufPtr = buffer;
	char **args = malloc(sizeof(*args) * count);
	int cond, status = 0, tokCount = 0, commandCount = 0;
	int isEOF = 0;

	if (!args)
		exit(-1);
	while (1)
	{
		for (i = 0; i < count; i++)
			args[i] = NULL;
		_printf("($) ");
		commandCount++;
		cond = _getline(&bufPtr, &buf_size);
		if (*bufPtr == '\n')
			continue;
		if (cond == -1)
		{
			return (0);
		}
		if (cond == 0)
			return (0);
		if (buffer[cond - 1] != '\n')
			isEOF = 1;
		if (fflush(stdin) == EOF)
		{
			write(1, "Error: unable to flush stdin\n", 29);
			exit(98);
		}
		tokCount = process_string(bufPtr, &args, &count);
		if (!_strcmp(args[0], "exit"))
		{
			if (args[1])
				status = _atoi(args[1]);
			else
				status = 0;
			free(args);
			return (status);
		}
		if (!_strcmp(args[0], "setenv") && tokCount == 3)
		{
			_setenv(env, args[1], args[2]);
			for (i = 0; i < BUFFER_SIZE; i++)
				buffer[i] = 0;
			status = 0;
			tokCount = 0;
			continue;
		}
		if (!_strcmp(args[0], "env") && tokCount == 1)
		{
			print_env(env);
			for (i = 0; i < BUFFER_SIZE; i++)
				buffer[i] = 0;
			status = 0;
			tokCount = 0;
			continue;
		}
		pid = fork();
		if (pid < 0)
		{
			exit(98);
		}
		else if (pid == 0)/* in child process */
		{
			run_command(args, env);
			_printf("%s: %d: No such file or directory\n",
				argv[0], commandCount);
			free(args);
			return (-1);
		}
		else
		{
			wait(&status);
			if (isEOF)
			{
				_printf("($) \n");
				free(args);
				return (0);
			}
			for (i = 0; i < BUFFER_SIZE; i++)
				buffer[i] = 0;
			status = 0;
			tokCount = 0;
		}
	}
}
