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
    int broj;
    scanf("%d", &broj);
    int n = brojCifara(broj);
    int mat[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                mat[i][j] = (int)(broj / pow(10,i)) % 10;
                continue;
            }
            if(i + j == n - 1){
                mat[i][j] = (int)(broj / pow(10,n - 1 - i)) % 10;
                continue;
            }

        }
    }
    int dijagonala;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j && i + j == n - 1)
                continue;
            if((i > j && i + j < n - 1) || (i < j && i + j > n - 1)){
                dijagonala = mat[j][j];
                mat[i][j] = (dijagonala + 1) % 10;
                continue;
            }
            if((j > i && i + j < n - 1) || (i > j && i + j > n - 1)){
                dijagonala = mat[j][j];
                mat[i][j] = dijagonala - 1;
                if(mat[i][j] < 0)
                    mat[i][j] = 9;
                continue;
            }

        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }





    return 0;
}