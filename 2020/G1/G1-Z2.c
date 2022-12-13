#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


void rotate_rings( int n,int matrix[n][n], int m, int k) {
    // Iterate over the rings of the matrix
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < m - i - 1; j++) {
            // Store the current element in a temporary variable
            int temp = matrix[i][j];

            // Shift the remaining elements in the ring to their new positions
            matrix[i][j] = matrix[n - j - 1][i + k % (m - i - i)];
            matrix[n - j - 1][i + k % (m - i - i)] = matrix[n - i - 1][m - j - 1 + k % (m - i - i)];
            matrix[n - i - 1][m - j - 1 + k % (m - i - i)] = matrix[j][m - i - 1 + k % (m - i - i)];
            matrix[j][m - i - 1 + k % (m - i - i)] = temp;
        }
    }
}


int main(){
   int n,k;
   scanf("%d %d",&n,&k);
   int matrica[n][n];

   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           scanf("%d",&matrica[i][j]);
       }
   }
    rotate_rings(n,matrica,n,k);
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %d ",matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
6 8 Izlaz: 4 2 Izlaz:
3 2 6 4 5 8 4 2 3 4 9 0 8 1 7 5 7 8 8 1
7 4 3 2 7 1 3 2 9 4 9 0 8 7 4 6 0 4 4 7
0 5 6 9 2 3 2 7 6 9 2 7 7 4 4 9 1 4 7 5
0 7 9 4 9 4 9 2 9 4 2 3 0 1 3 7 3 7 9 6
9 2 2 9 4 9 4 3 4 5 7 2
4 3 2 4 3 2
 */