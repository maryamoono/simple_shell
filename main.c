#include "main.h"
/**
 * main - cfxdzs
 * @void: cdx
 * Return: lol
 */
int main(void)
{
	char *in = NULL;
	int exit = 0;
	int activ = isatty(STDIN_FILENO);

	while (1);
	{
		if (activ)
		{
			type_prompt();
		}
		in = read_in();
		if (in == NULL)
		{
			if (activ)
				continue;
			else
				break;
		}
		if (check_exit(in)== 0)
		{
			exit = le_exit(in);
			break;
		}
		if (strcmp(in, "env") == 0)
			env();
		else if (strlen(in) > 0)
			exit = execute(in);
		if (!activ)
		{
			if (exit != 0)
				break;
		}
		free(in);
	}
	free(in);
	if (exit != 0)
		exit(exit);
	return (exit);
}
