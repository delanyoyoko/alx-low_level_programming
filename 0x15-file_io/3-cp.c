#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer_bytes(char *file);
void close_file(int file_desc);

/**
 * create_buffer_bytes - Sets aside 1024 bytes for a buffer.
 * @file: The file name for storing chars in buffer.
 *
 * Return: A pointer to the "newly" allocated buffer. Or exit
 *         if buffer is null.
 */
char *create_buffer_bytes(char *file)
{
	char *buffer_bytes;

	buffer_bytes = malloc(sizeof(char) * 1024);

	if (buffer_bytes == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer_bytes);
}

/**
 * close_file - Closes file descriptors.
 * @file_desc: The file descriptor to close.
 */
void close_file(int file_desc)
{
	int c_file;

	c_file = close(file_desc);

	if (c_file == -1)
	{
		dprintf(STDERR_FILENO, 
			"Error: Can't close fd %d\n", file_desc);
		exit(100);
	}
}

/**
 * main - Copies the text contents of a file to another file.
 * @argc: The number of arguments supplied to the program in total.
 * @argv: An array of pointers to the arguments supplied to the program.
 *
 * Return: 0 on success.
 *
 * Description: If an argument count is not correct - exit with code 97.
 * If file_from does not exist or cannot be read - exit with code 98.
 * If file_to cannot be created or written to - exit with code 99.
 * If file_to or file_from cannot be closed - exit with code 100.
 */
int main(int argc, char *argv[])
{
	int from_file;
	int to_file;
	int read_value;
	int write_value;
	char *buffer_bytes;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer_bytes = create_buffer_bytes(argv[2]);
	from_file = open(argv[1], O_RDONLY);
	read_value = read(from_file, buffer_bytes, 1024);
	to_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from_file == -1 || read_value == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer_bytes);
			exit(98);
		}

		write_value = write(to_file, buffer_bytes, read_value);
		if (to_file == -1 || write_value == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer_bytes);
			exit(99);
		}

		read_value = read(from_file, buffer_bytes, 1024);
		to_file = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_value > 0);

	free(buffer_bytes);
	close_file(from_file);
	close_file(to_file);

	return (0);
}


