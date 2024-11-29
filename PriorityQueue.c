//wrong code

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

#define maxn 100069
#define inf 0x3f3f3f3f

int *PriorityQueue, n=1;

int ran(int x, int y) {
	return x + rand()%(y-x+1);
}

void Push(int *PrQueue, int x) {
	int i=n;
	PrQueue[i]=x;
	while (PrQueue[i] < PrQueue[i/2]) {
		//swap(PrQueue[i], PrQueue[i/2]);
		int temp=PrQueue[i/2];
		PrQueue[i/2]=PrQueue[i];
		PrQueue[i]=temp;

		i/=2;
	}
	n++;
}

void Pop(int *PrQueue) {
	PrQueue[1]=inf;
	int i=1;
	while (i<n) {
		int j=i*2;
		if (PrQueue[j+1] < PrQueue[j])
			j++;
		
		printf("%d %d    ", i, j);
		
		//swap(PrQueue[i], PrQueue[j]);
        int temp=PrQueue[j];
		PrQueue[j]=PrQueue[i];
		PrQueue[i]=temp;

		i=j;
	}
	n--;
}

int Front(int *PrQueue) {
	return PrQueue[1];
}

bool Empty(int *PrQueue) {
	return (n==1);
}

int main() {
	srand(time(NULL));
	setvbuf(stdout, NULL, _IONBF, 0);

	PriorityQueue = (int* ) malloc (maxn * sizeof(PriorityQueue));
	PriorityQueue[0]=-inf;
	/*
	for (int i=0; i<10; i++) {
	    int x=ran(-100,100);
	    printf("%d ", x);
	    Push(PriorityQueue, x);
	}
	*/
	PriorityQueue[1]=10;
	PriorityQueue[2]=25;
	PriorityQueue[3]=61;
	n=4;
	printf("\n");

	while (!Empty(PriorityQueue)) {
		int x=Front(PriorityQueue);
		printf("%d ", x);
		Pop(PriorityQueue);
		printf("\n");
	}
	return 0;
}