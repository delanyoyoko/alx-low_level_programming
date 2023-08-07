#include "main.h"

/**
 * append_text_to_file - Appends a text content to the end of a file.
 * @filename: A pointer to the file name.
 * @text_content: The string of content to add to the end of the file.
 *
 * Return: -1 for failure or filename is NULL or file does not exist
 *         or user lacks write permission. Else 1 for success.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_open;
	int write_byte;
	int content_len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (content_len = 0; text_content[content_len];)
			content_len++;
	}

	file_open = open(filename, O_WRONLY | O_APPEND);
	write_byte = write(file_open, text_content, content_len);

	if (file_open == -1 || write_byte == -1)
		return (-1);

	close(file_open);

	return (1);
}
