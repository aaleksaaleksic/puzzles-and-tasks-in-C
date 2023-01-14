#include <stdio.h>
/**
n = 6;

3 4 3 4 7 5
2 4 2 5 5 4
1 3 4 1 6 1
1 2 3 1 5 2
2 3 1 4 5 5
1 4 5 1 2 3
**/
void inputMatrix(int n,int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void outputMatrix(int n, int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int mat[100][100];
    inputMatrix(n,mat);
    int g = 0,d = n - 1;
    int max = -1;
    int cnt = 0;
    while(cnt < n/2){ // prstenova uvek ima n/2
        for(int i = g,j = g; j <= d; j++ ){
            if(mat[i][j] > max)
                max = mat[i][j];
        }
        for(int i = g,j = d; i <= d; i++ ){
            if(mat[i][j] > max)
                max = mat[i][j];
        }
        for(int i = d,j = d; j >= g; j-- ){
            if(mat[i][j] > max)
                max = mat[i][j];
        }
        for(int i = d,j = g; i >= g; i-- ){
            if(mat[i][j] > max)
                max = mat[i][j];
        }
        // sad cemo da ispisemo maksimum na sva mesta
        for(int i = g,j = g; j <= d; j++ ){
            mat[i][j] = max;
        }
        for(int i = g,j = d; i <= d; i++ ){
            mat[i][j] = max;
        }
        for(int i = d,j = d; j >= g; j-- ){
            mat[i][j] = max;
        }
        for(int i = d,j = g; i >= g; i-- ){
            mat[i][j] = max;
        }
        cnt++;
        g++;
        d--;
        max = -1;

    }
    outputMatrix(n,mat);
    return 0;
}