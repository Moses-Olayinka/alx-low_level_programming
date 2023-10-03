#include "main.h"

/**
 * To Read & Print a textfile - reads a text file and prints the letters
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

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	rdfil = read(fd, buff, letters);
	wrfil = write(STDOUT_FILENO, buff, rdfil);

	close(fd);

	free(buff);

	return (wrfil);
}
