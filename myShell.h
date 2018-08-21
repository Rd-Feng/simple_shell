#ifndef MY_SHELL_H
#define MY_SHELL_H

int process_string(char *, char ***, size_t *);

char *_strdup(char *);

int _strcmp(char *, char *);

char *_strtok(char *, char *);

void run_command(char **args, char **env);

void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);

#endif
