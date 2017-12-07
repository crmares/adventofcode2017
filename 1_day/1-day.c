//adventofcode2017 day 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int usage() {

	printf("Usage: <<./a.out>> <<input_file>>  <<'a' for the first part, 'b' for the second one>>\n");
	exit(0);
	return 0;
}

int main(int argc, char **argv) {

	if(argc != 3) {
		usage();
	}
	int step = 1, sum = 0;
	FILE *f = fopen(argv[1], "rb");
	if(f == NULL)
		usage();

	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *buffer = malloc(sizeof(char) * (fsize + 1));
	fread(buffer, fsize, 1, f);
	fclose(f);

	if(strcmp(argv[2], "a") == 0)
		step = 1;
	else if(strcmp(argv[2], "b") == 0)
		step = fsize / 2;
	else
		usage();

	for(int i = 0; i < fsize; i++) 
		if(buffer[i] == buffer[ (i + step)%fsize ])
			sum += buffer[i] - '0';

	printf("The solution to the captha is: %d\n", sum);


	return 0;
}

