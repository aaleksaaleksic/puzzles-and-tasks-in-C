//
// Created by Korisnik on 12/21/2022.
//
#include <stdio.h>
#include <math.h>

int brojCifara(int n){
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

    int dim = brojCifara(n);
    int mat[100][100];

    for(int i = 0; i < dim; i++){ // popunjavamo sporednu dijagonalu
        for(int j = 0; j < dim; j++){

            if(i + j == dim - 1)
                mat[i][j] = (int)(n / pow(10,j)) % 10;

        }
    }
    int j1 = dim - 1;
    int flag = 1;
    for(int i = 0; i < dim; i++){ // popunjavamo desno od sporedne
        int broj = mat[i][j1];
        flag = 1;
        for(int j = j1; j < dim; j++){
            if(j == j1){
                continue;
            }

            mat[i][j] = broj;
            flag++;
            if(flag == 2){
                flag = 0;
                broj++;
                broj %= 10;
            }
        }
        j1--;

    }
    flag = 1;
    j1 = dim - 1;

    for(int i = 0; i < dim; i++){ // popunjavamo levo od sporedne
        int broj = mat[i][j1] - 1;
        if(broj<0)
            broj = 9;
        flag = 1;

        for(int j = j1; j >= 0; j--){
            if(j == j1){
                continue;
            }

            mat[i][j] = broj;
            flag++;
            if(flag == 3){
                flag = 0;
                broj--;
                if(broj<0)
                    broj = 9;
            }
        }
        j1--;

    }

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            printf("%3d",mat[i][j]);
        }
        printf("\n");
    }


    return 0;
}