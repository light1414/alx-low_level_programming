#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buf(char *file);
void close_file(int fd);

/**
 * create_buf - gives 1024 bytes for a buffer.
 * @file: Name of the file buf is keeping chars for.
 *
 * Return: Pointer to the new-assigned buffer.
 */
char *create_buf(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
 * close_file - Ends file descriptors.
 * @fd: File descriptor to close.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - duplicates the cont of a file to another file.
 * @argc: The num of argu given to the program.
 * @argv: An array of pointers to the argu.
 *
 * Return: 0 if success.
 *
 * Description: If the argu count is incorrect - exit code 97.
 * If file_from does not exist or can't be read - exit code 98.
 * If file_to can't be written to - exit code 99.
 * If file_to or file_from can't be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, tt, x, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_tt\n");
		exit(97);
	}

	buffer = create_buf(argv[2]);
	from = open(argv[1], O_RDONLY);
	x = read(from, buffer, 1024);
	tt = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || x == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(tt, buffer, x);
		if (tt == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		x = read(from, buffer, 1024);
		tt = open(argv[2], O_WRONLY | O_APPEND);

	} while (x > 0);

	free(buffer);
	close_file(from);
	close_file(tt);

	return (0);
}
