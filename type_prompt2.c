#include "shell.h"
/**
 * free_co - likj
 * @co: command
 * @argem: kujh
 * Return: void
 */
void free_co(char *co, char *argem)
{
	if (co != NULL && co != argem)
		free(co);
}
/**
 * env - lol
 * @void: void
 * Return: nbh
 */
void env(void)
{
	char *env[100];
	int x = 0;

	while (env[x] != NULL)
	{
		write(1, env[x], strlen(env[x]));
		write(1, "\n", 1);
		x++;
	}
}
/**
 * exe_f - execute free
 * @x: vf
 * @n: bh
 * @arge: 20
 * Return: bgv
 */
void execute_f(char *x, char *n ,char *arge[16], int l, unsigned int w)
{
	if (w != 0)
		free(x);
	free_arg(arge, l);
	free_co(n, arge[0]);
}
/**
 * execute - execute
 * @i: index
 * Return: vg
 */
int execute(char *i)
{
	char *co, *arg[16], error[32];
	int stt, b = 0;
	pid_t pid;

	if (i == NULL)
		exit(EXIT_SUCCESS);
	b = extract_arg(i, arg);
	co = arg[0];
	co = get_command_loction(co);
	if (co == NULL)
	{
		strcpy(error, "./hsh: 1: ");
		strcat(error, ": not found\n");
		write(STDERR_FILENO, error, strlen(error));
		execute_f(i, co, arg, b, 0);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		write(STDERR_FILENO, "fork() error\n", 13);
		execute_f(i, co, arg, b, 1);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(co, arg, NULL) == -1)
		{
			perror("execve");
			execute_f(i, co, arg, b, 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &stt, 0) == -1)
		{
			execute_f(i, co, arg, b, 1);
			exit(EXIT_FAILURE);
		}
		execute_f(i, co, arg, b, 0);
		return (WEXITSTATUS(stt));
	}
	execute_f(i, co, arg, b, 0);
	return (0);
}
