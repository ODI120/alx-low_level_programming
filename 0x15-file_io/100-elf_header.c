#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * elf_header - displays information about the ELF header of a file
 * @filename: the name of the file to inspect
 *
 * Return: 0 on success, 98 on failure
 */

void print_error(char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

void print_header(Elf32_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n",
		header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
		header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
		header->e_ident[EI_CLASS] == ELFCLASSNONE ? "Invalid class" :
		"Unknown class");
	printf("Data:%s\n",
		header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
		header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
		header->e_ident[EI_DATA] == ELFDATANONE ? "Invalid data encoding" :
		"Unknown data encoding");
	printf("Version:%d%s\n",
		header->e_ident[EI_VERSION],
		header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf("OS/ABI:%s\n",
		header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
		header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
		header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
		header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
		header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
		header->e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
		header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
		header->e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
		header->e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM" :
		header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone App" :
		header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
		"Unknown OS/ABI");
	printf("ABI Version:%d\n",
		header->e_ident[EI_ABIVERSION]);
		printf("Type:%s\n",
		header->e_type == ET_NONE ? "NONE (No file type)" :
		header->e_type == ET_REL ? "REL (Relocatable file)" :
		header->e_type == ET_EXEC ? "EXEC (Executable file)" :
		header->e_type == ET_DYN ? "DYN (Shared object file)" :
		header->e_type == ET_CORE ? "CORE (Core file)" :
		"Unknown type");
	printf("Entry point address:0x%x\n",
		header->e_entry);
}

int main(int argc, char **argv)
{
	int fd;
	Elf32_Ehdr header;

	if (argc != 2)
		fd = open(argv[1], O_RDONLY);
		print_error("Usage: elf_header elf_filename");
	if (fd < 0)
		print_error("Cannot open file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Cannot read header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	print_header(&header);

	close(fd);
	return (0);
}
