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
	ssize_t nr_d, nw_r;
	char *buffa;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffa = malloc(sizeof(char) * (letters));
	if (!buffa)
		return (0);

	nr_d = read(fd, buffa, letters);
	nw_r = write(STDOUT_FILENO, buffa, nr_d);

	close(fd);

	free(buffa);

	return (nw_r);
}
