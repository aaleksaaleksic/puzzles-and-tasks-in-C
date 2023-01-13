//
// Created by Korisnik on 1/13/2023.
//
#include <stdio.h>
/**
broj = 23561
n = 4, m = 6

3 8 3 6 7 3
2 9 2 5 5 6
1 9 3 1 6 8
7 6 1 6 6 9

teme:(1,2) dim:3X3
**/

int brojCifara(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n /= 10;
    }
    return cnt;
}
void inputMatrix(int n,int m,int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void outputMatrix(int n,int m, int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
}
int isItInArray(int cifre[100], int n,int x){
    for(int i = 0; i < n; i++){
        if(cifre[i] == x)
            return 1;
    }
    return 0;
}
int doesItContain(int mat[100][100], int cifre[100],int brojCifara,int i, int j, int dim){
    for(int i1 = i; i1 < i + dim; i1++){
        for(int j1 = j; j1 < j + dim; j1++){
            if(!(isItInArray(cifre,brojCifara,mat[i1][j1])))
                return 0;
        }
    }
    return 1;
}


int main(){
    int broj;
    scanf("%d", &broj);
    int brCifara = brojCifara(broj);
    int mat[100][100];

    int n,m;
    printf("Unesite dimenzije matrice:");
    scanf("%d%d",&n,&m);
    inputMatrix(n,m,mat);
    int cifre[brCifara];
    for(int i = 0; i < brCifara; i++){
        cifre[i] = broj % 10;
        broj /= 10;
    }
    int maxDim = (n > m) ? m : n;
    int max = 0;
    int x,y;

    for(int dim = 1; dim <= maxDim; dim++){
        for(int i = 0; i <= n - dim; i++){
            for(int j = 0; j <= m - dim; j++){
                if(doesItContain(mat,cifre,brCifara,i,j,dim)){
                    if(dim > max){
                        max = dim;
                        x = i;
                        y = j;
                    }
                }
            }
        }
    }
    printf("teme : (%d,%d) dim : %d X %d",x,y,max,max);




    return 0;
}
