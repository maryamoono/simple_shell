#include "shell.h"

/**
 * copy_sigint -this function to
 * Handle the crtl + c call in prompt .
 * 
 * @sigint: Signal handler.
 */
void copy_sigint(int sigint)
{
	(void)sigint;
	write(STDOUT_FILENO, "\n$ ", 5);
}
