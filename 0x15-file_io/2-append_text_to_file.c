#include "main.h"

/**
 * append_text_to_file - appends text at the end of the file
 * @filename: created filename.
 * @text_content: content added
 *
 * Return: 1 if the file exists. -1 if it  does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int newletters;
	int rwrt;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (newletters = 0; text_content[newletters]; newletters++)
			;

		rwrt = write(fd, text_content, newletters);

		if (rwrt == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
