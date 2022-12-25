//
// Created by Korisnik on 12/25/2022.
//
/*
 * 3
 *
5 3 7
3 5 1
2 1 3
 *
 * */
#include <stdio.h>
#include <limits.h>

int vratiBroj(int mat[100][100],int x, int y, int n){
    int broj = mat[x][y];
    int max = INT_MIN;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == x || j == y)
                continue;
            if(mat[i][j] > max)
                max = mat[i][j];
        }
    }
    return max + broj;
}

int main(){
    int n;
    scanf("%d", &n);
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
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}
