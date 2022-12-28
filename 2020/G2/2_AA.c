//
// Created by Korisnik on 12/28/2022.
//
/*
2 6 1 4
3 5 6 8
4 1 8 0
9 6 3 7
 * */
#include <stdio.h>
#include <limits.h>
void ispisiMatricu(int mat[100][100],int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
}
void popuniMatricu(int mat[100][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void zameniMestaDijagonalama(int mat[100][100], int a[100][100], int n, int cnt){
    if(cnt == 1){ // glavnu na sporednu
        int niz[100];
        int x = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    niz[x++] = mat[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i + j == n - 1)
                    a[i][j] = niz[--x];
            }
        }
    }
    else if(cnt == 2){
        int niz[100];
        int x = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i + j == n- 1)
                    niz[x++] = mat[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    a[i][j] = niz[--x];
            }
        }
    }
}
int max_susjed(int i,int j, int n,int mat[100][100]){
    int max = 0;
    for(int x = -1; x <= 1; x++){
            if (i + x >= 0 && i + x < n && j + x >= 0 && j + x < n && !(i + x == i && j + x == j)){
                if(mat[i + x][j] > max && mat[i + x][j] % 2 == 0 && mat[i + x][j] != 0)
                    max = mat[i + x][j];
                if(mat[i][j + x] > max && mat[i][j + x] % 2 == 0 && mat[i][j + x]!=0)
                    max = mat[i][j + x];

        }
    }

    return max;
}



int main(){

    int n;
    scanf("%d", &n);

    int mat[100][100];
    int a[100][100];
    popuniMatricu(mat,n);
    int cnt = 1;

    while(cnt <= 2){
        zameniMestaDijagonalama(mat,a,n,cnt);
        cnt++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && i + j != n - 1){
                a[i][j] = max_susjed(i,j,n,mat);
            }
        }
    }

    ispisiMatricu(a,n);



    return 0;
}
