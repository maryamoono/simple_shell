#include "shell.h"

/**
 * read_line - reads the input string.
 *
 * @read: return value of getline function
 *
 * Return: input string
 */
char *read_line(int *read)
{
	char *input = NULL;
	size_t bufsize = 0;

	*read = getline(&input, &bufsize, stdin);

	return (input);
}
