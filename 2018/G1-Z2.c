#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(){
     int n;
    scanf("%d",&n);
    printf("UNETO\n");

    int mat[n][n];
    int max_elem = INT_MIN;
    ///prolazimo krzo matricu da bi nasli najveci broj
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
            if(mat[i][j] > max_elem){
                max_elem = mat[i][j];
            }
        }
    }
    ///inicijalizujemo mapu
    int mapa[max_elem+1];   ///gledaj ovo kao da je HashMapa ali sacinjena samo od niza, key je index, val je broj na indeksu
    for(int i = 0; i < max_elem;i++){
        mapa[i] = 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mapa[mat[i][j]]++; /// zezanje sa mapom "Ovo je malo konfuzna linija"
        }
        ///za pronalazak neparnih
        for(int k = max_elem; k >= 0; k--){
            if(k % 2 != 0 && mapa[k] > 0){
                printf("red %d: broj: %d, ponavljanja: %d \n",i,k,mapa[k]);
                break;
            }
        }
        for(int z = 0; z <= max_elem; z++){
            mapa[z] = 0;
        }
    }
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            mapa[mat[i][j]]++;
        }
        for(int g = 1; g < max_elem;g++){
            if(g % 2 == 0 && mapa[g] > 0){
                printf("kolona %d: broj: %d , ponavljanja : %d\n",j,g,mapa[g]);
                break;
            }
        }
        for(int f = 0; f < max_elem;f++){
            mapa[f] = 0;
        }
    }
    return 0;
}

/*4
2 2 13 13
5 1 7 19
0 3 1 3
1 2 3 4
*/

