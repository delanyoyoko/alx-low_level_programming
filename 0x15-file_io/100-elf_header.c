#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void checks_elf_header(unsigned char *ei_identity);
void print_magic_number(unsigned char *ei_identity);
void print_class_type(unsigned char *ei_identity);
void print_data_type(unsigned char *ei_identity);
void print_version_number(unsigned char *ei_identity);
void print_abii(unsigned char *ei_identity);
void print_os_abii(unsigned char *ei_identity);
void print_type(unsigned int entry_type, unsigned char *ei_identity);
void print_entry_point(unsigned long int ei_entry, unsigned char *ei_identity);
void close_elf_header(int elf);

/**
 * checks_elf_header - Checks if a file is an ELF header file.
 * @ei_identity: A pointer to an array containing the ELF header magic numbers.
 *
 * Description: If the file is not an ELF header file - exit with code 98.
 */
void checks_elf_header(unsigned char *ei_identity)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (ei_identity[index] != 127 &&
		    ei_identity[index] != 'E' &&
		    ei_identity[index] != 'L' &&
		    ei_identity[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF header file\n");
			exit(98);
		}
	}
}

/**
 * print_magic_number - Prints the magic numbers of an ELF header file.
 * @ei_identity: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Separate magic numbers by spaces.
 */
void print_magic_number(unsigned char *ei_identity)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", ei_identity[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class_type - Prints the class of an ELF header file.
 * @ei_identity: A pointer to an array containing the ELF class.
 */
void print_class_type(unsigned char *ei_identity)
{
	printf(" Class: ");

	switch (ei_identity[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", ei_identity[EI_CLASS]);
	}
}

/**
 * print_data_type - Prints the data of an ELF header file.
 * @ei_identity: A pointer to an array containing the ELF class.
 */
void print_data_type(unsigned char *ei_identity)
{
	printf(" Data: ");

	switch (ei_identity[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", ei_identity[EI_CLASS]);
	}
}

/**
 *  * print_version_number - Prints an ELF header file version number.
 *   * @ei_identity: A pointer to an array containing the ELF version number.
 *    */
void print_version_number(unsigned char *ei_identity)
{
	 printf(" Version: %d",
			  ei_identity[EI_VERSION]);

	switch (ei_identity[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_os_abii - Prints the OS/ABI of an ELF header file.
 * @ei_identity: A pointer to an array containing the ELF version number.
 */
void print_os_abii(unsigned char *ei_identity)
{
	printf(" OS/ABI: ");

	switch (ei_identity[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", ei_identity[EI_OSABI]);
	}
}

/**
 * print_abii - Prints the ABI version of an ELF header file.
 * @ei_identity: A pointer to an array that contains the ELF ABI version number.
 */
void print_abii(unsigned char *ei_identity)
{
	printf(" ABI Version: %d\n",
		ei_identity[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header file.
 * @entry_type: The ELF type.
 * @ei_identity: A pointer to an array that contains the ELF class.
 */
void print_type(unsigned int entry_type, unsigned char *ei_identity)
{
	if (ei_identity[EI_DATA] == ELFDATA2MSB)
		entry_type >>= 8;

	printf(" Type: ");

	switch (entry_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", entry_type);
	}
}

/**
 * print_entry_point - Prints the entry point of an ELF header file.
 * @ei_entry: The address of the ELF entry point.
 * @ei_identity: A pointer to an array containing the ELF class.
 */
void print_entry_point(unsigned long int ei_entry, unsigned char *ei_identity)
{
	printf(" Entry point address: ");

	if (ei_identity[EI_DATA] == ELFDATA2MSB)
	{
		ei_entry = ((ei_entry << 8) & 0xFF00FF00) |
			  ((ei_entry >> 8) & 0xFF00FF);
		ei_entry = (ei_entry << 16) | (ei_entry >> 16);
	}

	if (ei_identity[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)ei_entry);

	else
		printf("%#lx\n", ei_entry);
}

/**
 * close_elf_header - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf_header(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Shows the info contained in the ELF header
 * at the start of an ELF file.
 * @argc: The total number of arguments supplied to the program.
 * @argv: An array of pointers to the total arguments.
 *
 * Return: 0 on success.
 *
 * Description: If failure or not an ELF File, exit with code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header_buff;
	int file_open;
	int read_value;

	file_open = open(argv[1], O_RDONLY);
	if (file_open == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header_buff = malloc(sizeof(Elf64_Ehdr));
	if (header_buff == NULL)
	{
		close_elf_header(file_open);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_value = read(file_open, header_buff, sizeof(Elf64_Ehdr));
	if (read_value == -1)
	{
		free(header_buff);
		close_elf_header(file_open);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	checks_elf_header(header_buff->ei_identity);
	printf("ELF Header:\n");
	print_magic_number(header_buff->ei_identity);
	print_class_type(header_buff->ei_identity);
	print_data_type(header_buff->ei_identity);
	print_version_number(header_buff->ei_identity);
	print_os_abii(header_buff->ei_identity);
	print_abii(header_buff->ei_identity);
	print_type(header_buff->entry_type, header_buff->ei_identity);
	print_entry_point(header_buff->ei_entry, header_buff->ei_identity);

	free(header_buff);
	close_elf_header(file_open);
	return (0);
}
