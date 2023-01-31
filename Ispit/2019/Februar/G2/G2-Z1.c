#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int jesteDioNiza(int n, int array[n],int broj){
    int output = 0;
    for(int i = 0; i < n; i++){
        if(array[i] == broj){
            output = 1;
        }
    }
    return output;
}
void popuniNizNulama(int n, int array[n]){
    for(int i = 0; i < n; i++){
        array[i] = 0;
    }
}
void vratiKaoNizVrstu(int n, int matrix[n][n],int vrsta,int array[n]){
    int arrayIndex = 0;
    popuniNizNulama(n,array);
    for(int j = 0; j < n; j++){
        if(jesteDioNiza(n,array,matrix[vrsta][j])){
            continue;
        }else{
            array[arrayIndex] = matrix[vrsta][j];
            arrayIndex++;
        }
    }
}
void vratiKaoNizKolonu(int n, int matrix[n][n],int kolona,int array[n]){
    int arrayIndex = 0;
    popuniNizNulama(n,array);
    for(int i = 0; i < n; i++){
        if(jesteDioNiza(n,array,matrix[i][kolona])){
            continue;
        }else{
            array[arrayIndex] = matrix[i][kolona];
            arrayIndex++;
        }
    }
}
void loadMatrix(int n, int matrix[n][n]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}
void printMatrix(int n, int matrix[n][n]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n; j++){
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
}
void swap(int *a, int*b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
void sortArray(int n, int array[n]){
    for(int i = 0; i < n-1;i++){
        for(int j = i+1; j < n; j++){
            if(array[i] <= array[j]){
                swap(&array[i],&array[j]);
            }
        }
    }
}
int uporediDvijeVrste(int n, int matrixA[n][n], int prvaVrsta,int matrixB[n][n],int drugaVrsta){
    int output = 0;
    int arrayA[n];
    vratiKaoNizVrstu(n,matrixA,prvaVrsta,arrayA);
    int arrayB[n];
    vratiKaoNizVrstu(n,matrixB,drugaVrsta,arrayB);
    sortArray(n,arrayA);
    sortArray(n,arrayB);
    for(int i = 0; i < n; i++){
        if(arrayA[i] == arrayB[i]){
            output = 1;
        }else{
            return 0;
        }
    }
    return output;
}
int uporediDvijeKoloone(int n, int matrixA[n][n], int prvaKolona,int matrixB[n][n],int drugaKolona){
    int output = 0;
    int arrayA[n];
    vratiKaoNizKolonu(n,matrixA,prvaKolona,arrayA);
    int arrayB[n];
    vratiKaoNizKolonu(n,matrixB,drugaKolona,arrayB);
    sortArray(n,arrayA);
    sortArray(n,arrayB);
    for(int i = 0; i < n; i++){
        if(arrayA[i] == arrayB[i]){
            output = 1;
        }else{
            return 0;
        }
    }
    return output;
}
void uporediSveVrste(int n,int matrixA[n][n],int matrixB[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(uporediDvijeVrste(n,matrixA,i,matrixB,j)){
                printf("vrste : %d %d\n",i,j);
            }
        }
    }
}
void uporediSveKolone(int n,int matrixA[n][n],int matrixB[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(uporediDvijeKoloone(n,matrixA,i,matrixB,j)){
                printf("kolone : %d %d\n",i,j);
            }
        }
    }
}
int main(){
    int n = 4;
    printf("Prva matrica: \n");
    int matricA[n][n];
    loadMatrix(n,matricA);
    printf("Druga matrica: \n");
    int matricaB[n][n];
    loadMatrix(n,matricaB);
    uporediSveVrste(n,matricA,matricaB);
    uporediSveKolone(n,matricA,matricaB);
    return 0;
}

/*
Primer:
1. matrica 2. matrica
1 1 9 7     1 9 7 9
1 5 9 1     7 9 7 1
1 9 7 9     5 1 8 8
1 15 6 9    5 7 8 6

 1 1 9 7
1 5 9 1
1 9 7 9
1 15 6 9
Druga matrica:
1 9 7 9
7 9 7 1
5 1 8 8
5 7 8 6



 Ispis:
vrste 0 0
vrste 0 1
vrste 2 0
vrste 2 1
kolone 3 1
 */

