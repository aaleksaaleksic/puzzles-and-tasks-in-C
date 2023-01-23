#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void loadMatrix(int n,int matrix[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}
int zbirVrste(int n, int matrix[n][n], int vrsta){
    int zbir = 0;
    for(int i = 0; i < n; i++){
        zbir += matrix[vrsta][i];
    }
    return zbir;
}
int zbirKolone(int n, int matrix[n][n], int kolona){
    int zbir = 0;
    for(int i = 0; i < n; i++){
        zbir += matrix[i][kolona];
    }
    return zbir;
}
int vratiIndexMaxVrste(int n, int matrix[n][n]){
    int maxZbir = INT_MIN;
    int lokalniZbir = 0;
    int index ;
    for(int vrsta = 0; vrsta < n; vrsta++){
        lokalniZbir = zbirVrste(n,matrix,vrsta);
        if(lokalniZbir > maxZbir){
            maxZbir = lokalniZbir;
            index = vrsta;
        }
    }
    return index;
}
int vratiIndexMaxKolone(int n, int matrix[n][n]){
    int maxZbir = INT_MIN;
    int lokalniZbir = 0;
    int index ;
    for(int kolona = 0; kolona < n; kolona++){
        lokalniZbir = zbirKolone(n,matrix,kolona);
        if(lokalniZbir > maxZbir){
            maxZbir = lokalniZbir;
            index = kolona;
        }
    }
    return index;
}
void redPillNeo(int n, int array[n*n-(2*n-1)],int matrix[n][n]){
    int arrayIndex = 0;
    int indexMaxVrste = vratiIndexMaxVrste(n,matrix);
    int indexMaxKolone = vratiIndexMaxKolone(n,matrix);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == indexMaxVrste || j == indexMaxKolone){
                continue;
            }else{
                array[arrayIndex] = matrix[i][j];
                arrayIndex++;
            }
        }
    }
    printf("index max vrste : %d, index max kolone : %d\n",indexMaxVrste,indexMaxKolone);
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortArray(int n, int niz[n*n-(2*n-1)]){
    for(int i = 0; i < n*n-(2*n-1) -1 ; i++){
        for(int j = i +1 ; j < n*n-(2*n-1);j++){
            if(niz[i] > niz[j]){
                swap(&niz[i],&niz[j]);
            }
        }
    }
}
void bluePillNeo(int n, int niz[n*n-(2*n-1)], int matrix[n][n]){
    int arrayIndex = 0;
    int indexMaxVrste = vratiIndexMaxVrste(n,matrix);
    int indexMaxKolone = vratiIndexMaxKolone(n,matrix);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == indexMaxVrste || j == indexMaxKolone){
                continue;
            }else{
                matrix[i][j] = niz[arrayIndex];
                arrayIndex++;
            }
        }
    }
}
void newLine(){
    printf("\n");
}
void printArray(int n,int niz[n*n-(2*n-1)]){
    printf("Niz : ");
    for(int i = 0; i < n*n-(2*n-1);i++){
        printf(" %d ",niz[i]);
    }
    newLine();
}
void printMatrix(int n,int matrix[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    int niz[n*n-(2*n-1)];
    loadMatrix(n,matrix);
    newLine();
    redPillNeo(n,niz,matrix);
    printArray(n,niz);
    newLine();
    sortArray(n,niz);
    printArray(n,niz);
    newLine();
    bluePillNeo(n,niz,matrix);
    printMatrix(n,matrix);
    return 0;
}

/*
5
4 7 3 1 5
2 7 4 6 5
1 5 3 8 4
7 2 6 9 8
3 9 1 8 7
 *
 */



