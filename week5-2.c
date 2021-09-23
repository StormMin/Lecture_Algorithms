#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int findPivot(int* x, int start, int end) {
	return start;
}
int inPaclePartition(int* x, int start, int end, int key) {
	int i = start + 1;
	int j = end;
	while (i <= j) {
		while (x[key] >= x[i]) {
			i++;
		}
		while (x[key] <= x[j] && j > start) {
			j--;
		}
		if (i > j) {
			int temp = x[j];
			x[j] = x[key];
			x[key] = temp;
		}
		else {
			int temp = x[j];
			x[j] = x[i];
			x[i] = temp;
		}
	}
	return j;
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