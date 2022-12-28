//
// Created by Korisnik on 12/28/2022.
//
/** Rotiranje prstenova za neku vrednost k
 * prstenova uvek ima n / 2
 * elemente jednog prstena spakujemo u niz
 * niz rotiramo tako sto while petljom prodjemo od 0 do broj rotacija i poslednji element spakujemo
 * i sve pomerimo za mesto u desno i vratimo poslednji element na prvo mesto
 * i onda te elemente vratimo iz niza u matricu*/
/*
8 1 7 5
8 7 4 6
7 4 4 9
0 1 3 7
 */

#include <stdio.h>
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

void popuni_niz(int gornja,int donja,int mat[100][100], int niz[100],int* dim){
    int cnt = 0;
    for(int i = gornja, j = gornja; j < donja; j++){
        niz[cnt++] = mat[i][j];
    }
    for(int i = gornja, j = donja; i < donja; i++){
        niz[cnt++] = mat[i][j];
    }
    for(int i = donja, j = donja; j > gornja; j--){
        niz[cnt++] = mat[i][j];
    }
    for(int i = donja, j = gornja; i > gornja; i--){
        niz[cnt++] = mat[i][j];
    }
    *dim = cnt;

}
void zarotiraj_niz(int niz[100],int dim,int k){
    int cnt = 0;
    while(cnt < k){
        int temp = niz[dim - 1];
        for(int i = dim - 2; i >= 0; i--){
            niz[i + 1] = niz[i];

        }
        niz[0] = temp;
        cnt++;

    }
}
void vrati_u_Matricu(int gornja,int donja,int mat[100][100], int niz[100], int dim){

    int cnt = 0;
    for(int i = gornja, j = gornja; j < donja; j++){
        mat[i][j] = niz[cnt++];
    }
    for(int i = gornja, j = donja; i < donja; i++){
        mat[i][j] = niz[cnt++];
    }
    for(int i = donja, j = donja; j > gornja; j--){
        mat[i][j] = niz[cnt++];
    }
    for(int i = donja, j = gornja; i > gornja; i--){
        mat[i][j] = niz[cnt++];
    }

}

int main(){

    int n,k;
    scanf("%d%d",&n,&k);
    int mat[100][100];
    popuniMatricu(mat,n);



    int cnt = 0;
    int upper = 0;
    int lower = n - 1;

    while(cnt < n/2){
        int niz[n * n];
        int dim = 0;
        popuni_niz(upper,lower,mat,niz,&dim);
        zarotiraj_niz(niz,dim,k);
        vrati_u_Matricu(upper,lower,mat,niz,dim);
        upper++;
        lower--;
        cnt++;
    }
    ispisiMatricu(mat,n);




    return 0;
}