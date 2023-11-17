#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
extern char **environ;
#define BUFFER_SIZE 1024


void type_prompt(void);
void clear_in(char *input, char *output);
char *get_command_loction(char *co);
int extract_arg(char *input, char *argv[16]);
void free_arg(char *argv[16], int l);
void free_co(char *co, char *argem);
void env(void);
void execute_f(char *x, char *n, char *arge[16], int l, unsigned int w);
int execute(char *i);
int check_exit(char *i);
int le_exit(char *x);
int num(char *x);
void pt_exit(char *txt, char *ar[20]);
int check_path(char *co);
char *read_command(void);


#endif
