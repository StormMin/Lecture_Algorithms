#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	int n, max, index, temp;
	scanf("%d", &n);
	int* p;
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		max = p[i];
		index = i;
		for (int j = 0; j <= i; j++) {
			if (max < p[j]) {
				index = j;
				max = p[j];
			}
		}
		temp = p[i];
		p[i] = p[index];
		p[index] = temp;
	}
	for (int i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	free(p);
	return 0;
}