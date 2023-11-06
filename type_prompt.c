#include "main.h"
/**
 * type_prompt - bhvgcfxd print asign
 * @void: void
 * Return: non
 */
void type_prompt(void)
{
	write(1, "$", 1);
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

	while (input[o] != '\0')
	if (input[o] == '#')
	{
		input[o]--;
		if (input[o] == ' ');
		{
			input[o]++;
			break;
		}
		input[o]++;
		m = 1;
		output[m] = input[o];
		else if (input[o] != ' ')
		{
			m = 1;
			output[m] = input[o];}
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
}
