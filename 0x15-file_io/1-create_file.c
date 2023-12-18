#include "main.h"

/**
 * create_file - Makes a file.
 * @filename: pointer to the name of the file to make.
 * @text_content: pointer to a string to copy to the file.
 *
 * Return: If the funct fails - -1.
 *         else - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int pd, x, lon = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lon = 0; text_content[lon];)
			lon++;
	}

	pd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(pd, text_content, lon);

	if (pd == -1 || x == -1)
		return (-1);

	close(pd);

	return (1);
}
