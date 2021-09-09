#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>
int heap[101],size=0;
int downHeap(int i) {
	int root = i, c = 1;
	do {
		c = root * 2;
		if (c <= size - 1 && heap[c] < heap[c + 1]) {
			c++;
		}
		if (c <= size && heap[c] > heap[root]) {
			int tmp = heap[c];
			heap[c] = heap[root];
			heap[root] = tmp;
		}
		root = c;
	} while (c<=size);
	return;
}
int printHeap() {
	for (int i = 1; i <= size; i++) {
		printf(" %d", heap[i]);
	}
	printf("\n");
	return;
}
int rBuildHeap(int i) {
	if (i > size) {
		return;
	}
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
	return;
}
int buildHeap() {
	for (int i = size / 2; i >= 1; i--) {
		downHeap(i);
	}
}
int main()
{
	scanf("%d", &size);
	for (int i = 1; i <= size; i++) {
		scanf("%d", &heap[i]);
	}
	buildHeap();
	printHeap();
	return 0;
}