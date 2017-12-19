//adventofcode day 7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 300
#define M 1000

int usage() 
{
	printf("Usage: <<./a.out>> <<input_file>>  <<'a' for the first part, 'b' for the second one>>\n");
	exit(0);
	return 0;
}


char *getAllButFirstAndLast(char *input)
{
  int len = strlen(input); 
  if(len > 0)
    input++;//Go past the first char
  if(len > 1)
    input[len - 2] = '\0';//Replace the last char with a null termination
  return input;
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "rb");
    if(f == NULL)
        usage();
    
    int len, n = 0;
    char *line = malloc(sizeof(char) * N);
    char *token = NULL, *number = malloc(sizeof(char) * 10);
    char ***tree = (char***)malloc(sizeof(char**) * M);
    int cost[M];
    size_t count;

    
    while(getline(&line, &count, f) != -1) {
        len = strlen(line);
		if(line[len-1] == '\n')
    	    line[len-1] = 0;
    	    
        for(int i = 0; i < M; i++)
            tree[i] = (char**)malloc(sizeof(char*) * M);
    	    
    	token = strtok(line, " ");
    	tree[n][0] = malloc(sizeof(char) * M);
    	strcpy(tree[n][0], token);
		    while(token != NULL) {
		        if(token[0] == '(') {
		            strcpy(number, token);
		            number = getAllButFirstAndLast(number);
		            printf("%s\n", number);
		        }
		        
		    token = strtok(NULL, " ");
		    }
    }
        
    fclose(f);        
    
    return 0;
}