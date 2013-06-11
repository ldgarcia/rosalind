#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if(argc < 2) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	struct stat fileinfo;
	FILE *file = fopen("input.txt", "r");
	if(!file) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fstat(fileno(file), &fileinfo);
	char *buffer = malloc(fileinfo.st_size);
	if(!buffer)	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if(fread(buffer, 1, fileinfo.st_size, file) != fileinfo.st_size) {
		fprintf(stderr, "fread\n");
		exit(EXIT_FAILURE);
	}
	fclose(file);
	int i;
	for(i = fileinfo.st_size; i >= 0; --i) {
		if(buffer[i] == 'T') {
			putchar('A');
		}
		else if(buffer[i] == 'A') {
			putchar('T');
		}
		else if(buffer[i] == 'G') {
			putchar('C');
		}
		else if(buffer[i] == 'C') {
			putchar('G');
		}
	}
	free(buffer);
	return 0;
}
