#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
typedef struct NODE {
	struct NODE* next;
	struct edge* ed;
}NODE;
typedef struct vertice {
	struct vertice* next;
	struct NODE* inc;
	int label;
	char index;
	int topo;
}vertice;
typedef struct edge {
	struct edge* next;
	struct vertice* ver1, * ver2;
}edge;
vertice* v;
edge* e;
char * topOrder;
int t;
int addvertice(char a) {
	vertice* x = v;
	while (x->next != NULL) {
		x = x->next;
	}
	vertice* New;
	New = (vertice*)malloc(sizeof(vertice));
	New->next = NULL;
	New->label = 0;
	New->index = a;
	New->inc = (NODE*)malloc(sizeof(NODE));
	New->inc->next = NULL;
	x->next = New;
}
int addedge(char u, char w) {
	vertice* x=v, * y=v;
	while (x->index != u) {
		x = x->next;
	}
	while (y->index != w) {
		y = y->next;
	}
	edge* eo=e;
	while (eo->next != NULL) {
		eo = eo->next;
	}
	edge* New;
	New = (edge*)malloc(sizeof(edge));
	New->next = NULL;
	New->ver1 = x;
	New->ver2 = y;
	eo->next = New;
	NODE* xx=x->inc, * incx;
	while (xx->next != NULL) {
		xx = xx->next;
	}
	incx = (NODE*)malloc(sizeof(NODE));
	incx->ed = New;
	incx->next = NULL;
	xx->next = incx;
}
int buildheap() {
	int n,m;
	char a,u,w;
	v = (vertice*)malloc(sizeof(vertice));
	e = (edge*)malloc(sizeof(edge));
	v->next = NULL;
	e->next = NULL;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		scanf("%c", &a);
		if (i == 1) {
			v->index = a;
			v->inc = (NODE*)malloc(sizeof(NODE));
			v->inc->next = NULL;
		}
		else
			addvertice( a);
		getchar();
	}
	scanf("%d", &m);
	getchar();
	for (int i = 1; i <= m; i++) {
		scanf("%c %c", &u, &w);
		addedge(u, w);
		getchar();
	}
	return n;
}
int rtoloGraph(vertice *x) {
	x->label = 1;
	NODE* xx = x->inc->next;
	while (xx != NULL) {
		if (xx->ed->ver1 == x) {
			if (xx->ed->ver2->label == 0) {
				rtoloGraph(xx->ed->ver2);
			}
			else if (xx->ed->ver2->topo == 0) {
				printf("CYCLE\n");
			}
		}
		else if (xx->ed->ver2 == x) {
			if (xx->ed->ver1->label == 0) {
				rtoloGraph(xx->ed->ver1);
			}
			else if (xx->ed->ver1->topo == 0) {
				printf("CYCLE\n");
			}
		}
		xx = xx->next;
	}
	x->topo = 1;
	topOrder[t - 1] = x->index;
	t--;
}
void toloGraph(int n) {
	topOrder = (char*)malloc(sizeof(char)*n);
	vertice* x = v;
	edge* y = e;
	while (x != NULL) {
		x->label = 0;
		x->topo = 0;
		x = x->next;
	}
	x = v;
	while (x != NULL) {
		if (x->label == 0) {
			rtoloGraph(x);
		}
		x = x->next;
	}
}
int main() {
	int n = buildheap();
	t = n;
	toloGraph(n);
	for (int i = 0; i < n; i++) {
		printf("%c ", topOrder[i]);
	}
}