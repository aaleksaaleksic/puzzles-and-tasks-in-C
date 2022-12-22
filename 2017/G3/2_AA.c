//
// Created by Korisnik on 12/22/2022.
//
#include <stdio.h>
#include <math.h>
int dimenzije(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n /= 10;
    }
    return cnt;
}
int main(){

    int n;
    scanf("%d", &n);
    int dim = dimenzije(n);
    int mat[100][100];

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(i == j)
                mat[i][j] = (int)(n / pow(10,i)) % 10;
            if(i + j== dim - 1)
                mat[i][j] = (int)(n / pow(10,j)) % 10;
        }
    }
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(i == j || i + j == dim - 1)
                continue;
            if((j < i && i + j < n - 1) || (j > i && i + j > n - 1)){
                mat[i][j] = (mat[j][j] + 1) % 10;
            }
            else{
                mat[i][j] = mat[j][j] - 1;
                if(mat[i][j] < 0)
                    mat[i][j] = 9;
            }
        }
    }
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            printf("%3d",mat[i][j]);
        }
        printf("\n");
    }

}
