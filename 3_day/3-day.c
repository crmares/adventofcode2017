//adventofcode day 3

#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a) < (b) ? a : b)

int usage()
{

	printf("Usage: <<./a.out>> <<input_file>>  <<'a' for the first part, 'b' for the second one>>\n");
	exit(0);
	return 0;
}

int min4(int a, int b, int c, int d)
{
	if(MIN(a, b) < MIN(c, d))
		return MIN(a, b);
	else
		return MIN(c, d);
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		usage();
	}
	int x, s[1000], i = 0, additional, step, distance = 0;
	int mid1, mid2, mid3, mid4;
	FILE *f = fopen(argv[1], "rb");
	if(f == NULL)
		usage();

	fscanf(f, "%d", &x);

	s[0] = 1;

	do {
		i++;
		s[i] = (8 * i) + s[i - 1];

	}while(s[i] < x);

	if(i == 0) {
		distance = 0;
	}
	else if(i == 1) {
		distance += i + x % 2;
	}
	else {
		step = 2 * i;
		mid1 = s[i] - i;
		mid2 = mid1 - step;
		mid3 = mid2 - step;
		mid4 = mid3 - step;
		mid1 = abs(mid1 - x);
		mid2 = abs(mid2 - x);
		mid3 = abs(mid3 - x);
		mid4 = abs(mid4 - x);
		additional = min4(mid1, mid2, mid3, mid4);
		distance = i + additional;
	} 

	printf("The solution to the puzzle is: %d\n", distance);

	fclose(f);

	return 0;
}