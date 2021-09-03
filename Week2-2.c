#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	int n, index, temp;
	scanf("%d", &n);
	int* p;
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int j = i;
		while (p[j] > p[j + 1]) {
			temp = p[j];
			p[j] = p[j + 1];
			p[j + 1] = temp;
			j--;
		}
	}
	for (int i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	free(p);
	return 0;
}