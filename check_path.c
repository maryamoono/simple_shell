#include "main.h"
/**
 * check_path - bhvgcf
 * @co: fcxd
 * Return: 0
 */
int check_path(char *co)
{
	if (co[0] == '.' && co[1] == '/')
		return (1);
	else if ((co[0] == '.' && co[1] == '.' && co[2] == '/') || co[0] == '/')
		return (1);
	else
		return (0);
}
