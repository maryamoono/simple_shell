#include "shell.h"

/**
 * get_builtin -This function to get builtin
 *  that pais the command in the arg .
 *
 * @cmd: command
 * 
 * Return: function pointer of the builtin command
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{"env", _env },
		{"setenv", _setenv },
		{"unsetenv", _unsetenv },
		{"cd", cd_shell },
		{NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}

