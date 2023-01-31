#include <stdio.h>

/**
broj: 447

matrica:
1 4 9 1
4 7 1 4
2 3 4 2
7 4 1 4

ispis:
vrste 1 3
kolone 1
**/


/// ako proveravam cifre sa ponovaljanjima po kolnama i nizovima mogu da imam niz kontejner koji cu da punim
/// ciframa niza ili kolone koji proveravam i sa nizom cifara koje se sadrze mogu zajedno da ih prosledim funkciji
/// i da se krecem samo kroz ta dva niza i ako postujem broj pojavljivanja mnogo bolja opcija od flagova je
/// da poklapanja popunim tj. zamenim sa -1 da se ne bi kasnije poklopilo da se procita ista cifra dva puta
void inputMatrix(int mat[100][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}


void proveriVrstu(int mat[100][100],int ii, int n,int kontejner[50], int index, int cifre[50]){
    int cnt = 0;
    for(int k = 0; k < index; k++){
        for(int j = 0; j < n; j++){
            if(kontejner[j] == cifre[k]){
                cnt++;
                kontejner[j] = -1; // popunjavamo da smo posetili jer postujemo ponavljanja
            }
        }
    }
    if(cnt == index)
        printf("%d ",ii);
    return;
}

void proveriKolonu(int mat[100][100], int jj,int n, int kontejner[100], int index, int cifre[100]){
    int cnt = 0;
    for(int k = 0; k < index; k++){
        for(int i = 0; i < n; i++){
            if(cifre[k] == kontejner[i]){
                cnt++;
                kontejner[i] = -1; // popunjavamo da smo posetili jer postujemo ponavljanja
            }
        }
    }
    if(cnt == index){
        printf("%d ",jj);
    }
    return;
}


int main(){
    int n;
    scanf("%d",&n);
    int mat[100][100];
    inputMatrix(mat,n);
    printf("Unesite broj: ");
    int broj = 0;
    scanf("%d",&broj);

    int cifre[100];
    int index = 0;
    while(broj > 0){
        cifre[index++] = broj % 10;
        broj /= 10;
    }
    int kontejner[n];
    printf("Vrste: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            kontejner[j] = mat[i][j];
        }
        proveriVrstu(mat,i,n,kontejner,index,cifre);
    }
    printf("\nKolone: ");
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            kontejner[i] = mat[i][j];
        }
        proveriKolonu(mat,j,n,kontejner,index,cifre);
    }

    return 0;
}
