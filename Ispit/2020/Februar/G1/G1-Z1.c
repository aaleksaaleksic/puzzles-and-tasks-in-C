#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

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
int vratiMaxIzKolone(int n,int matrix[n][n],int kolona){
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(matrix[i][kolona] > max && matrix[i][kolona] != 0){
            max = matrix[i][kolona];
        }
    }
    return max;
}
int vratiMinimumIzKolone(int n,int matrix[n][n],int kolona){
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        if(matrix[i][kolona] < min && matrix[i][kolona] != 0){
            min = matrix[i][kolona];
        }
    }
    return min;
}
void seciBadnjak(int n,int matrix[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i+j+n/2 < n -1) || (j < i-n/2) || (j > i + n/2) || (i+j-n/2 > n-1)){
                matrix[i][j] = 0;
            }
        }
    }
}
void popuniPolja(int n, int matrix[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i+j+n/2 < n -1) || (j > i + n/2)){
                matrix[i][j] = vratiMaxIzKolone(n,matrix,j);
            }else if((j < i-n/2) || (i+j-n/2 > n-1)){
                matrix[i][j] = vratiMinimumIzKolone(n,matrix,j);
            }
        }
    }
}

void newLine(){
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    loadMatrix(n,matrix);
    printMatrix(n,matrix);
    newLine();
    seciBadnjak(n,matrix);
    printMatrix(n,matrix);
    popuniPolja(n,matrix);
    newLine();
    printMatrix(n,matrix);
    return 0;
}
/*
 6
1 3 5 6 7 5
2 3 4 5 1 6
9 1 1 3 4 8
5 6 7 8 7 9
1 2 3 4 5 0
3 4 1 2 6 4
 */
