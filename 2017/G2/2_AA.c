//
// Created by Korisnik on 12/22/2022.
//
#include <stdio.h>
#include <math.h>

int dimenzija(int n){
    int cnt = 0;
    while(n > 0){
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main(){
    int n;
    scanf("%d", &n);

    int dim = dimenzija(n);
    int mat[100][100];

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(dim % 2 && i == dim/2){
                    mat[i][j] = (int)(n / pow(10, dim - 1 - j)) % 10;

            }
            else if(!(dim % 2) && (i == dim/2 || i == dim/2 - 1)){
                    mat[i][j] = (int)(n / pow(10, dim - 1 - j)) % 10;
            }
            else
                mat[i][j] = 0;
        }
    }
    int flag = 1;
    int trenutni_i;

    trenutni_i = dim / 2;

    for(int j = 0; j < dim; j++){
        int broj = mat[trenutni_i][j];
        for(int i = trenutni_i; i < dim; i++){
            if(i == trenutni_i)
                continue;
            mat[i][j] = broj;
            if(mat[i][j] < 0)
                mat[i][j] = 9;
            flag++;
            if(flag == 2){
                flag = 0;
                broj--;
            }


        }
    }
     flag = 0;
    trenutni_i = (dim % 2) ? dim / 2 : dim / 2 - 1;
    for(int j = 0; j < dim; j++){
        int broj = mat[trenutni_i][j] + 1;
        for(int i = trenutni_i; i >= 0; i--){
            if(i == trenutni_i)
                continue;
            mat[i][j] = broj % 10;
            flag++;
            if(flag == 2){
                flag = 0;
                broj++;
            }


        }
    }
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            printf("%3d",mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
