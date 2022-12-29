//
// Created by Aleksa on 12/8/2022.
//
#include <stdio.h>
#include <math.h>


//za n =  ----> 6.187624

double rek(int n, double br){
    if(n == 1)
        return 1;
    if(br == sqrt(1))
        return n + br / rek(n - 1, sqrt(2));
    return n + br / rek(n - 1, sqrt(1));


}

double ite(int n){
    double res = 1;
    double br = (n % 2) ? sqrt(2) : sqrt(1);

    for(int i = 2; i <= n; i++){
        res = i + br / res;
        br = (br == sqrt(2)) ? sqrt(1) : sqrt(2);

    }
    return res;
}

 int main(){

    int n;
    scanf("%d", &n);
     printf("[REK] %f\n",rek(n,sqrt(1)));
     printf("[ITE] %f\n",ite(n));

    return 0;
}

