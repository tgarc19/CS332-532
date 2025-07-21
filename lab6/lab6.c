#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("No File Provided\n");
		return 1;
	}
	char* filename = argv[1];
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("File Not Found\n");
		return 1;
	}
	char line[256];
	while (fgets(line, sizeof(line), file)) {
		printf("%s", line);

	}
	fclose(file);
}