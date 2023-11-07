#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


#define BUFFER_SIZE 1024

void type_prompt(void);
void clear_in(char *input, char *output);
char *get_command_loction(char *command);


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






#endif/*MAIN_H*/
