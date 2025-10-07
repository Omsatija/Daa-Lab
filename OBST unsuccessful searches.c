#include <stdio.h>
#include <float.h>
#define MAX 10
int main(){
    int n, i, j, k;
    float p[MAX], q[MAX];
    float E[MAX][MAX], W[MAX][MAX];
    int R[MAX][MAX];
    float cost;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter %d probabilities of successful searches (p[i]):\n", n);
    for (i = 1; i <= n; i++)
        scanf("%f", &p[i]);
    printf("Enter %d probabilities of unsuccessful searches (q[i]):\n", n + 1);
    for (i = 0; i <= n; i++)
        scanf("%f", &q[i]);
    for (i = 0; i <= n; i++){
        E[i][i] = q[i];
        W[i][i] = q[i];
        R[i][i] = 0;
    }
    for (int d = 1; d <= n; d++){
        for (i = 0; i <= n - d; i++){
            j = i + d;
            E[i][j] = FLT_MAX;
            W[i][j] = W[i][j - 1] + p[j] + q[j];
            for (k = i + 1; k <= j; k++){
                cost = E[i][k - 1] + E[k][j] + W[i][j];
                if (cost < E[i][j]) {
                    E[i][j] = cost;
                    R[i][j] = k;
                }
            }
        }
    }
    printf("\nMinimum expected cost of Optimal BST: %.4f\n", E[0][n]);
    printf("\nMatrix E (Expected Cost):\n");
    for (i = 0; i <= n; i++){
        for (j = 0; j <= n; j++){
            if (j < i)
                printf("   -   ");
            else
                printf("%7.3f ", E[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix W (Weights):\n");
    for (i = 0; i <= n; i++){
        for (j = 0; j <= n; j++){
            if (j < i)
                printf("   -   ");
            else
                printf("%7.3f ", W[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix R (Roots):\n");
    for (i = 0; i <= n; i++){
        for (j = 0; j <= n; j++){
            if (j < i)
                printf("  -  ");
            else
                printf("%4d ", R[i][j]);
        }
        printf("\n");
    }
    return 0;
}