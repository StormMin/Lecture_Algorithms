#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int heap[101], size = 0;
int upHeap(int i) {
	while (i != 1 && heap[i] > heap[i / 2]) {
		int tmp = heap[i];
		heap[i] = heap[i / 2];
		heap[i / 2] = tmp;
		i /= 2;
	}
	return;
}
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
	} while (c <= size);
	return;
}
int insertltem(int key) {
	heap[++size] = key;
	upHeap(size);
	return;
}
int removeMax() {
	int key = heap[1];
	heap[1] = heap[size--];
	downHeap(1);
	return key;
}
int printHeap() {
	for (int i = 1; i <= size; i++) {
		printf(" %d", heap[i]);
	}
	printf("\n");
	return;
}
int main()
{
	int x;
	char a;
	while (1) {
		scanf("%c", &a);
		getchar();
		if (a == 'i') {
			scanf("%d", &x);
			getchar();
			insertltem(x);
			printf("0\n");

		}
		else if (a == 'd') {
			printf("%d\n", removeMax());
		}
		else if (a == 'p') {
			printHeap();
		}
		else if (a == 'q') {
			break;
		}
	}
	return 0;
}