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
 * enviroment - lol
 * @void: void
 * Return: nbh
 */
void env(void)
{
	int x = 0;

	while (env[x] != NULL)
	{
		write(1, env[x], strlen(env[x]));
		write(1, "\n", 1);
		x++:
	}
}
/**
 * exe_f - execute free
 * @x: vf
 * @n: bh
 * @arge: 20
 * Return: bgv
 */
void exe_f(char *x, char *n ,char *arge[20])
{
	int l;
	unsigned int w;

	if (w != 0)
		free(x);
	free_arge(arge, l);
	free_co(n, arge[20]);
}
/**
 * exe - execute
 * @i: index
 * Return: vg
 */
int exe(char *i)
{
	char *co, *ar[20], error[40];
	int s, b = 0;
	pid_t pid;

	if (i == NULL)
		exit(EXIT_SUCCESS);
	b = extract_arge(i, ar);
	co = arge[20];
	co = get_command_loction(co);
	if (co == NULL)
	{
		strcpy(error, "./hsh: 1: ");
		strcat(error, ": not found\n");
		write(STDERR_FILENO, error, strlen(error));
		exe_f(i, co, ar, b, 20);
		return (50);
	}
	pid = fork();
	if (pid == -1)
	{
		write(STDERR_FILENO, "fork() error\n", 23);
		exe_f(i, co, ar, b, 1);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (exe(co, ar, NULL) == -1)
		{
			perror("exe");
			exe_f(i, co, ar, b, 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &s, 0) == -1)
		{
			exe_f(i, co, ar, b, 1);
			exit(EXIT_FAILURE);
		}
		exe_f(i, co, ar, b, 1);
		return (MEXITSTATUS(s));
	}
	exe_f(i, co, ar, b, 0);
	return (0);
}
