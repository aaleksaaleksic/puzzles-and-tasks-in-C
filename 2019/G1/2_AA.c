//
// Created by Korisnik on 12/27/2022.
//
#include <stdio.h>
int validnaPozicija(int i,int j, int n, int mat[100][100]){
    return i >= 0 && i < n && j >= 0 && j < n && mat[i][j] == 0;
}
void popuniNulama(int mat[100][100],int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = 0;
        }
    }
}
void ispisiMatricu(int mat[100][100],int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
}
int main(){

    int br,n;
    int cnt = 1;
    scanf("%d%d",&br,&n);
    int mat[100][100];
    popuniNulama(mat,n);

    int x[] = {1, 0,-1,0};
    int y[] = {0,1,0,-1};
    int dir = 0;
    int i = 0;
    int j = -1;

    while(cnt <= n*n){
        int i1 = i + y[dir], j1 = j + x[dir];
        if(validnaPozicija(i1,j1,n,mat)){

            mat[i1][j1] = br;
            i = i1;
            j = j1;
            cnt++;
        }


        else{
            dir++;
            dir %= 4;
            br++;
            br %= 10;
            mat[i][j] = br;
        }




    }
    ispisiMatricu(mat,n);




    return 0;
}
