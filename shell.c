#include "olaf.h"

/**
 * main - Entry point of the program.
 * Return: Always 0.
 */
int main(void)
{
	char *line;
	size_t size;
	int command_counter;

	command_counter = 0;
	signal(SIGINT, SIG_IGN);
	do {
		command_counter++;
		line = NULL;
		size = 0;
		parse_line(line, size, command_counter);

	} while (1);

	return (0);
}
