#include "main.h"

/**
 * create_file - creates file
 * @filename: creates filename.
 * @text_content: content written in the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int newletters;
	int rwrt;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (newletters = 0; text_content[newletters]; newletters++)
		;

	rwrt = write(fd, text_content, newletters);

	if (rwrt == -1)
		return (-1);

	close(fd);

	return (1);
}
