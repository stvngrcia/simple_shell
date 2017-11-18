#include "olaf.h"

/**
 * setenv_b - Initialize a new environ variable, or modify an existing one
 * @line: A string representing the input from the user.
 */
void setenv_b(char *line)
{
	int check, token_count = 0;
	char **path_tokens;
	const char *delim = "\n\t ";
	char *env, *value;

	path_tokens = token_interface(line, delim, token_count);
	env = path_tokens[1], value = path_tokens[2];

	check = check_env(env);
	if (check == 1)
		modify_env(env, value);
	if (check == 0)
		add_env(env, value);

	double_free(path_tokens);
}

/**
 * check_env - Check if an environ variable exists
 * @env: Variable to be checked
 * Return: 1 - found environ variable, 0 - not found
 */
int check_env(char *env)
{
	int i, j;

	i = 0;
	while (environ[i])
	{
		j = 0;
		while (environ[i][j] == env[j])
		{
			j++;
			if (environ[i][j] == '=' && !env[j])
				return (1);
		}
		i++;
	}
	return (0);
}

/**
 * modify_env - Modify environ variable
 * @env: environ variable
 * @value: environ variable value
 */
void modify_env(char *env, char *value)
{
	int index, i = 0, j = 0;

	index = find_path(env);

	for (i = 0; env[i]; i++)
		environ[index][i] = env[i];

	environ[index][i] = '=', i++;

	for (j = 0; value[j]; i++, j++)
		environ[index][i] = value[j];
	environ[index][i] = '\0';
}

/**
 * add_env - Add new environ variable
 * @env: environ variable
 * @value: environ variable value
 */
void add_env(char *env, char *value)
{
	int i = 0, j = 0, t = 0, count = 0, size;
	char **new;

	for (i = 0; environ[i]; i++)
		count++;

	new = _realloc(environ, sizeof(char *) * count, sizeof(char *) * (count + 1));
	if (new == NULL)
		return;
	for (i = 0; i < count; i++)
		new[i] = _strdup(environ[i]);

	size = strlen(env) + strlen(value) + 2;
	new[i] = malloc(sizeof(char) * size);
	if (new[i] == NULL)
		return;

	for (j = 0; env[j]; j++)
		new[i][j] = env[j];

	new[i][j] = '=', j++;

	for (t = 0; value[t]; j++, t++)
		new[i][j] = value[t];
	new[i][j] = '\0';

	environ = new;
}
