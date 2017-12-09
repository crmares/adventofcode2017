//adventofcode day 3 part two

#include <stdio.h>
#include <stdlib.h>

#define N 100

int usage()
{
	printf("Usage: <<./a.out>> <<input_file>>\n");
	exit(0);
	return 0;
}

int neighbours_sum(int m[N][N], int x, int y)
{
	int sum = 0;
	sum += m[x - 1][y] + m[x - 1][y - 1] + m[x - 1][y + 1];
	sum += m[x][y - 1] + m[x][y + 1];
	sum += m[x + 1][y - 1] + m[x + 1][y] + m[x + 1][y + 1];

	return sum;
}

int main(int argc, char *argv[])
{
	int matrix[N][N], input;	
	int i,j ,mid = 50, point = 2, nivel, x, y, val;
	FILE *f = fopen(argv[1], "rb");
	if(f == NULL)
		usage();

	fscanf(f, "%d", &input);

	memset(matrix, 0, sizeof(matrix[0][0]) * N * N);

	matrix[mid][mid] = 1;
	nivel = 1;

	x = mid;
	y = mid + 1;

	while(1) {
		nivel += 2;

		for(i = 0; i < nivel - 1; i++) {
			val = neighbours_sum(matrix, x - i, y);
			matrix[x - i][y] = val;
			if(val > input)
				goto final;
		}
		x -= nivel - 2;

		for(i = 0; i < nivel - 1; i++) {
			val = neighbours_sum(matrix, x, y - i - 1);
			matrix[x][y - i - 1] = val ;
				if(val > input)
				goto final;
		}
		y -= nivel - 1;

		for(i = 0; i < nivel - 1; i++) {
			val =  neighbours_sum(matrix, x + i + 1, y);
			matrix[x + 1 + i][y] = val;
				if(val > input)
				goto final;
		}
;		x += nivel - 1;

		for(i = 0; i < nivel - 1; i++) {
			val = neighbours_sum(matrix, x, y + i +1);
			matrix[x][y + i + 1] = val; 
				if(val > input)
				goto final;
		}
		y += nivel;
	}

	final:
		printf("The solution to the puzzle is: %d\n", val);

	return 0;
}