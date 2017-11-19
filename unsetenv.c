#include "olaf.h"

/**
 * unsetenv_b - Remove an environ variable
 * @line: A string representing the input from the user.
 */
void unsetenv_b(char *line)
{
	int check, token_count = 0;
	char **path_tokens;
	const char *delim = "\n\t ";
	char *env;

	path_tokens = token_interface(line, delim, token_count);
	env = path_tokens[1];

	check = check_env(env);
	if (check == 0)
	{
		printf("unsetenv: %s: variable not found\n", env);
		return;
	}
	if (check == 1)
		remove_env(env);

	double_free(path_tokens);
}

/**
 * remove_env - Remove environ variable
 * @env: environ variable
 */
void remove_env(char *env)
{
	int i = 0, j = 0, size = 0, index;
	char **str;

	for (i = 0; environ[i]; i++)
		size++;
	str = malloc(sizeof(char *) * size);
	if (str == NULL)
		return;

	index = find_path(env);
	for (i = 0; environ[i]; i++, j++)
	{
		if (i == index)
			i++;
		str[j] = _strdup(environ[i]);
	}
	str[j] = NULL;
	environ = str;
}
