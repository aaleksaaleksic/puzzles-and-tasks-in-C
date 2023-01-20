#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int min(int a, int b){
    return a > b? b : a;
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
    printf("\n");
}

int minKolona(int n, int matrix[n][n],int kolona){
    int minimum = INT_MAX;
    for(int i = 0; i < n;i++){
        if(matrix[i][kolona] < minimum){
            minimum = matrix[i][kolona];
        }
    }
    return minimum;
}

int minVrsta(int n, int matrix[n][n],int vrsta){
    int minimum = INT_MAX;
    for(int j = 0; j < n;j++){
        if(matrix[vrsta][j] < minimum){
            minimum = matrix[vrsta][j];
        }
    }
    return minimum;
}

void funkcija(int n, int input[n][n],int output[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            output[i][j] = min(minKolona(n,input,j), minVrsta(n,input,i));
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    loadMatrix(n,matrix);
    int matrixB[n][n];
    printMatrix(n,matrix);
    funkcija(n,matrix,matrixB);
    printMatrix(n,matrixB);
    return 0;
}

/*
5
2 3 5 7 5
3 5 9 2 8
1 8 2 5 6
7 3 4 5 4
1 3 9 6 5
 */