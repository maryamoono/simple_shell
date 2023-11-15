#include "shell.h"
/*
 * free_data - This function frees data structure.
 *
 * @datash: Data structure.
 *
 * Return: No return.
 */
void free_data(data_shell *datash)
{
  unsigned int i = 0; // Initialize i to 0

  while (datash->_environ[i] != NULL) // Change the loop condition to check for NULL
  {
    free(datash->_environ[i]);
    i++;
  }

  free(datash->_environ);
  free(datash->pid);
}

/*
 * set_data - This function initializes data structure.
 *
 * @datash: Data structure.
 * @av: Argument vector.
 *
 * Return: No return.
 */
void set_data(data_shell *datash, char **av) // Change av to char **av
{
  unsigned int i = 0; // Initialize i to 0

  datash->av = av; // Change av to av
  datash->input = NULL;
  datash->args = NULL;
  datash->status = 0;
  datash->counter = 1;

  for (i = 0; _environ[i] != NULL; i++) // Change the loop condition to check for NULL
    ;

  datash->_environ = malloc(sizeof(char *) * (i + 1));

  for (i = 0; _environ[i] != NULL; i++) // Change the loop condition to check for NULL
  {
    datash->_environ[i] = _strdup(environ[i]);
  }

  datash->_environ[i] = NULL;
  datash->pid = RM_itoa(getpid());
}

/*
 * main - Entry point.
 *
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
  data_shell datash;
  (void) ac;

  signal(SIGINT, copy_sigint);
  set_data(&datash, av);
  
  // Perform operations using datash
  
  free_data(&datash);
  
  if (datash.status < 0)
    return (255);
  
  return (datash.status);
}
