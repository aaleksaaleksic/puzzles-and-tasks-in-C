//
// Created by Korisnik on 12/27/2022.
//
#include <stdio.h>
/*
3 4 1 6
1 2 9 8
5 6 6 1
2 3 1 1
 */
int validnaPozicija(int i, int j, int n,int mat[100][100]){
    return i >= 0 && i < n && j >= 0 && j < n;
}
void popuniMatricu(int mat[100][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

int main(){

    int n;
    scanf("%d", &n);
    int cnt = 0;
    int mat[100][100];
    popuniMatricu(mat,n);
    int y[] = {1, -1};
    int dir = 0; //0 gore, 1 dole, znaci %2
    int i = -1,j = 0;
    int max_count = 0,count = 1;
    int trenutni;
    int prethodni = mat[0][0];



    while(cnt < n*n){
        int i1 = i + y[dir];
        int j1 = j;
        if(validnaPozicija(i1,j1,n,mat)){
            trenutni = mat[i1][j1];
            cnt++;
            i = i1;
        }
        else{
            dir++;
            dir %= 2;
            i = i1;
            j++;
            prethodni = trenutni;
            continue;
        }
        if(trenutni == prethodni){
            count++;
        }
        else{
            max_count = (count > max_count) ? count : max_count;
            count = 1;
        }
     prethodni = trenutni;


    }
    max_count = (count > max_count) ? count : max_count;
    printf("broj ponavljanja : %d",max_count);



    return 0;
}
