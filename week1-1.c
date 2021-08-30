#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int size;
typedef struct NODE {
	struct NODE* next;
	struct NODE* prev;
	char data;
}NODE;
void getNODE(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
}
void add(NODE* H, NODE* T,int c,char data) {
	NODE* p;
	getNODE(&p);
	p->next = NULL;
	p->prev = NULL;
	p->data = data;
	for (int i = 1; i < c; i++) {
		H = H->next;
	}
	(H->next)->prev = p;
	p->next = H->next;
	H->next = p;
	p->prev = H;
	size++;
}
void delete(NODE* H, NODE* T,int c) {
	for (int i = 1; i < c; i++) {
		H = H->next;
	}
	H->next = (H->next)->next;
	(H->next)->prev = H;
	size--;
}
void gets(NODE* H, NODE* T, int c) {
	for (int i = 0; i < c; i++) {
		H = H->next;
	}
	printf("%c\n",H->data);
}
void print(NODE* H, NODE* T) {
	H = H->next;
	for (int i = 1; i <= size; i++) {
		printf("%c", H->data);
		H = H->next;
	}
	printf("\n");
}
int main()
{
	NODE* H, * T;
	getNODE(&H);
	getNODE(&T);
	H->next = T;
	T->prev = H;
	H->prev = NULL;
	T->next = NULL;
	T->data = NULL;
	H->data = NULL;
	int N,x;
	char a,b;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%c", &a);
		getchar();
		if (a == 'A') {
			scanf("%d %c", &x, &b);
			getchar();
			if (x <= size+1) {
				add(H, T, x, b);
			}
			else {
				printf("invalid position\n");
			}
		}
		if (a == 'D') {
			scanf("%d", &x);
			getchar();
			if (x <= size) {
				delete(H, T, x);
			}
			else {
				printf("invalid position\n");
			}
		}
		if (a == 'P') {
			if (size <= 1) {
				printf("invalid position\n");
			}
			else {
				print(H, T);
			}
		}
		if (a == 'G') {
			scanf("%d", &x);
			getchar();
			if (x <= size) {
				gets(H, T, x);
			}
			else {
				printf("invalid position\n");
			}
		}
	}
	return 0;
}
