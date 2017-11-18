#ifndef _OLAF_
#define _OLAF_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <signal.h>
#define PROMPT "Olaf $ "


/**
 * struct builtin_d - Defines the builtins functions.
 * @built: The name of the build in command.
 * @f: A pointer to the right builtin function.
 */
typedef struct builtin_d
{
	char *built;
	void (*f)(char *);
} builtin_t;

extern char **environ;

char **token_interface(char *line, const char *delim, int token_count);
int count_token(char *line, const char *delim);
char **tokenize(int token_count, char *line, const char *delim);
void create_child(char **param_array, char *line);
void parse_line(char *line, size_t size);
char *path_finder(char *command);
int str_len(char *str);
int find_path(char *str);
char **tokenize_path(int index, char *str);
char *search_directories(char **path_tokens, char *command);
char *build_path(char *directory, char *command);
void double_free(char **to_be_freed);
void single_free(int n, ...);

/*Builtin functions*/
int built_in(char **command, char *line);
void (*check_built_ins(char *str))(char *str);
void exit_b(char *str);
void env_b(char *str);
void cd_b(char *directory);
void unsetenv_b(char *str);
void setenv_b(char *str);
int check_env(char *env);
void modify_env(char *env, char *value);
void add_env(char *env, char *value);
void remove_env(char *env);

/*Holberton library functions*/
int _strcmp(char *s1, char *s2);
char *_strdup(char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print_str(char *str, int new_line);

#endif
