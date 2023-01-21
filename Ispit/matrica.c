#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int isValid(int n, int i, int j){
    if(i < n && i >= 0 && j < n && j >= 0){
        return 1;
    }else{
        return 0;
    }
}

void loadMatrix(int n, int matrix[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}
void printMatrix(int n, int matrix[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int diagonAlley(int n, int matrix[n][n], int i, int j){
    int max = INT_MIN;
    for(int i1 = 0; i1 < n; i1++){
        for(int j1 = 0; j1 < n; j1++){
            if(isValid(n,i,j) && isValid(n,i1,j1));//ne znam ni sto sam ovo stavljao ali ajde

            if(i1+j1 == i+j && (matrix[i1][j1] != matrix[i][j])){
                if(matrix[i1][j1] > max){
                    max = matrix[i1][j1];
                }
            }
            if(i1 - j1 == i-j && (matrix[i1][j1] != matrix[i][j])){
                if(matrix[i1][j1] > max){
                    max = matrix[i1][j1];
                }
            }
        }
    }
    return max;
}

int main(){
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    int matrixB[n][n];
    loadMatrix(n,matrix);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){
            matrixB[i][j] = diagonAlley(n,matrix,i,j);
        }
    }
    printMatrix(n,matrixB);
    return 0;
}
/**
 Ulaz:
5
1 2 3 4 5
6 7 8 9 9
1 2 3 4 5
6 5 8 7 5
2 3 4 5 6

 */
