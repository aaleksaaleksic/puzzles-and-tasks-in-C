//
// Created by Korisnik on 12/15/2022.
//

#include <stdio.h>
#include <math.h>

int brojCifara(int n){
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
    int dimension = brojCifara(n);
    int mat[dimension][dimension];


    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(i == 0){
                mat[i][j] = (int)(n / pow(10,dimension - j - 1)) % 10;
            }
            else
                mat[i][j] = 0;
        }
    }
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(i == 0)
                continue;
           else if (i % 2) {
                mat[i][j] = mat[i - 1][j] - 1;
                if (mat[i][j] < 0) {
                    mat[i][j] = (mat[i][j] == -1) ? 9 : 8;
                }
            }
           else{
                mat[i][j] = mat[i - 1][j] - 2;
                if (mat[i][j] < 0) {
                    mat[i][j] = (mat[i][j] == -1) ? 9 : 8;
                }

            }
        }

    }
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
        printf("%2d",mat[i][j]);
        }
        printf("\n");
    }


    return 0;
}
