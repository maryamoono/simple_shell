#include "shell.h"
/**
 * main - cfxdzs
 * @void: cdx
 * Return: lol
 */
int main(void)
{
	char *input = NULL;
	int exit_status = 0;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
		{
			type_prompt();
		}
		input = readlinkat();

		if (input == NULL)
		{
			if (is_interactive)
				continue;
			else
				break;
		}
		if (check_exit(input) == 0)
		{
			exit_status = le_exit(input);
			break;
		}
		if (strcmp(input, "env") == 0)
			env();

		else if (strlen(input) > 0)
			exit_status = execute(input);
		if (!is_interactive)
		{
			if (exit_status != 0)
				break;
		}
		free(input);
	}
	free(input);
	if (exit_status != 0)
		exit(exit_status);
	return (exit_status);
}
