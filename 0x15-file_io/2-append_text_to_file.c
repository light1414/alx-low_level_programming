#include "main.h"

/**
 * append_text_to_file - adds txt at the end of a file.
 * @filename: pointer to the name of file.
 * @text_content: The string to attach to the end of file.
 *
 * Return: If the funct fails or filename is NULL - -1.
 *         If the file does not exist user has no write permissions - -1.
 *         else - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int p, x, lent = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lent = 0; text_content[lent];)
			lent++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	x = write(p, text_content, lent);

	if (p == -1 || x == -1)
		return (-1);

	close(p);

	return (1);
}
