#include "main.h"

/**
 * create_file - Creates a text file using a filename.
 * @filename: Points to the name of the file to create.
 * @text_content: Pointer to strings to write to the file.
 *
 * Return: If the function fails -1 or 1 for success.
 */
int create_file(const char *filename, char *text_content)
{
	int file_desc;
	int write_byte;
	int content_len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (content_len = 0; text_content[content_len];)
			content_len++;
	}

	file_desc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_byte = write(file_desc, text_content, content_len);

	if (file_desc == -1 || write_byte == -1)
		return (-1);

	close(file_desc);

	return (1);
}
