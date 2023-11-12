#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>


#define BUFFER_SIZE 1024

void type_prompt(void);
void clear_in(char *input, char *output);
char *get_command_loction(char *command);
int extract_arg(char *input, char *argv[20]);
void free_arg(char *argv[20]. int len);

//for with string
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

//for with string 2 
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

//for with string 3
void rev_string(char *s);

//to handle cd
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash); 
int cd_shell(data_shell *datash);

//handle copy sigint
void copy_sigint(int sigint);

/**
 * struct data - struct that contains all relevant data on runtime.
 *
 * @av: argument vector.
 * @input: command line written by the user.
 * @args: tokens of the command line .
 * @status: last status of the shell .
 * @counter: lines counter .
 * @_environ: environment variable .
 * @pid: process ID of the shell .
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

//for RM error
int get_error(data_shell *datash, int error);

// for RM error1
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);

// for RM error2
char *error_exit_shell(data_shell *datash);
char *error_env(data_shell *datash);
char *error_path_126(data_shell *datash);

//for RM_std
int get_lenght(int n);
char *RM_itoa(int n);
int _atoi(char *s);


//handle cmd
int cdir(char *path, int *i);
char *locates(char *cmd, char **_environ);
int executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exe(data_shell *datash);

//for environment 
int cmp_environment_name(const char *nenv, const char *name);
char *_get_environment(const char *name, char **_environ);
int _environment(data_shell *datash);
void set_environment(char *name, char *value, data_shell *datash);
char *copy_info(char *name, char *value);

//for com
int _setenvironment(data_shell *datash);
int _unsetenv(data_shell *datash);

//for memory
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);



#endif/*MAIN_H*/
