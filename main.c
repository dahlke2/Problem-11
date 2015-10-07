#include "/problems.h"
#define GRID "/grid.txt"
int array[20][20];
int largest=0;
int c,i;

int gridin(){
	int i = 0;
	FILE *grid;
	grid = fopen(GRID, "r");
			while (EOF != fscanf(grid, "%2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i %2i", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4], &array[i][5], &array[i][6], &array[i][7], &array[i][8], &array[i][9], &array[i][10], &array[i][11], &array[i][12], &array[i][13], &array[i][14], &array[i][15], &array[i][16], &array[i][17], &array[i][18], &array[i][19]))
				i++;
	fclose(grid);
	for (int i = 0; i<19; i++){
		for (int c=0; c<=19;c++)
			printf("%2i ",array[i][c]);
		printf("\n");
	}
	return 1;
}

int left(){
	int temp;
	for (i = 0; i<19; i++)
		for (c = 3; c<19; c++){
			temp = array[i][c]*array[i][c-1]*array[i][c-2]*array[i][c-3];
			if (temp > largest)
				largest = temp;
		}
	return 1;
}

int right(){
	int temp;
	for (i = 0; i<19; i++)
		for (c = 0; c<=16; c++){
			temp = array[i][c]*array[i][c+1]*array[i][c+2]*array[i][c+3];
			if (temp > largest)
				largest = temp;
		}
	return 1;
}	

int up(){
	int temp;
	for (i = 3; i<19; i++)
		for (c = 0; c<19; c++){
			temp = array[i][c]*array[i-1][c]*array[i-2][c]*array[i-3][c];
			if (temp > largest)
				largest = temp;
		}
	return 1;	
}

int down(){
	int temp;
	for (i = 0; i<=16; i++)
		for (c = 0; c<19; c++){
			temp = array[i][c]*array[i+1][c]*array[i+2][c]*array[i+3][c];
			if (temp > largest)
				largest = temp;
		}
	return 1;	
}

int rightdiagonial(){
	int temp;
	for (i = 0; i<=16; i++)
		for (c = 0; c<=16; c++){
			temp = array[i][c]*array[i+1][c+1]*array[i+2][c+2]*array[i+3][c+3];
			if (temp > largest)
				largest = temp;
		}
	return 1;	
}

int leftdiagonal(){
	int temp;
	for (i = 19; i>=3; i--)
		for (c = 19; c>=3; c--){
			temp = array[i][c]*array[i-1][c-1]*array[i-2][c-2]*array[i-3][c-3];
			if (temp > largest)
				largest = temp;
		}
	return 1;	
}

int toprdiagonal(){
	int temp;
	for (i = 0; i<=16; i++)
		for (c = 19; c>=3; c--){
			temp = array[i][c]*array[i+1][c-1]*array[i+2][c-2]*array[i+3][c-3];
			if (temp > largest)
				largest = temp;
		}
	return 1;	
}

int bottomldiagonal(){
	int temp;
	for (i = 19; i>=3; i--)
		for (c = 0; c<=16; c++){
			temp = array[i][c]*array[i-1][c+1]*array[i-2][c+2]*array[i-3][c+3];
			if (temp > largest)
				largest = temp;
		}
	return 1;	
}

int main () {
	t0 = starttime();
	gridin();
	left();
	right();
	up();
	down();
	rightdiagonial();
	bottomldiagonal();
	toprdiagonal();
	printf("Largest: %i \n",largest);
	t1 = endtime();
	displaytime();
	return 0;
}
