#include "olaf.h"

/**
 * cd_b - Changes the current working directory to the parameter passed to cd.
 * if no parameter is passed it will change directory to HOME.
 * @line: A string representing the input from the user.
 */
void cd_b(char *line)
{
	int index;
	int token_count;
	char **param_array;
	const char *delim = "\n\t ";

	token_count = 0;
	param_array = token_interface(line, delim, token_count);
	if (param_array[0] == NULL)
	{
		single_free(2, param_array, line);
		return;
	}
	if (param_array[1] == NULL)
	{
		index = find_path("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(param_array[1], "-") == 0)
		print_str(param_array[1], 0);

	else
		chdir(param_array[1]);
	double_free(param_array);
}

/**
 * env_b - Prints all the environmental variables in the current shell.
 * @line: A string representing the input from the user.
 */
void env_b(__attribute__((unused))char *line)
{
	int i;
	int j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * exit_b - Exits the shell with value 0. After freeing allocated resources.
 * If exit value provided, exit with value. If exit value is not integer,
 * exit with 2 and print error message.
 * @line: A string representing the input from the user.
 */
void exit_b(char *line)
{
	int token_count, value;
	char **argv;
	const char *delim = "\n\t ";

	argv = token_interface(line, delim, token_count);
	if (argv[1] == NULL)
		value = 0;
	else if (atoi(argv[1]))
		value = atoi(argv[1]);
	else
	{
		value = 2;
		print_str("logout", 0);
		printf("exit: %s: numeric argument required\n", argv[1]);
		free(line);
		exit(value);
	}
	free(line);
	print_str("logout", 0);
	exit(value);
}

/**
 * check_built_ins - Finds the right function needed for execution.
 * @str: The name of the function that is needed.
 * Return: Upon sucess a pointer to a void function. Otherwise NULL.
 */
void (*check_built_ins(char *str))(char *str)
{
	int i;

	builtin_t buildin[] = {
		{"exit", exit_b},
		{"env", env_b},
		{"cd", cd_b},
		{NULL, NULL}
	};

	for (i = 0; buildin[i].built != NULL; i++)
	{
		if (_strcmp(str, buildin[i].built) == 0)
		{
			return (buildin[i].f);
		}
	}
	return (NULL);
}

/**
 * built_in - Checks for builtin functions.
 * @command: An array of all the arguments passed to the shell.
 * @line: A string representing the input from the user.
 * Return: If function is found 0. Otherwise -1.
 */
int built_in(char **command, char *line)
{
	void (*build)(char *);

	build = check_built_ins(command[0]);
	if (build == NULL)
		return (-1);
	if (_strcmp("exit", command[0]) == 0)
		double_free(command);
	build(line);
	return (0);
}
