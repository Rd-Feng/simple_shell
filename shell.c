#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
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
	size_t i, buf_size = BUFFER_SIZE, count = 10;
	char buffer[BUFFER_SIZE] = {0};
	char *bufPtr = buffer;
	char **args = malloc(sizeof(*args) * count);
	int cond, tokCount = 0, inputCount = 0, status = 0;

	signal(SIGINT, sigint_handler);
	if (!args)
		exit(-1);
	while (1)
	{
		for (i = 0; i < count; i++)
			args[i] = NULL;
		_printf("($) ");
		cond = _getline(&bufPtr, &buf_size);
		inputCount++;
		if (cond == -1 || cond == 0)
			return (0);
		tokCount = process_string(bufPtr, &args, &count);
		if (tokCount == 0)
			continue;
		status = run_command(&args, env, tokCount);
		if (status)
			_printf("%s: %d: %s: No such file or directory\n",
                                argv[0], inputCount, args[0]);
		for (i = 0; i < BUFFER_SIZE; i++)
			buffer[i] = 0;
		tokCount = 0;
	}
}
