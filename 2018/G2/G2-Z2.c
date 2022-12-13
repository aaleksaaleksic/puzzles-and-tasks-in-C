#include <stdio.h>
#define MAX 10

/**
UUP-2018-2019-KLK2-G2-Z2
2 (7p). Napraviti funkciju koja za unetu matricu dimenzija N x N pravi novu matricu čija se polja formiraju na sledeći način.
Svako polje u novoj matrici je jednako razlici sume susednih polja iz učitane matrice (iznad, ispod, levo, desno) i vrednosti sa trenutnog polja.
Korisnik učitava ceo broj N i matricu.

ULAZ:        IZLAZ:
5 3 6        1 13 -2
3 5 1        9 3  13
2 1 3        2 9  -1
*/


int element(int i, int j, int A[][MAX], int n) {
    int sum = 0;
    if(i+1 >= 0 && i+1 < n && j >= 0 && j < n)
        sum += A[i+1][j];
    if(i-1 >= 0 && i-1 < n && j >= 0 && j < n)
        sum+=A[i-1][j];
    if(i >= 0 && i < n && j-1 >= 0 && j-1 < n)
        sum += A[i][j-1];
    if(i >= 0 && i < n && j+1 >= 0 && j+1 < n)
        sum += A[i][j+1];

    return sum-A[i][j];

}
void ispisiMatricu(int A[][MAX],int size){
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            printf("%d ", A[i][j]);

        printf("\n");
    }
}

int main(void) {
    int A[MAX][MAX];
    int B[MAX][MAX];
    int n, i, j;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    // Za svako polje:
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            // Pravimo element u novoj matrici.
            B[i][j] = element(i, j, A, n);

    ispisiMatricu(B,n);
}



