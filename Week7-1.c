#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef struct NODE {
    struct NODE* left;
    struct NODE* right;
    struct NODE* parent;
    int key;
}NODE;
void getNODE(NODE** p) {
    (*p) = (NODE*)malloc(sizeof(NODE));
    (*p)->left = NULL;
    (*p)->right = NULL;
    (*p)->parent = NULL;
}
bool isExternal(NODE* w) {
    if (w->left == NULL && w->right == NULL) {
        return 1;
    }
    else return 0;
}
bool isInternal(NODE* w) {
    if (w->left != NULL || w->right != NULL) {
        return 1;
    }
    else return 0;
}
NODE* sibling(NODE* w) {
    if (w->parent == NULL) {
        return;
    }
    if ((w->parent)->left == w) {
        return (w->parent)->right;
    }
    else return (w->parent)->left;
}
NODE* inOrderSucc(NODE* w) {
    w = w->right;
    if (isExternal(w)) {
        return;
    }
    while (isInternal(w->left)) {
        w = w->left;
    }
    return w;
}
NODE* reduceExternal(NODE* root, NODE* z) {
    NODE* w, * zs, * g;
    getNODE(&w);
    getNODE(&zs);
    getNODE(&g);
    w = (z->parent);
    zs = sibling(z);
    if (w->parent == NULL) {
        root = zs;
        zs->parent = NULL;
    }
    else {
        g = w->parent;
        zs->parent = g;
        if (w == g->left) {
            g->left = zs;
        }
        else {
            g->right = zs;
        }
    }
    free(z);
    free(w);
    return zs;
}
NODE* treeSearch(NODE* H, int k) {
    if (isExternal(H)) {
        return H;
    }
    if (H->key == k) {
        return H;
    }
    if (k > H->key) {
        return treeSearch(H->right, k);
    }
    else {
        return treeSearch(H->left, k);
    }
}
int insertitem(NODE* H, int k) {
    NODE* p, * le, * ri;
    getNODE(&p);
    getNODE(&le);
    getNODE(&ri);
    p = treeSearch(H, k);
    le->parent = p;
    ri->parent = p;
    p->key = k;
    p->left = le;
    p->right = ri;
}
int removeElement(NODE* H, int k) {
    NODE* p;
    getNODE(&p);
    p = treeSearch(H, k);
    if (isExternal(p)) {
        printf("X\n");
        return;
    }
    printf("%d\n", p->key);
    NODE* z,*y;
    getNODE(&z);
    getNODE(&y);
    z = p->left;
    if (!isExternal(z)) {
        z = p->right;
    }
    if (isExternal(z)) {
        reduceExternal(p, z);
    }
    else {
        y = inOrderSucc(p);
        z = y->left;
        p->key = y->key;
        reduceExternal(y, z);
    }
}
void print(NODE* H) {
    if (H->left != NULL && H->right != NULL) {
        printf(" %d", H->key);
        print(H->left);
        print(H->right);
    }
}
NODE* findElement(NODE* H, int k) {
    NODE* p;
    getNODE(&p);
    p = treeSearch(H, k);
    if (p->key == k) {
        printf("%d\n", k);
    }
    else printf("X\n");
}
int main() {
    NODE* H;
    getNODE(&H);
    char a;
    int data;
    while (1) {
        scanf("%c", &a);
        if (a == 'i') {
            scanf("%d", &data);
            insertitem(H, data);
        }
        if (a == 'd') {
            scanf("%d", &data);
            removeElement(H, data);
        }
        if (a == 's') {
            scanf("%d", &data);
            findElement(H, data);
        }
        if (a == 'p') {
            print(H);
            printf("\n");
        }
        if (a == 'q') {
            break;
        }
        getchar();
    }
    return 0;
}