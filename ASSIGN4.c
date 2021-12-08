#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
typedef struct vertice {
	int index;
	int bag;
}vertice;
typedef struct edge {
	int ver1, ver2;
	int dis;
}edge;
typedef struct Graph {
	vertice ver[100];
	edge ed[1000];
}Graph;
Graph* G;
int size;
edge heap[100];
void upheap(edge x) {
	int idx = ++size;
	while (idx > 1 && heap[idx / 2].dis < x.dis) {
		heap[idx] = heap[idx / 2];
		idx /= 2;
	}
	heap[idx] = x;
}
edge downheap(int x) {
	edge out = heap[x];
	heap[x] = heap[size--];
	int c,root = x;
	do {
		c = root * 2;
		if (heap[c].dis < heap[c + 1].dis && c <= size - 1) {
			c++;
		}
		if (heap[c].dis > heap[root].dis && c <= size) {
			edge tmp = heap[c];
			heap[c] = heap[root];
			heap[root] = tmp;
		}
		root = c;
	} while (c <= size);
	return out;
}
void Kru(int n, int m) {
	for (int i = 1; i <= n; i++) {
		G->ver[i].bag = i;
	}
	for (int i = 1; i <= m; i++) {
		upheap(G->ed[i]);
	}
	int MST = 0;
	while (size != 0) {
		edge tmp=downheap(1);
		if (G->ver[tmp.ver1].bag != G->ver[tmp.ver2].bag) {
			printf(" %d", tmp.dis);
			MST += tmp.dis;
			for (int i = 1; i <= n; i++) {
				if (G->ver[i].bag == G->ver[tmp.ver2].bag && i != tmp.ver2) {
					G->ver[i].bag = G->ver[tmp.ver1].bag;
				}
			}
			G->ver[tmp.ver2].bag= G->ver[tmp.ver1].bag;
		}
	}
	printf("\n%d", MST);
}
int main() {
	G = (Graph*)malloc(sizeof(Graph));
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		G->ver[i].index = i;
	}
	int a, b, w;
	for (int j = 1; j <= m; j++) {
		scanf("%d %d %d", &a, &b, &w);
		G->ed[j].ver1 = a;
		G->ed[j].ver2 = b;
		G->ed[j].dis = w;
	}
	Kru(n, m);
}