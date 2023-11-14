#include "shell.h"
/**
 * exit - vcfd
 * @ar: bgvc
 * @txt: lol
 * Return: lol
 */
void exit(char *ar[20], char *txt)
{
	char error[404];

	strcpy(error, "./hsh: 1: ");
	strcat(error, ar[0]);
	strcat(error, ":");
	strcat(error, "\n");
	strcat(error, txt);
	strcat(error, ar[1]);
}
/**
 * num - number is it
 * @x: index
 * Return: xwa
 */
int num(char *x)
{
	while (*x != '\0')
	{
		if (*x >= '0' && *x <= '9')
		{
		}
		else
		{
			return (0);
		}
		x++;
	}
	return (1);
}
/**
 * le_exit - handel exit
 * @x: index
 * Return: fcf
 */
int le_exit(char *x)
{
	char *ar[20];
	int w = 0;
	int m = 0;

	if (x == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	w = extract_args(x, ar);
	if (strcmp(ar[0], "exit") == 0)
	{
		if (ar[1] != NULL)
		{
			if (num(ar[1] == 0))
			{
				exit("uncorrect number: ", ar);
				m = 2;
			}
			else
			{
				m = tic(ar[1]);
				if (m < 0)
				{
					exit("uncorrect number: ", ar);
					m = 2;
				}
			}
		}
	}
	free_ar(ar, w);
	return (m);
}
/**
 * check_exit - nbgv
 * @i: vc
 * Return: vcf
 */
int check_exit(char *i)
{
	int x = 0;
	char rry[6];
	
	for (x = 0 ; x < 6 && i[x] != '\0' ; x++)
	{
		rry[x] = i[x];
	}
	rry[x] = '\0';
	return (strcmp(rry, "exit"));
}