#include <stdio.h>
#include <limits.h>
#define MAX 10
int main(){
    int n, i, j, k, d, kmin;
    float P[MAX], C[MAX][MAX], R[MAX][MAX];
    float minval, sum;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter probabilities P[i] for each key:\n");
    for (i = 1; i <= n; i++)
        scanf("%f", &P[i]);
    for (i = 1; i <= n; i++){
        C[i][i - 1] = 0;
        C[i][i] = P[i];
        R[i][i] = i;
    }
    C[n + 1][n] = 0;
    for (d = 1; d <= n - 1; d++){
        for (i = 1; i <= n - d; i++){
            j = i + d;
            minval = 9999;
            sum = 0;
            for (k = i; k <= j; k++){
                if (C[i][k - 1] + C[k + 1][j] < minval){
                    minval = C[i][k - 1] + C[k + 1][j];
                    kmin = k;
                }
            }
            for (k = i; k <= j; k++)
                sum += P[k];
            C[i][j] = minval + sum;
            R[i][j] = kmin;
        }
    }
    printf("\nMinimum cost of Optimal BST: %.4f\n", C[1][n]);
    printf("\nRoot Table R[i][j]:\n");
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i > j)
                printf(" - ");
            else
                printf("%4.0f", R[i][j]);
        }
        printf("\n");
    }
    return 0;
}