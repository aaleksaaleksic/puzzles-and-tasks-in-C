#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
///zmijica ucitavanja
///vrati broj max broj ponavljanja broja unutra ukupne sekvence
int main(){
    int n;
    scanf("%d",&n);
    ///deklarisanje matrice
    int matrica[n][n];
    ///ucitavanje matrice
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrica[i][j]);
        }
    }
////////////////////////////////////////////////////////////////////////////
    ///deklarisanje pomocnog niza u kome cemo da posmatramo sekvencu
    int zmija[n*n];
    int zmija_index = 0;
    for(int j = 0; j < n; j++){
        if(j % 2){
            for (int i = 0; i < n; i++) {
                zmija[zmija_index++] = matrica[i][j];
                ///ova linija u niz zmija ubacuje elemente iz matrice
            }
        }else{
            for(int i = n - 1; i >= 0; i--){
                zmija[zmija_index++] = matrica[i][j];
                ///ova linija u niz zmija ubacuje elemente iz matrice
            }
        }
    }
///////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < n*n;i++){
        printf("ucitan element : %d \n",zmija[i]);
        if((i+1) % 4 == 0){
            printf("\n");
        }
    }



    int brojPonavljanja = 1;
    int maxPonavljanja = 0;
    for(int i = 1; i < n*n; i++){
        if(zmija[i] == zmija[i-1]){  ///ako je trenutni element jednak prethodnom
            brojPonavljanja++;
        }else{
            if(brojPonavljanja > maxPonavljanja){
                maxPonavljanja = brojPonavljanja;
            }
            brojPonavljanja = 1;
        }
    }
    if(brojPonavljanja > maxPonavljanja){
        maxPonavljanja = brojPonavljanja;
    }
    printf("Broj ponavljanja : %d",maxPonavljanja);
    return 0;
}
/*
 *  3 4 1 1
    1 2 9 1
    5 6 6 1
    2 3 1 1
    rezultat treba da bude 3
 */