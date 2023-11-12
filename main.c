#include "main.h"
/**
 * main - cfxdzs
 * @void: cdx
 * Return: lol
 */
int main(void)
{
	char *input;
	while(1);
	{
		type_prompt();
		input = get_input();
		if (strcmp(input, "exit") == 0)
			break;
		else
			_execute(input);
	}
	return (0);
}

