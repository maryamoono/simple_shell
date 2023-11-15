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
  char *error_p;
  /* Cases of errors */
  switch (error)
  {
    case -1:
      error_p = error_env(datash);
      break;
    case 126:
      error_p = error_path_126(datash);
      break;
    case 127:
      error_p = error_not_found(datash);
      break;
    case 2:
      if (_strcmp("exit", datash->args[0]) == 0)
        error_p = error_exit_shell(datash);
      else if (_strcmp("cd", datash->args[0]) == 0)
        error_p = error_get_cd(datash);
      break;
  }

  if (error_p)
  {
    write(STDERR_FILENO, error_p, _strlen(error_p));
    free(error_p);
  }

  datash->status = error;
  return (error);
}

