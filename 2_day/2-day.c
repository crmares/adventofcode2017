//adventofcode day 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N 100

int usage() {

	printf("Usage: <<./a.out>> <<input_file>>  <<'a' for the first part, 'b' for the second one>>\n");
	exit(0);
	return 0;
}


int main(int argc, char *argv[])
{

	size_t count;
	int n = 0, m = 0;
	int matrix[N][N];
	char *line = malloc(sizeof(char) * N);
	char *token = NULL;
	FILE *f = fopen(argv[1], "r");
	if(f == NULL)
		usage();

	while(getline(&line, &count, f) != -1) {
		printf("%d \n", count);
		for(; count > 0; count--, m++)
			sscanf(line, "%d", &matrix[n][m]);
		n++;
	}



  // while (getline(&line, &count, f) != -1)
  // {
  // 	printf("%s\n", line);

  //    token = strtok(line, " ");
  //    m = 0;
  //    while(token != NULL)
  //    {
  //      matrix[n][m] = atoi(token);
  //      printf("%d\n", atoi(token));
  //      token=strtok(NULL, " ");
  //      m++;
  //    }
  //    n++;
  // }

	printf("%d %d\n", n, m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");	
	}

	fclose(f);


	return 0;
}