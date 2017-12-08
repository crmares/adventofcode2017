//adventofcode day 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

#define N 100

int usage() {

	printf("Usage: <<./a.out>> <<input_file>>  <<'a' for the first part, 'b' for the second one>>\n");
	exit(0);
	return 0;
}


//https://stackoverflow.com/questions/17770202/remove-extra-whitespace-from-a-string-in-c
char *removeSpaces(char *str)
{
    char *inp = str, *outp = str;
    int prevSpace = 0;

    while (*inp) {
        if (isspace(*inp)) {
            if (!prevSpace) {
                *outp++ = ' ';
                prevSpace = 1;
            }
        } else {
            *outp++ = *inp;
            prevSpace = 0;
        }
        ++inp;
    }
    *outp = '\0';
    return str;
}

int main(int argc, char *argv[])
{

	if(argc != 3) {
		usage();
	}

	size_t count;
	int n = 0, m = 0, sum = 0, min, max;
	int matrix[N][N];
	char *line = malloc(sizeof(char) * N);
	char *token = NULL;
	FILE *f = fopen(argv[1], "r");
	if(f == NULL)
		usage();


  while (getline(&line, &count, f) != -1) {
  	line = removeSpaces(line);

     token = strtok(line, " ");
     m = 0;
     while(token != NULL) {
       matrix[n][m] = atoi(token);
       token=strtok(NULL, " ");
       m++;
     }
     n++;
  }
  	//case a: first part of the problem
  	if(strcmp(argv[2], "a") == 0) {
		for(int i = 0; i < n; i++) {
			max = INT_MIN;
			min = INT_MAX;
			for(int j = 0; j < m; j++) {
				if(matrix[i][j] > max)
					max = matrix[i][j];
				if(matrix[i][j] < min)
					min = matrix[i][j];
			}
			sum += max - min;
		}
  	}
  	//case b: second part of the problem
	else if(strcmp(argv[2], "b") == 0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				for(int k = 0; k < m; k++) {
					if(j != k) {
						if(matrix[i][j] % matrix[i][k] == 0) {
							sum += matrix[i][j] / matrix[i][k];
						}
					}
				}

			}
		}
	}
	else
		usage();
	

	fclose(f);

	printf("The solution to the puzzle is: %d\n", sum);


	return 0;
}