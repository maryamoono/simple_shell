#include "shell.h"

/*
 * get_error - This function calls the error
 * according to the builtin, syntax, or permission.
 *
 * @datash: Data structure that contains arguments.
 * @error: Error value.
 *
 * Return: Error.
 */
int get_error(data_shell *datash, int error)
{
	char *error1;

	switch (error)
	{
	case -1:
		error1 = error_env(datash);
		break;
	case 126:
		error1 = error_path_126(datash);
		break;
	case 127:
		error1 = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error1 = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error1 = error_get_cd(datash);
		break;
	}

	if (error1)
	{
		write(STDERR_FILENO, error1, _strlen(error1));
		free(error1);
	}

	datash->status = error;
	return (e);
}
