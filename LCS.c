#include <stdio.h>
#include <string.h>
#define MAX 100

void LCS(char s1[], char s2[], int m, int n, int C[MAX][MAX], int B[MAX][MAX]) {
    for (int i = 0; i <= m; i++) {
        C[i][0] = 0;
    }
  
    for (int j = 0; j <= n; j++) {
        C[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          
            if (s1[i - 1] == s2[j - 1]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = 0;
            }
            else if (C[i - 1][j] >= C[i][j - 1]) {
                C[i][j] = C[i - 1][j];
                B[i][j] = 1;
            } 
            else {
                C[i][j] = C[i][j - 1];
                B[i][j] = 2;
            }
        }
    }
}

void printLCS(int m, int n, int B[MAX][MAX], char s1[]) {
    if (m == 0 || n == 0) {
        return;
    }

    if (B[m][n] == 0) {
        printLCS(m - 1, n - 1, B, s1);
        printf("%c", s1[m - 1]);
    } 
    else if (B[m][n] == 1) {
        printLCS(m - 1, n, B, s1);
    } 
    else {
        printLCS(m, n - 1, B, s1);
    }
}

int main() {
    char s1[] = "ABCBDAB";
    char s2[] = "BDCABA";
    int m = strlen(s1);
    int n = strlen(s2);
    int C[MAX][MAX], B[MAX][MAX];

    LCS(s1, s2, m, n, C, B);

    printf("Length of LCS: %d\n", C[m][n]);
    printf("LCS: ");
    printLCS(m, n, B, s1);

    return 0;
}
