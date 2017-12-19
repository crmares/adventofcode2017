//adventofcode day 7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 300

int usage() 
{
	printf("Usage: <<./a.out>> <<input_file>>  <<'a' for the first part, 'b' for the second one>>\n");
	exit(0);
	return 0;
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "rb");
    if(f == NULL)
        usage();
    
    char *line = malloc(sizeof(char) * N);
    size_t count;
    
    while(getline(&line, &count, f) != -1) {
        printf("%s\n", )
    }
        
    fclose(f);        
    
    return 0;
}