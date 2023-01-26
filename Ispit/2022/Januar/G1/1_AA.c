//
// Created by Korisnik on 1/20/2023.
//

#include <stdio.h>
/**
 Ulaz:
    5

1 2 3 4 5
6 7 8 9 9
1 2 3 4 5
6 5 8 7 5
2 3 4 5 6

 */

void inputMatrix(int n,int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void outputMatrix(int n,int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
}
int validnaPozicija(int i,int j,int n){
    return i >= 0 && i < n && j >= 0 && j < n;
}
int proveriDijagonale(int i,int j,int mat[100][100],int n){
    int p = i;
    int q = j;
    int max = -1;
    while(validnaPozicija(p - 1,q - 1,n)){ // gore levo
        p--;
        q--;
        if(mat[p][q] > max)
            max = mat[p][q];
    }
    p = i;
    q = j;
    while(validnaPozicija(p + 1,q + 1,n)){ // dole desno
        p++;
        q++;
        if(mat[p][q] > max)
            max = mat[p][q];
    }
    p = i;
    q = j;
    while(validnaPozicija(p + 1,q - 1,n)){ // dole levo
        p++;
        q--;
        if(mat[p][q] > max)
            max = mat[p][q];
    }
    p = i;
    q = j;
    while(validnaPozicija(p - 1,q + 1,n)){ // gore desno
        p--;
        q++;
        if(mat[p][q] > max)
            max = mat[p][q];
    }
    return max;
}

int main(){

    int n;
    scanf("%d",&n);
    int mat[100][100];
    int a[100][100];
    inputMatrix(n,mat);
//    printf("%d", proveriDijagonale(2,1,mat,n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = proveriDijagonale(i,j,mat,n);
        }
    }
    outputMatrix(n,a);

    return 0;
}