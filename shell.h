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
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


void type_prompt(void);
void clear_in(char *input, char *output);
char *get_command_loction(char *co);
int extract_arg(char *input, char *argv[16]);
void free_arg(char *argv[16], int l);
void free_co(char *co, char *argem);
void env(void);
void execute_f(char *x, char *n ,char *arge[16], int l, unsigned int w);
int execute(char *i);
int check_exit(char *i);
int le_exit(char *x);
int num(char *x);
void pt_exit(char *ar[20], char *txt);

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

void rev_string(char *s);
/**
* struct data - struct that contains all relevant data on runtime
* @av: argument vector
* @input: command line written by the user
* @args: tokens of the command line
* @status: last status of the shell
* @counter: lines counter
* @_environ: environment variable
* @pid: process ID of the shell
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

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int check_syntax_error(data_shell *datash, char *input);

char *without_comment(char *in);
void shell_loop(data_shell *datash);
char *read_line(int *i_eof);

char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);

void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash); 
int cd_shell(data_shell *datash);

void copy_sigint(int sigint);

int get_error(data_shell *datash, int error);

int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int check_syntax_error(data_shell *datash, char *input);

char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);

char *error_exit_shell(data_shell *datash);
char *error_env(data_shell *datash);
char *error_path_126(data_shell *datash);

int get_lenght(int n);
char *RM_itoa(int n);
int _atoi(char *s);

int cdir(char *path, int *i);
char *locates(char *cmd, char **_environ);
int executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exe(data_shell *datash);

int cmp_environment_name(const char *nenv, const char *name);
char *_get_env(const char *name, char **_environ);
int _env(data_shell *datash);
void set_env(char *name, char *value, data_shell *datash);
char *copy_info(char *name, char *value);

int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

void set_data(data_shell *datash , char **av);
void free_data(data_shell *datash);

int (*get_builtin(char *cmd))(data_shell *);
int exe_line(data_shell *datash);

#endif/*SHELL_H*/
