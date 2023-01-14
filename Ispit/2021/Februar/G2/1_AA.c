
#include <stdio.h>
/**
n = 4, m = 5
3 4 3 4 7
2 4 2 5 5
1 3 1 8 6
1 2 3 9 5

Ispis: (2,2) , dužina 7
**/
int validnaPozicija(int i,int j,int n,int m, int mat[100][100]){
    return i >= 0 && i < n && j >= 0 && j < m;
}
void inputMatrix(int n,int m,int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void outputMatrix(int n,int m, int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int mat[100][100];
    inputMatrix(n,m,mat);
    int tmpLen = 0, maxLen = 0;
    int prev = mat[n - 1][0];
    int koordX, koordY,maxKoordX, maxKoordY;
    for(int j = 0; j < m; j++){
        for(int i = n - 1; i >= 0; i--){
            if(mat[i][j] > prev && tmpLen == 0){
                koordX = i - 1;
                koordY = j;
                tmpLen++;
            }
            else if(mat[i][j] > prev && tmpLen != 0)
                tmpLen++;
            else{
                if(tmpLen > maxLen){
                    maxLen = tmpLen;
                    maxKoordX = koordX;
                    maxKoordY = koordY;
                    tmpLen = 0;
                }
            }
            prev = mat[i][j];


        }
        j++;
        for(int i = 0; i < n; i++){
            if(mat[i][j] > prev && tmpLen == 0){
                koordX = i;
                koordY = j;
                tmpLen++;
            }
            else if(mat[i][j] > prev && tmpLen != 0)
                tmpLen++;
            else{
                if(tmpLen > maxLen){
                    maxLen = tmpLen;
                    maxKoordX = koordX;
                    maxKoordY = koordY;
                    tmpLen = 0;
                }
            }
            prev = mat[i][j];

        }

    }
    printf("(%d,%d) duzina: %d \n", maxKoordX, maxKoordY, maxLen);

    return 0;
}
