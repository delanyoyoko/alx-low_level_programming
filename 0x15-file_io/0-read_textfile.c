#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file then prints to
 * standard output in POSIX.
 * @filename: The text file being read to standard output.
 * @letters: The number of bytes to read & write.
 * Return: w- the actual number of bytes read & printed
 *        or 0 when write fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff_mode;
	ssize_t file_desc;
	ssize_t text_mode;
	ssize_t write_mode;
	
	file_desc = open(filename, O_RDONLY);
	if (file_desc == -1)
		return (0);
	buff_mode = malloc(sizeof(char) * letters);
	text_mode = read(file_desc, buff_mode, letters);
	write_mode = write(STDOUT_FILENO, buff_mode, text_mode);

	free(buff_mode);
	close(file_desc);
	return (write_mode);
}
