#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
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
	char *arg = NULL;
	int i, j, cond;

	argc += 1;
	env += 1;
	while (1)
	{
		write(1, "($) ", 4);
		cond = getline(&bufPtr, &buf_size, stdin);
		if (cond == EOF)
			return (0);
		if (EOF == fflush(stdin))
		{
			write(1, "Error: unable to flush stdin\n", 29);
			exit(98);
		}
		pid = fork();
		if (pid < 0)
		{
			write(1, "Error: unable to create child process\n", 38);
			exit(98);
		}
		else if (pid == 0)/* in child process */
		{
			arg = strtok(buffer, " \n");
			execve(arg, argv, NULL);
			for (j = 0; &argv[0][j] != '\0'; j++)
				write(1, &argv[0][j], 1);
			write(1,  ": No such file or directory\n", 28);
		}
		else
		{
			wait(NULL);
			for (i = 0; i < BUFFER_SIZE; i++)
				buffer[i] = 0;
		}
	}
}
