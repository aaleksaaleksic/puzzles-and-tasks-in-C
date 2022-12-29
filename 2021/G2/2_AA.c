//
// Created by Korisnik on 12/29/2022.
//
/*
 Ulaz:
3 6 7 5 3
5 6 2 9 1
2 7 0 9 3
6 0 6 2 6
1 8 7 9 2

 */
#include <stdio.h>

void popuniMatricu(int n, int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void ispisiMatricu(int n, int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
}
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap_kolone(int j1,int j2,int n, int mat[100][100]){
    for(int i = 0; i < n; i++){
        swap(&mat[i][j1],&mat[i][j2]);
    }

}
void sortirajKolonu(int j,int n,int mat[100][100]){
    for(int i = 0; i < n - 1; i++){
        for(int x = 0; x < n - 1; x++){
            if(mat[x][j] > mat[x + 1][j])
                swap(&mat[x][j],&mat[x + 1][j]);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int mat[100][100];
    popuniMatricu(n,mat);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sortirajKolonu(j,n,mat);
        }
    }
    for(int i = n - 1, j = 0; j < n - 1; j++){
        for(int x = 0; x < n - 1; x++){
            if(mat[i][x] < mat[i][x + 1]){
                swap_kolone(x,x + 1,n,mat);
            }
        }

    }
    ispisiMatricu(n,mat);

    return 0;
}
