#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "myShell.h"
#include "holberton.h"
#include <string.h>

int _getline(char **lineptr, size_t *n)
{
	static char line[1024];
	char *ptr;
	unsigned int len;

	if (lineptr == NULL || n == NULL)
	{
		//errno = EINVAL;
		return -1;
	}

	read(0, line, 1024);
	/* iterate through line looking for \n */
	ptr = _strchr(line,'\n');
	if (ptr)
		*ptr = '\0';

	len = _strlen(line);
   
   if ((len+1) < 1024)
   {
      //ptr = realloc(*lineptr, 256);
      //if (ptr == NULL)
         //return(-1);
      *lineptr = ptr;
      *n = 1024;
   }

   strcpy(*lineptr, line); 
   return(len);
}
