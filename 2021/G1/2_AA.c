#include <stdio.h>
#include <stdlib.h>


int ugaoni_elementi(int x, int y, int dim, int mat[][100]) {
    int gl = mat[x][y];
    int gd = mat[x][y+dim-1];
    int dl = mat[x+dim-1][y];
    int dd = mat[x+dim-1][y+dim-1];

    for(int i = x; i < x + dim; i++) {
        for(int j = y; j < y + dim; j++) {
            if((i == x && j == y) || (i == x && j == y+dim-1) || (i == x+dim-1 && j == y) || (i == x+dim-1 && j == y+dim-1))
                continue;

            if(mat[i][j] == gl || mat[i][j] == gd || mat[i][j] == dl || mat[i][j] == dd)
                return 0;
        }
    }

    return 1;
}


int main() {
    int n, m;
    int mat[100][100];

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    for(int dim = 3; dim <= n && dim <= m; dim++) {
        for(int i = 0; i <= n - dim; i++) {
            for(int j = 0; j <= m - dim; j++) {
                if(ugaoni_elementi(i, j, dim, mat) == 1) {
                    printf("(%d, %d) dimenzija %dx%d\n", i, j, dim, dim);
                }
            }
        }
    }

    return 0;
}
/*
 * 4 6
1 2 3 4 1 3
3 1 4 1 5 9
2 4 1 7 6 8
5 5 3 1 9 2
 */