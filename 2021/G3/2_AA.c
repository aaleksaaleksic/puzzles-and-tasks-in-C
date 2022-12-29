//
// Created by Korisnik on 12/29/2022.
//

#include <stdio.h>
#include <limits.h>
/*
  5 4
1 2 2 2
6 3 1 1
5 8 1 1
6 3 3 1
7 2 1 2
 */
void rotateColumn(int j,int n,int k, int mat[100][100]){

    while(k > 0){
        int temp = mat[n - 1][j];
        for(int i = n - 1; i >= 0; i--){
            mat[i][j] = mat[i-1][j];
        }
        mat[0][j] = temp;
        k--;
    }
}
int biggestInColumn(int j,int n, int mat[100][100]){
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(mat[i][j] > max){
            max = mat[i][j];
        }
    }
    return max;
}
void popuniMatricu(int n,int m, int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void ispisiMatricu(int n,int m, int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
}
int isColumnPalindrome(int j,int n,int mat[100][100]){
    for(int i = 0; i < n/2; i++){
        if(mat[i][j] != mat[n - i - 1][j])
            return 0;
    }
    return 1;
}
int main(){
    int n,m;
    scanf("%d%d", &n,&m);
    int mat[100][100];
    popuniMatricu(n,m,mat);
    for(int j = 0; j < m; j++){
        if(!(isColumnPalindrome(j,n,mat))){
            int k = biggestInColumn(j,n,mat) % n;
            rotateColumn(j,n,k,mat);
        }

    }
    ispisiMatricu(n,m,mat);

    return 0;
}
