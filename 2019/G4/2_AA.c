//
// Created by Korisnik on 12/27/2022.
//
/*
3 4 1 6
2 1 3 1
3 4 5 5
2 3 4 5
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
int validnaPozicija(int i, int j, int n,int mat[100][100]){
    return i >= 0 && i < n && j >= 0 && j < n;
}

int main(){

    int n;
    scanf("%d", &n);
    int mat[100][100];
    popuniMatricu(mat,n);
    int dir = 0;
    int x[] = {1,-1};
    int i = 0;
    int j = -1;
    int cnt = 0;
    int prethodni = mat[0][0],trenutni;
    int count = 1, max_count = 0;
    while(cnt < n * n){
        int i1 = i;
        int j1 = j + x[dir];
        trenutni = mat[i1][j1];
        if(validnaPozicija(i1,j1,n,mat)){
            if(prethodni < trenutni)
                count++;
            else{
                if (count > max_count)
                    max_count = count;
                count = 1;
            }
            cnt++;
            j = j1;
        } else{
            dir++;
            dir %= 2;
            i++;
            j = j1;
        }
        prethodni = trenutni;


    }
    printf("%d",max_count);

    return 0;
}
