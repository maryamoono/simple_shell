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
  /* Initialize i to 0 */
  unsigned int i = 0; 
  /* Change the loop condition to check for NULL*/
  while (datash->_environ[i] != NULL) 
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
 /* Change av to char **av*/
void set_data(data_shell *datash, char **av)
{
  unsigned int i = 0; // Initialize i to 0
  /* Change av to av */
  datash->av = av; 
  datash->input = NULL;
  datash->args = NULL;
  datash->status = 0;
  datash->counter = 1;

  for (i = 0; __environ[i] != NULL; i++) // Change the loop condition to check for NULL
    ;

  datash->_environ = malloc(sizeof(char *) * (i + 1));

  for (i = 0; __environ[i] != NULL; i++) // Change the loop condition to check for NULL
  {
    datash->_environ[i] = _strdup(_environ[i]);
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
