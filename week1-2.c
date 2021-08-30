#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef struct NODE {
	struct NODE* right;
	struct NODE* left;
	int data;
}NODE;
void getNODE(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
}
void add(NODE* H, int y, int z) {
	NODE* p, * q;
	getNODE(&p);
	getNODE(&q);
	p->data = y;
	q->data = z;
	p->left = NULL;
	p->right = NULL;
	q->left = NULL;
	q->right = NULL;
	if (y>0)
	H->left = p;
	if (z>0)
	H->right = q;
}
void find(NODE* H,int x,int y,int z) {
	if (H != NULL) {
		if (H->data == x) {
			add(H, y, z);
		}
		find(H->left,x, y, z);
		find(H->right, x, y, z);
	}
}
void prt(NODE* H, char a[]) {
	int size = strlen(a);
	for (int i = 0; i < size; i++) {
		printf(" %d", H->data);
		if (a[i] == 'R') {
			H = H->right;
		}
		else if (a[i] == 'L') {
			H = H->left;
		}
	}
	printf(" %d\n", H->data);
}
int main()
{
	NODE* H;
	getNODE(&H);
	H->data = NULL;
	H->left = NULL;
	H->right = NULL;
	int N,x,y,z;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (i == 0) {
			H->data = x;
		}
		find(H, x, y, z);
	}
	int M;
	char a[10];
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%s", a);
		prt(H, a);
	}
	return 0;
}
