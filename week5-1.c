#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef struct NODE {
	int data;
	struct NODE* next;
}NODE;
void getNODE(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
}
void add(NODE* L, int w) {
	while (L->next != NULL) {
		L = L->next;
	}
	NODE* p;
	getNODE(&p);
	p->data = w;
	p->next = NULL;
	L->next = p;
}
void partition(NODE* L, NODE** L1, NODE** L2, int k) {
	NODE* p;
	getNODE(&p);
	NODE* H, * T;
	*L1 = L;
	p = L;
	for (int i = 0; i < k / 2 - 1; i++) {
		p = p->next;
	}
	*L2 = p->next;
	p->next = NULL;
}
NODE* merge(NODE** L1, NODE** L2) {
	NODE* H = *L1, * T = *L2;
	NODE* p, * q;
	if (H->data < T->data) {
		q = H;
		p = q;
		H = H->next;
	}
	else {
		q = T;
		p = q;
		T = T->next;
	}
	while (H != NULL && T != NULL) {
		if (H->data < T->data) {
			p->next = H;
			H = H->next;
			p = p->next;
		}
		else {
			p->next = T;
			T = T->next;
			p = p->next;
		}
	}
	if (H != NULL) {
		p->next = H;
	}
	if (T != NULL) {
		p->next = T;
	}
	return q;
}
void mergeSort(NODE** L, int k) {
	if (k > 1) {
		NODE* L1, * L2;
		getNODE(&L1);
		getNODE(&L2);
		partition(*L, &L1, &L2, k);
		mergeSort(&L1, k / 2);
		if (k % 2 == 0) {
			mergeSort(&L2, k / 2);
		}
		else {
			mergeSort(&L2, k / 2 + 1);
		}
		*L = merge(&L1, &L2);
	}
}
int main() {
	NODE* L;
	getNODE(&L);
	L->next = NULL;
	int N, w;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &w);
		if (i == 0) L->data = w;
		else
			add(L, w);
	}
	mergeSort(&L, N);
	while (L != NULL) {
		printf(" %d", L->data);
		L = L->next;
	}
	return 0;
}