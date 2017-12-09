//adventofcode day 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int usage()
{
	printf("Usage: <<./a.out>> <<input_file>>\n");
	exit(0);
	return 0;
}

int main(int argc, char *argv[])
{
	FILE *f = fopen(argv[1], "rb");
	if(f == NULL)
		usage();
	int n;
	char *line = malloc(sizeof(char) * N); 
	char *token = NULL;
	char **vector;
	size_t count;

	while(getline(&line, &count, f) != -1) {
		vector = malloc(sizeof(char*) * N);
		n = 0;

		token = strtok(line, " ");
		while(token != NULL) {
			vector[n] = malloc(sizeof(char) * strlen(token));
			strcpy(vector[n], token);
			// printf("%s.", vector[n]);
			n++;
			token = strtok(NULL, " ");
		}

		for(int i = 0; i < n; i++)
			printf("<<%s>> ", vector[i]);
		printf("\n");
	}

	return 0;
}