#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read file prnt to STDOUT.
 * @filename: text file to read
 * @letters: numb of letters to read
 * Return: p- main numb of bytes read and printed
 *        0 when funt fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *cuf;
	ssize_t fd;
	ssize_t p;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	cuf = malloc(sizeof(char) * letters);
	t = read(fd, cuf, letters);
	p = write(STDOUT_FILENO, cuf, t);

	free(cuf);
	close(fd);
	return (p);
}
