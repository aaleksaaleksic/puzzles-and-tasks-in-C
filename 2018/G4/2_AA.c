//
// Created by Korisnik on 12/25/2022.
//

#include <stdio.h>
#include <limits.h>
#include <math.h>
/*
1 2 3
4 5 6
7 8 9
 */

int vratiBroj(int mat[100][100],int x, int y, int n){
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(y == 0){
            if(mat[i][y + 1] < min)
                min = mat[i][y + 1];
        }
        else if(y == n - 1){
            if(mat[i][y - 1] < min)
                min = mat[i][y - 1];
        }
        else {
            if (mat[i][y - 1] < min)
                min = mat[i][y + 1];
            if (mat[i][y - 1] < min)
                min = mat[i][y - 1];
        }
    }
    for(int j = 0; j < n; j++){
        if(x == 0){
            if(mat[x + 1][j] > max)
                max = mat[x + 1][j];
        }
        else if(x == n - 1){
            if(mat[x - 1][j] > max)
                max = mat[x - 1][j];
        }
        else{
            if(mat[x - 1][j] > max)
                max = mat[x - 1][j];
            if(mat[x + 1][j] > max)
                max = mat[x + 1][j];
        }
    }
    return abs(min - max);
}

int main(){

    int n;
    scanf("%d",&n);
    int mat[100][100];
    int a[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = vratiBroj(mat,i,j,n);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
