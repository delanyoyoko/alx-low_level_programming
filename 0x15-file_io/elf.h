#ifndef ELF_H
#define ELF_H

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

#endif
