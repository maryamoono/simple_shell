#include "main.h"

/**
 * copy_sigint - Handle the crtl + c call in prompt .
 * 
 * @sigint: Signal handler.
 *
 *
 */
void copy_sigint(int sigint)
{
	(void)sigint;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
