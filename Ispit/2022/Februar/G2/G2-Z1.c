#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Function to right-rotate an array by one position
void rightRotateByOne(int A[], int n)
{
    int last = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        A[i + 1] = A[i];
    }
    A[0] = last;
}
// Function to right-rotate an array by `k` positions
void rightRotate(int A[], int k, int n)
{
    // base case: invalid input
    if (k < 0 || k >= n) {
        return;
    }
    for (int i = 0; i < k; i++) {
        rightRotateByOne(A, n);
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int matrica[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrica[i][j]);
        }
    }

    int b[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = 0;
        }
    }
    int start = 0;
    int end = n-1;
    for(int z = 0; z < n/2;z++) {
        int niz[n * n];
        int niz_index = 0;
        //ucitavam gore desno u niz
        for (int j = start; j < end; j++) {
            niz[niz_index++] = matrica[start][j];
        }
        //ucitavam desno dolje
        for (int i = start; i < end; i++) {
            niz[niz_index++] = matrica[i][end];
        }
        //ucitavam dolje lijevo
        for (int j = end; j > start; j--) {
            niz[niz_index++] = matrica[end][j];
        }
        //ucitavam dolje put gore
        for (int i = end; i > start; i--) {
            niz[niz_index++] = matrica[i][start];
        }

        //rotiram niz za k pozicija
        printf("\nUcitan niz: \n");
        for (int i = 0; i < niz_index; ++i) {
            printf("%d ,", niz[i]);
        }

        printf("\nRotiran niz:\n");
        rightRotate(niz, k, niz_index);

        for (int i = 0; i < niz_index; ++i) {
            printf("%d ,", niz[i]);
        }
        printf("\n");

        //vracam iz niza u matricu
        //sada pravim novu matricu
        niz_index = 0;
        for (int j = start; j < end; j++) {
            b[start][j] = niz[niz_index++];
        }
        for (int i = start; i < end; i++) {
            b[i][end] = niz[niz_index++];
        }
        for (int j = end; j > start; j--) {
            b[end][j] = niz[niz_index++];
        }
        for (int i = end; i > start; i--) {
            b[i][start] = niz[niz_index++];
        }
        start++;
        end--;
    }

    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
