//adventofcode day 6

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define N 30000

int usage() 
{
	printf("Usage: <<./a.out>> <<input_file>>  <<'a' for the first part, 'b' for the second one>>\n");
	exit(0);
	return 0;
}

char *save_state(int mem_banks[], int n)
{
	char *s = malloc(60 * sizeof(char)), buffer[30];
	for(int i = 0; i < n; i++) {
		sprintf(buffer, "%d", mem_banks[i]);
		strcat(s, buffer);
		strcat(s, ".");
	}
	return s;
}

int duplicate_state(char **state, int m)
{
	for(int i = 0; i < m - 1; i++) {
		if(strcmp(state[m - 1], state[i]) == 0)
			return i;
	}
	return 0;
}

int get_max_memory(int mem_banks[], int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++){
		if(mem_banks[i] > max)
			max = mem_banks[i];
	}
	return max;
}

int main(int argc, char *argv[])
{
	if(argc != 3) {
		usage();
	}

	FILE *f = fopen(argv[1], "rb");
	if(f == NULL)
		usage();

	int mem_banks[N];
	char **state = malloc(sizeof(char*) * N);
	for(int i = 0; i < N; i++)
		state[i] = malloc(sizeof(char) * N);
	int n = 0, m = 0, max, steps = 0;
	int start_poz, block_size, loops, duplicate_position;

	while (!feof(f))
		fscanf(f, "%d", &mem_banks[n++]);

	while(1) {
		strcpy(state[m++], save_state(mem_banks, n));
		duplicate_position = duplicate_state(state, m);
		if(duplicate_position != 0 && m > 1) {
			loops = m - duplicate_position - 1;
			break;
		}
		max = get_max_memory(mem_banks, n);
		for(int i = 0; i < n; i++) {
			if(mem_banks[i] == max) {
				start_poz = i;
				block_size = mem_banks[i];
				break;
			}
		}
		mem_banks[start_poz] = 0;
		while(block_size > 0) {
			start_poz = (start_poz + 1) % n;
			mem_banks[start_poz]++;
			block_size--;
		}
		steps++;
	}
	if(strcmp(argv[2], "a") == 0) {
		printf("The solution to the puzzle is: %d\n", steps);
	}
	else if(strcmp(argv[2], "b") == 0) {
		printf("The solution to the puzzle is: %d\n", loops);
	}
	else
		usage();

	fclose(f);

	return 0;
}