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
void newLine(){
    printf("\n");
}
//268939

void stampajSusjede(int n, int matrix[n][n], int i, int j){
    printf("OG i:%d j:%d = %d\n",i,j,matrix[(i)%n][j]);
    printf("Polje [i-1]:%d [j-1]:%d = %d\n",(i-1+n)%n,(j-1+n)%n,matrix[(i-1+n)%n][(j-1+n)%n]);
    printf("Polje [i-1]:%d [j]:%d = %d\n",(i-1+n)%n,j,matrix[(i-1+n)%n][(j)%n]);
    printf("Polje [i-1]:%d [j+1]:%d = %d\n",(i-1+n)%n,(j+1+n)%n,matrix[(i-1+n)%n][(j+1+n)%n]);
    printf("Polje [i]:%d [j-1]:%d = %d\n",i,(j-1+n)%n,matrix[(i)%n][(j-1+n)%n]);
    printf("Polje [i]:%d [j+1]:%d = %d\n",i,(j+1+n)%n,matrix[(i)%n][(j+1+n)%n]);
    printf("Polje [i+1]:%d [j-1]:%d = %d\n",(i+1+n)%n,(j-1+n)%n,matrix[(i+1+n)%n][(j-1+n)%n]);
    printf("Polje [i+1]:%d [j]:%d = %d\n",(i+1+n)%n,j,matrix[(i+1+n)%n][(j)%n]);
    printf("Polje [i+1]:%d [j+1]:%d = %d\n",(i+1+n)%n,(j+1+n)%n,matrix[(i+1+n)%n][(j+1+n)%n]);
}



int maxSusjed(int n, int matrix[n][n],int i, int j){
    int max = INT_MIN;
    if(matrix[(i-1+n)%n][(j-1+n)%n] > max)max = matrix[(i-1+n)%n][(j-1+n)%n];
    if(matrix[(i-1+n)%n][(j+n)%n] > max)max = matrix[(i-1+n)%n][(j+n)%n];
    if(matrix[(i-1+n)%n][(j+1+n)%n] > max)max = matrix[(i-1+n)%n][(j+1+n)%n];
    if(matrix[(i)%n][(j-1+n)%n] > max)max = matrix[(i)%n][(j-1+n)%n];
    if(matrix[(i)%n][(j+1+n)%n] > max)max = matrix[(i+n)%n][(j+1+n)%n];
    if(matrix[(i+1+n)%n][(j-1+n)%n] > max)max = matrix[(i+1+n)%n][(j-1+n)%n];
    if(matrix[(i+1+n)%n][(j)%n] > max)max = matrix[(i+1+n)%n][(j)%n];
    if(matrix[(i+1+n)%n][(j+1+n)%n] > max)max = matrix[(i+1+n)%n][(j+1+n)%n];
    return max;
}

int minSusjed(int n, int matrix[n][n],int i, int j){
    int min = INT_MAX;
    if(matrix[(i-1+n)%n][(j-1+n)%n] < min)min = matrix[(i-1+n)%n][(j-1+n)%n];
    if(matrix[(i-1+n)%n][(j+n)%n] < min)min = matrix[(i-1+n)%n][(j+n)%n];
    if(matrix[(i-1+n)%n][(j+1+n)%n] < min)min = matrix[(i-1+n)%n][(j+1+n)%n];
    if(matrix[(i)%n][(j-1+n)%n] < min)min = matrix[(i)%n][(j-1+n)%n];
    if(matrix[(i)%n][(j+1+n)%n] < min)min = matrix[(i+n)%n][(j+1+n)%n];
    if(matrix[(i+1+n)%n][(j-1+n)%n] < min)min = matrix[(i+1+n)%n][(j-1+n)%n];
    if(matrix[(i+1+n)%n][(j)%n] < min)min = matrix[(i+1+n)%n][(j)%n];
    if(matrix[(i+1+n)%n][(j+1+n)%n] < min)min = matrix[(i+1+n)%n][(j+1+n)%n];
    return min;

}

void doStuff(int n, int input[n][n],int output[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            output[i][j] = abs(maxSusjed(n,input,i,j) - minSusjed(n,input,i,j));
        }
    }
}

/*
4
2 1 4 7
5 3 8 2
6 1 7 9
3 0 4 2

7 8 8 6
8 7 8 7
9 8 9 6
9 6 9 7


 */

int main(){
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    int solution[n][n];
    loadMatrix(n,matrix);
    printMatrix(n,matrix);
    stampajSusjede(n,matrix,3,0);
    printf("Max susjed : %d", maxSusjed(n,matrix,3,0));
    newLine();
    printf("Min susjed : %d", minSusjed(n,matrix,3,0));
    doStuff(n,matrix,solution);
    newLine();
    newLine();
    printMatrix(n,solution);
    return 0;
}