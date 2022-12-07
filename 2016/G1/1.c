#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double rek(int n, int br){
    if(n == 1)
        return sqrt((double)br/n);
    if(br == 2)
        return sqrt((double)br / n + rek(n - 1, 1));
    return sqrt((double)br / n + rek(n - 1,2));

}

double ite(int n){

    int br = (n % 2) ? 1 : 2;
    double sum = sqrt((double)br);
    br = (br == 1) ? 2 : 1;
    for(int i = 2; i <= n; i++){

        sum = sqrt((double)br / i + sum);
        br = (br == 1) ? 2 : 1;
    }
    return sum;

}


int main()
{
    int n;
    scanf("%d", &n);
    printf("[REK]       %f\n",rek(n,1));
    printf("[ITE]       %f\n",ite(n));
    return 0;
}
