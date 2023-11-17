#include "shell.h"
/**
 * type_prompt - bhvgcfxd print asign
 * @void: void
 * Return: non
 */
void type_prompt(void)
{
	write(1, "$ ", 2);
}
/**
 * clear_in - clear th input from whitespace and removing any comments
 * @input: that from aprogram command
 * @output: the result
 * Return: nsw
 */
void clear_in(char *input, char *output)
{
	int i = 0;
	int cd =  0;

	if (*input == '#')
	{
		output[i] = '\0';
		return; }
	while (*input != '\0')
	{
		if (*input == '#')
		{
			input--;
			if (*input == ' ')
			{
				input++;
				break; }
			input++;
			cd = 1;
			output[i++] = *input; }
		else if (*input != ' ')
		{
			cd  = 1;
			output[i++] = *input; }
		else if (cd == 1)
		{
			while (*input != '\0')
			{
				if (*input != ' ')
				{
					output[i++] = ' ';
					input--;
					break;
				}
				input++;
			}
		}
		input++;
	}
	output[i] = '\0';
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
		if (read == -1)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		command[strcspn(command, "\n")] = '\0';
		if (command[0] == '#')
		{
			free(command);
			return (strdup(""));
		}
		break;
	}
	output = malloc(sizeof(char *) * (strlen(command) + 1));
	if (output == NULL)
	{
		free(command);
		return (NULL);
	}
	clear_in(command, output);
	free(command);
	return (output);
}
/**
 * get_command_loction - gvcfxd
 * @co: vgcfxd
 * Return: 0
 */
char *get_command_loction(char *co)
{
	char *pa, *path_cy = NULL, *path_tk, *f_path;
	int co_length, dir_length;
	struct stat buffer;

	if (check_path(co) == 0)
	{
		pa = getenv("PATH");
		if (pa)
		{
			path_cy = strdup(pa);
			co_length = strlen(co);
			path_tk = strtok(path_cy, ":");
			while (path_tk != NULL)
			{dir_length = strlen(path_tk);
				f_path = malloc(co_length + dir_length + 2);
				strcpy(f_path, path_tk);
				strcat(f_path, "/");
				strcat(f_path, co);
				strcat(f_path, "\0");
				if (stat(f_path, &buffer) == 0)
				{free(path_cy);
					return (f_path);
				}
				else
				{free(f_path);
					path_tk = strtok(NULL, ":"); }
			}
		}
	}
	else
	{
		if (path_cy != NULL)
			free(path_cy);
		if (stat(co, &buffer) == 0)
			return (co);
		else
			return (NULL); }
	if (path_cy != NULL)
		free(path_cy);
	return (NULL);
}
/**
 * extract_arg - cfxds
 * @input: cfxd
 * @argv: cfxdzs
 * Return: integer
 */
int extract_arg(char *input, char *argv[16])
{
	const char deli[2] = " ";
	char *tk;
	int x = 0;

	tk = strtok(input, deli);
	while (tk != NULL)
	{
		argv[x] = malloc(sizeof(char) * (strlen(tk) + 1));
		strcpy(argv[x++], tk);
		tk = strtok(NULL, deli);
	}
	argv[x] = NULL;
	return (x);
}
