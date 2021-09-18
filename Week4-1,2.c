#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int heap[99],size;
int downHeap(int i) {
	int root = i,c;
	do {
		c = root * 2;
		if (c <= size - 1&&heap[c]<heap[c+1]) {
			c++;
		}
		if (heap[c] > heap[root]&&c<=size) {
			int tmp = heap[c];
			heap[c] = heap[root];
			heap[root] = tmp;
		}
		root = c;
	} while (c <= size);
}
int rbuildHeap(int i) {
	if (i > size)
		return;
	rbuildHeap(i * 2);
	rbuildHeap(i * 2 + 1);
	downHeap(i);
}
int inPlaceHeapsort() {
	for (int i = size; i >= 1; i--) {
		int tmp = heap[1];
		heap[1] = heap[i];
		heap[i] = tmp;
		size--;
		downHeap(1);
	}
}
int printArray() {
	for (int i = 1; i <= size; i++) {
		printf(" %d", heap[i]);
	}
}
int main() {
	scanf("%d", &size);
	for (int i = 1; i <= size; i++) {
		scanf("%d", &heap[i]);
	}
	rbuildHeap(1);
	int cmp = size;
	inPlaceHeapsort();
	size = cmp;
	printArray();
	return 0;
}