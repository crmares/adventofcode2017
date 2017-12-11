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
	int isDuplicate, sum = 0;

	while(getline(&line, &count, f) != -1) {
		vector = malloc(sizeof(char*) * N);
		n = 0;

		token = strtok(line, " ");
		while(token != NULL) {
			vector[n] = malloc(sizeof(char) * strlen(token));
			strcpy(vector[n], token);
			char *pch = strstr(vector[n], "\n");
			if(pch != NULL) {
  				strncpy(pch, "", 1);
  				strcpy(vector[n], pch);
			}
			n++;
			token = strtok(NULL, " ");
		}
		isDuplicate = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if((strcmp(vector[i], vector[j]) == 0) && i != j) {
					//printf("%s   %s   %d %d\n", vector[i], vector[j], i, j);
					isDuplicate = 1;
				}
			}
		}
		if(isDuplicate == 0) {
			sum++;
			printf("<<");
			for(int i = 0; i < n; i++) {
				printf("%s ", vector[i]);
			}
			printf(">>");
			printf("\n");
		}

	}

	printf("The solution to the puzzle is: %d\n", sum);

	fclose(f);

	return 0;
}