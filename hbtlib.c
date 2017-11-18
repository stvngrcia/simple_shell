#include "olaf.h"

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if strings match. -1 Otherwise.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (str_len(s1) != str_len(s2))
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 * _strdup - create a copy of a string
 * @src: Contains the original string
 * Return: Gives back the copy of string
 */
char *_strdup(char *src)
{
	int i;
	int len;
	char *dest;

	len = str_len(src);
	dest = malloc(sizeof(char) * (len + 1));

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _realloc - reallocate a memory block
 * @ptr: pointer to old block
 * @old_size: old memory size
 * @new_size: new memory size
 * Return: pointer to new block, NULL when failed
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *orig = (char *)ptr;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
		return (NULL);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
	}
	else
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		for (i = 0; orig[i] != '\0' && i < new_size ; i++)
			p[i] = orig[i];
	}
	return (p);
}

/**
 * print_str - Prints a string character by character.
 * @str: String to be printed. If the string is NULL it will print (null)
 * @new_line: If integer is 0 a new line will be printed. Otherwise a new line
 * will not be printed.
 */
void print_str(char *str, int new_line)
{
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);
	if (new_line == 0)
		write(STDOUT_FILENO, "\n", 1);
}
