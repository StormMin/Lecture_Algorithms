#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>
int selection(int* p, int n) {
	int min,index,temp;
	for (int i = 0; i < n; i++) {
		min = p[i];
		index = i;
		for (int j = i; j < n; j++) {
			if (min > p[j]) {
				min = p[j];
				index = j;
			}
		}
		temp = p[i];
		p[i] = p[index];
		p[index] = temp;
	}
}
int insert(int* q, int n) {
	int temp;
	for (int i = 0; i < n-1; i++) {
		int j = i;
		while (q[j] > q[j + 1]) {
			temp = q[j];
			q[j] = q[j + 1];
			q[j + 1] = temp;
			j--;
		}
	}
}
int main()
{
	LARGE_INTEGER ticksPerSec,start,end,diff;
	srand(time(NULL));
	int n,index,temp;
	scanf("%d", &n);
	int* p, * q;
	p = (int*)malloc(sizeof(int) * n);
	q = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		p[i] = rand();
		q[i] = p[i];
	}
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	selection(p, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	
	
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	insert(q, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	free(p);
	free(q);
	return 0;
}