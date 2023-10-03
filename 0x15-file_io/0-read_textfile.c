#include "main.h"

/**
 * To Read & Print a Textfile - reads a text file and prints the letters
 * @filename: D fileName
 * @letters: Numbers of printed letters.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rdfil, wrfil;
	char *buff;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

	rdfil = read(fd, buff, letters);
	if (rdfil == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}

	wrfil = write(STDOUT_FILENO, buff, rdfil);
	if (wrfil == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}

	close(fd);

	return (rdfil);
}
