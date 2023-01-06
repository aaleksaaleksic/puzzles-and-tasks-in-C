//
// Created by Korisnik on 1/6/2023.
//

#include <stdio.h>
#include <math.h>

int gore(int i, int n){
    if(i < n/2)
        return n - i;
    else if(!(i % 2) && i == n/2)
        return n - i + 1;
    else
        return i + 1;
}
int dole(int i){
    return pow(i + 1,2);
}
double rek(int i,int n){
    if(i + 1 == n)
        return sqrt(1.0 * gore(i,n) / dole(i));
    return sqrt(1.0 * gore(i,n) / dole(i) + rek(i + 1,n));
}
double ite(int n){
    double sum = sqrt(gore(n - 1,n)/dole(n - 1));
    for(int i = n - 1; i >= 0; i--){
        sum = sqrt(1.0 * gore(i,n) / dole(i) + sum);
    }
    return sum;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("[REK] %f\n", rek(0,n));
    printf("[ITE] %f\n", ite(n));
    return 0;
}