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
int main() {
    int n;
    scanf("%d", &n);
    int dim = brojCifara(n);
    int mat[dim][dim];
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (i == dim - 1) {
                mat[i][j] = (int) (n / pow(10, dim - j - 1)) % 10;
            } else {
                mat[i][j] = 0;
            }
        }
    }
    for (int i = dim - 1; i >= 0; i--) {
        for (int j = dim - 1; j >= 0; j--) {

            if (i == dim - 1)
                continue;
            else if (i % 2) {
                mat[i][j] = mat[i + 1][j] + 2;
                if (mat[i][j] >= 10) {

                    mat[i][j] = (mat[i][j] == 11) ? 1 : 0;
                }
            } else {
                mat[i][j] = mat[i + 1][j] + 1;
                if (mat[i][j] >= 10) {
                    mat[i][j] = (mat[i][j] == 11) ? 1 : 0;
                }

            }
        }
    }


        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {

                printf("%2d", mat[i][j]);
            }
            printf("\n");
        }

    }






