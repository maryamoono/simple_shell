#include "main.h"
/**
 * type_prompt - bhvgcfxd print asign
 * @void: void
 * Return: non
 */
void type_prompt(void)
{
	write(1, "$", 2);
}
/**
 * clear_in - clear th input from whitespace and removing any comments
 * @input: that from aprogram command
 * @output: the result
 * Return: nsw
 */
void clear_in(char *input, char *output)
{
	int o = 0;
	int m = 0;
	int space = 0;
	while (input[o] != '\0')
	if (input[o] == '#')
	{
		input[o]--;
		if (input[o] == ' ')
		{
			input[o]++;
			space = 1;
			break;
		}
		else
		{
			input[o]++;
			output[m] = input[o];
		}
	}
	else if (input[o] != ' ' || space)
	{
		m = 1;
		output[m] = input[o];
		space = 0;
	}
	else if (m == 1)
	{
		while (input[o] != '\0')
		{
			if (input[o] != ' ')
			{
				output[m] = ' ';
				input[o]++;
			}
			input[m]++;
		}
		input[m]++;
	}
	output[m] = '\0';
}
/**
 * read_command - displays  prompt and waits for the user to type a command
 * @void: void
 * Return: SUCCESS
 */
char *read_command(void)
{
	char *command = NULL;
	char *output = NULL;
	size_t input_size = 0;
	ssize_t read;

	while (1)
	{
		read = getline(&command, &input_size, stdin);
		command[strcspn(command, "\n")] = '\0';
		if (read == -1)
		{
			free(command);
			exit(SUCCESS);
		}
		if (command == 0)
		{
			free(command);
			return (strdup(""));
		}
		break;
		output = malloc(sizeof(char *) *(strlen(command) + 1));
		if (output == NULL)
		{
			free(command);
			return (NULL);
		}
		clear_in(command, output);
		free(command);
		return (output);
	}
}
/**
 *
 *
 *
 */


