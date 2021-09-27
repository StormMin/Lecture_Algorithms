#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int findPivot(int* x, int start, int end) {
	srand(time(NULL));
	int random = start + (rand()/1) % (end - start + 1);
	return random;
}
int inPaclePartition(int* x, int start, int end, int key) {
	int temp = x[key];
	x[key] = x[end];
	x[end] = temp;
	int lock = start;
	for (int i = start; i < end; i++) {
		if (x[i] < x[end]) {
			temp = x[i];
			x[i] = x[lock];
			x[lock++] = temp;
		}
	}
	temp = x[lock];
	x[lock] = x[end];
	x[end] = temp;
	return lock;
}
void inPlaceQuicksort(int* x, int start, int end) {
	if (start >= end) {
		return;
	}
	int key = findPivot(x, start, end);
	int pivot = inPaclePartition(x, start, end, key);
	inPlaceQuicksort(x, start, pivot - 1);
	inPlaceQuicksort(x, pivot + 1, end);
}
int main() {
	int n, * x;
	scanf("%d", &n);
	x = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	inPlaceQuicksort(x, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf(" %d", x[i]);
	}
	return 0;
}