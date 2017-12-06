//adventofcode2017 day 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {

	if(argc != 2) {
		printf("Usage: <<./a.out>> <<input_file>>\n");
		exit(0);
	}

	FILE *f = fopen(argv[1], "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *buffer = malloc(sizeof(char) * (fsize + 1));
	fread(buffer, fsize, 1, f);
	fclose(f);

	int sum = 0;

	for(int i = 0; i < fsize; i++)
		if(buffer[i] == buffer[ (i + 1)%fsize ])
			sum += buffer[i] - '0';

	printf("The solution to the captha is: %d\n", sum);


	return 0;
}

