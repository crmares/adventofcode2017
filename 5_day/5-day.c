//adventofcode day 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2000

int usage() 
{
	printf("Usage: <<./a.out>> <<input_file>>  <<'a' for the first part, 'b' for the second one>>\n");
	exit(0);
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc != 3) {
		usage();
	}

	FILE *f = fopen(argv[1], "rb");
	if(f == NULL)
		usage();
	int instructions[N];
	int n = 0, steps, current_step, prev_poz, inc, poz;

	while (!feof(f))
		fscanf(f, "%d", &instructions[n++]);

	steps = 0;
	current_step = 0;
	poz = 0;
	prev_poz = poz;
	while(1) {
		inc = 1;
		prev_poz = poz;
		current_step = instructions[poz];
		poz = poz + current_step;

		if(strcmp(argv[2], "a") == 0) {
			inc = 1;
		}
		else if(strcmp(argv[2], "b") == 0) {
			if(current_step >= 3)
				inc = -1;
			else
				inc = 1;
		}
		else
			usage();

		instructions[prev_poz] += inc;
		steps++;
		if(poz >= n || poz < 0)
			break;
	}
	printf("The solution to the puzzle is: %d\n", steps);

	fclose(f);

	return 0;
}