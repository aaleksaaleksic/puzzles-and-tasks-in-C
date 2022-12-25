//
// Created by Korisnik on 12/25/2022.
//
/*
 * 3
 *
5 3 6
3 5 1
2 1 3
 *
 * */

#include <stdio.h>

int vratiBroj(int i, int j, int n, int mat[100][100]){
    return (mat[i - 1][j] + mat[i + 1][j] + mat[i][j-1] + mat[i][j+1]) - mat[i][j];
}

int main(){

    int n;
    scanf("%d", &n);
    int mat[100][100];
    int res[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i][j] = vratiBroj(i,j,n,mat);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ",res[i][j]);
        }
        printf("\n");
    }



}

