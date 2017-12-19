//adventofcode day 7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 1300
#define WORD_SIZE 20
#define COST_SIZE 5

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
    
    int len, n = 0, m;
    char *line = malloc(sizeof(char) * N);
    char *token = NULL, *number = malloc(sizeof(char) * COST_SIZE);
    char ***tree = (char***)malloc(sizeof(char**) * M);
    int cost[M], hasChild[M];
    size_t count;

    memset(hasChild, 0, sizeof(hasChild));
    
    for(int i = 0; i < M; i++)
            tree[i] = (char**)malloc(sizeof(char*) * 20);
    
    while(getline(&line, &count, f) != -1) {
        m = 0;
        len = strlen(line);
		if(line[len-1] == '\n')
    	    line[len-1] = 0;
    	    
    	token = strtok(line, " ");
    	tree[n][0] = malloc(sizeof(char) * WORD_SIZE);
    	strcpy(tree[n][m], token);
		    while(token != NULL) {
		        if(token[0] == '(') {
		            strcpy(number, token);
		            number = getAllButFirstAndLast(number);
		            cost[n] = atoi(number);
		        }
		        else if(token[0] == '-') {
		            //do nothing
		        }
		        else {
		            m++;
		            tree[n][m] = malloc(sizeof(char) * WORD_SIZE);
		            strcpy(tree[n][m], token);
		            if(tree[n][m][strlen(tree[n][m]) - 1] == ',')
		                tree[n][m][strlen(tree[n][m]) - 1] = '\0';
		        }
		        
		    token = strtok(NULL, " ");
		    }
		 printf("%s  %d  ", tree[n][0], cost[n]);
// 		 for(int i = 1; i < m; i ++)
// 		    printf("%s  ", tree[n][i]);
// 		 printf("\n");
// 		 printf("%d\n", strlen(tree[n]));
//     tree[n][m + 1] = malloc(sizeof(char) * WORD_SIZE);
    n++;
    }
    // printf("%d\n", n);
    for(int i = 0; i < n; i++) {
        printf("%s\n", tree[i][0]);
    }

    // for(int i = 0; i < n; i++) {
    //     m = 1;
    //     // if(tree[i][m] == NULL)
    //     //     printf("dadasdAdada\n");
    //     while(tree[i][m] != NULL) {
    //         for(int j = 0; j < n; j++)
    //             if(strcmp(tree[j][0], tree[i][m]) == 0)
    //                 hasChild[j] = 1;
    //     m++;
    //     }
    // }

    // for(int i = 0; i < n; i++) 
    //     if(hasChild[i] == 0)
    //         printf("%s\n", tree[i][0]);
        
    fclose(f);        
    
    return 0;
}