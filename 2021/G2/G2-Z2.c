#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void loadMatrix(int n,int matrix[n][n]){
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}
void printMatrix(int n,int matrix[n][n]){
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sortColumns(int n,int matrix[n][n]){
    for(int column = 0; column < n; column++){ // iteritam kolonom kroz broj kolona kvadratne matrice
        for(int i = 0; i < n-1;i++){
            for(int j = i+1; j < n; j++){
                if(matrix[i][column] > matrix[j][column]){
                    swap(&matrix[i][column],&matrix[j][column]);
                }
            }
        }
    }
}
void swapRows(int n, int matrix[n][n]){
    for(int vrsta = 0; vrsta < n; vrsta++) { //iteriram kroz vrstu
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if(matrix[n-1][i] < matrix[n-1][j]){
                    swap(&matrix[vrsta][i],&matrix[vrsta][j]);
                }
            }
        }
    }
}



int main(){
    int n;
    scanf("%d",&n);
    int matrica[n][n];
    loadMatrix(n,matrica);
    printf("\nUcitana matrica\n");
    printMatrix(n,matrica);
    printf("\nSortirane kolone\n");
    sortColumns(n,matrica);
    printMatrix(n,matrica);
    swapRows(n,matrica);
    printf("\nSortirana poslijednja vrsta\n");
    printMatrix(n,matrica);
/*
5
3 6 7 5 3
5 6 2 9 1
2 7 0 9 3
6 0 6 2 6
1 8 7 9 2
*/
    return 0;
}
