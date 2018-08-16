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
	int i, cond;

	argc += 1;
	env += 1;
	while (1)
	{
		printf("($) ");
		cond = getline(&bufPtr, &buf_size, stdin);
		if (cond == EOF)
			return (0);
		if (EOF == fflush(stdin))
		{
			printf("Error: unable to flush stdin\n");
			exit(98);
		}
		pid = fork();
		if (pid < 0)
		{
			printf("Error: unable to create child process\n");
			exit(98);
		}
		else if (pid == 0)/* in child process */
		{
			arg = strtok(buffer, " \n");
			execve(arg, argv, NULL);
			printf("%s: No such file or directory\n", argv[0]);
		}
		else
		{
			wait(NULL);
			for (i = 0; i < BUFFER_SIZE; i++)
				buffer[i] = 0;
		}
	}
}
