#include <stdio.h>
#include <limits.h>

int MatrixChainMulti(int n, int p[]) {
    int m[n][n];
    int s[n][n];
    int i, j, k, d, q;

    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (d = 1; d < n - 1; d++) {
        for (i = 1; i < n - d; i++) {
            j = i + d;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int p[] = {5, 4, 6, 2, 7};
    int n = sizeof(p) / sizeof(p[0]);

    int cost = MatrixChainMulti(n, p);
    printf("Minimum cost = %d\n", cost);

    return 0;
}
