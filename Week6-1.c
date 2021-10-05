#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int binary_Search(int* p, int m, int n, int k) {
    if (m <= n) {
        int w = -1, mid = (m + n) / 2;
        if (m == n) {
            if (p[m] > k) {
                return m - 1;
            }
            else return m;
        }
        if (p[mid] == k) {
            return mid;
        }
        else if (p[mid] < k) {
            w = binary_Search(p, mid + 1, n, k);
        }
        else {
            w = binary_Search(p, m, mid - 1, k);
        }
        return w;
    }
    else return m - 1;
}

int main() {
    int n, k, * p;
    scanf("%d %d", &n, &k);
    p = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    int f = binary_Search(p, 0, n - 1, k);
    printf("%d", f);
    free(p);
    return 0;
}