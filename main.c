#include "main.h"
/**
 * main - mnbv
 * Return: vbfg
 */
int main ()
{
char *read_command()
{
	char input[100];
	char output[100];

	clear_in(input, output);
	char *command = read_command();
	free(command);
	return (0);
}
void type_prompt(void)
{
	printf("type a command");
}
void clear_in(char *input, char *output)
{
	input[0] = '\0';
	output[0] = '\0';
}
char *read_commmand(void)
{
	char *command = NULL;
       	size_t in = 0;
	ssize_t line = getline(&command, &in, stdin);
	if (line == -1)
	{
	return (command);
	}
}	
}
