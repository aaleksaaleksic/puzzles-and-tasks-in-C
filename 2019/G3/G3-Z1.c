#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rek(int n, double veci, double manji, int iteracija){
    if(iteracija == n-1){
        if(iteracija%2 == 0)
            return sqrt(pow(veci, iteracija%(n/2) + 1)/manji);
        else
            return sqrt(manji/pow(veci, iteracija%(n/2) + 1));
    }
    if(iteracija % 2 == 0)
        return sqrt(pow(veci, iteracija%(n/2)+1)/manji + rek(n, veci-1, manji-1, iteracija+1));
    else
        return sqrt(manji/pow(veci, iteracija%(n/2)+1) + rek(n, veci-1, manji-1, iteracija+1));
}

double ite(int n){
    double manji = 1, veci = n, res = 0;
    for(int i = n-1; i>=0; i--){
        if(i%2 != 0)
            res = sqrt(manji/pow(veci, i%(n/2)+1) + res);
        else
            res = sqrt(pow(veci, i%(n/2)+1)/manji + res);
        veci++;
        manji++;
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%lf %lf", rek(n, n*2-1, n, 0), ite(n));
    return 0;
}
