/* Waste of space */
/* A c program to waste space on your disk */

// Usage: ./waste [amount to waste]
// Optional argument: --unit [mb|gb] (default: mb)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define DEBUG // MUST be defined before including main.h
#include "../inc/main.h"

#define MB_SIZE (1024 * 1024)
#define GB_SIZE (1024 * MB_SIZE)
#define UNIT_MB 1
#define UNIT_GB 2

void print_usage()
{
	printf("Usage: ./waste [amount to waste] [--unit mb|gb]\n");
	printf("Default unit is MB.\n");
}
void waste_space(size_t size, int unit)
{
	size_t bytes_to_waste = size;
	if (unit == UNIT_GB) {
		bytes_to_waste *= GB_SIZE;
	} else {
		bytes_to_waste *= MB_SIZE;
	}
	// Create file in the temp folder so it doesnt end up actually clogging up the disk
	// and is deleted when the system is restarted.
	char *temp_dir;
	temp_dir = getenv("TMPDIR");
	debug_print(
		"attempting to find temp dir from environment variable TMPDIR: %s\n",
		temp_dir ? temp_dir : "not set");
	if (temp_dir == NULL) {
		temp_dir = getenv("TMP");
		debug_print(
			"attempting to find temp dir from environment variable TMP: %s\n",
			temp_dir ? temp_dir : "not set");
	}
	if (temp_dir == NULL) {
		temp_dir = getenv("TEMP");
		debug_print(
			"attempting to find temp dir from environment variable TEMP: %s\n",
			temp_dir ? temp_dir : "not set");
	}
	if (temp_dir == NULL) {
		temp_dir =
			"/tmp"; // Fallback to /tmp if no environment variable is set
		debug_print("no temp dir found, using fallback: %s\n",
			    temp_dir);
	}

	char file_path[MAX_PATH_LENGTH] = { 0 }; // defined as 4096 in main.h
	snprintf(file_path, sizeof(file_path), "%s/waste_space.bin", temp_dir);
	debug_print("Attempting to waste space in file: %s\n", file_path);

	FILE *file = fopen(file_path, "wb");
	if (file == NULL) {
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	size_t chunk_size = MB_SIZE;
	char *buffer = malloc(chunk_size);
	if (buffer == NULL) {
		perror("Failed to allocate memory");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	memset(buffer, 1, chunk_size);
	while (bytes_to_waste > 0) {
		size_t bytes_to_write = (bytes_to_waste < chunk_size) ?
						bytes_to_waste :
						chunk_size;
		size_t written = fwrite(buffer, 1, bytes_to_write, file);
		if (written < bytes_to_write) {
			perror("Failed to write to file");
			free(buffer);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		bytes_to_waste -= written;
	}
}
int main(int argc, char *argv[])
{
	debug_print(
		"Looks like we were compiled in debug mode. To remove debug messages, recompile without the DEBUG macro defined.\n");
	debug_print("wasteofspace version: %s\n", VERSION);
	debug_print("wasteofspace started with %d arguments\n", argc);

	if (argc < 2 || argc > 4) {
		print_usage();
		return 1;
	}
	char *endptr;
	size_t size = strtoul(argv[1], &endptr, 10);
	if (*endptr != '\0' || size == 0) {
		print_usage();
		return 1;
	}

	int unit = UNIT_MB;
	if (argc == 4 && strcmp(argv[2], "--unit") == 0) {
		if (strcmp(argv[3], "mb") == 0) {
			unit = UNIT_MB;
		} else if (strcmp(argv[3], "gb") == 0) {
			unit = UNIT_GB;
		} else {
			print_usage();
			return 1;
		}
	} else if (argc == 3) {
		print_usage();
		return 1;
	}
	printf("Welcome to wasteofspace version: %s!\n", VERSION);
	printf("Let's waste some space!\n");
	waste_space(size, unit);
	printf("Successfully wasted %zu %s of space.\n", size,
	       (unit == UNIT_MB) ? "MB" : "GB");

	return 0;
}
