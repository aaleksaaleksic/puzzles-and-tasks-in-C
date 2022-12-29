//
// Created by Korisnik on 12/29/2022.
//

#include <stdio.h>
#include <math.h>
#include <limits.h>
int p(int n){
    return pow(n,2);
}

int fib(int x){
    if(x == 1 ||x == 2)
        return 1;
    int count = 2;
    int prethodni = 1;
    int trenutni = 1;
    int fibonaci;
    for(int i = 0; i < x*2; i++){
        fibonaci = trenutni + prethodni;
        prethodni = trenutni;
        trenutni = fibonaci;
        count++;
        if(count == x)
            return fibonaci;
    }
    return 0;
}
int mnoz(int i){
    return fib(i);
}
double rek(int n,int i){
    if(n == 1){
        return fib(i) * sqrt(n);
    }
    return fib(i) * sqrt(p(n) + rek(n - 1, i + 1));
}
double ite(int n){
    double sum = mnoz(n) * sqrt(1);
    int cnt = 2;
    for(int i = n - 1; i > 0; i--){
        sum = fib(i) * sqrt(p(cnt) + sum);
        cnt++;
    }
    return sum;
}

int main(){


    int n;
    scanf("%d",&n);
    printf("%f\n", rek(n,1));
    printf("%f\n", ite(n));



    return 0;
}
