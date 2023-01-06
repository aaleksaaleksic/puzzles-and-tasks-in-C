//
// Created by Korisnik on 1/5/2023.
//
#include <stdio.h>
#include <math.h>
int dole(int i,int n){
    if(i%2)
        return n / 3 + i - 1;
    return pow(i + 1,2);
}
int gore(int i){
    return i;
}
double rek(int i,int n){
    if(i == n){
        if(i % 2)
            return sqrt(1.0*gore(i)/ dole(i,n));
        return i * sqrt(1.0*gore(i)/ dole(i,n));
    }
    if(i % 2)
        return sqrt(1.0*gore(i) / dole(i,n) + rek(i + 1, n));
    return i * sqrt(1.0*gore(i) / dole(i,n) + rek(i + 1,n));

}
double ite(int n){
    double sum = (n % 2) ? sqrt(1.0*gore(n)/ dole(n,n)) : n * sqrt(1.0*gore(n)/ dole(n,n));
    for(int i = n - 1; i > 0; i--){
        if(i % 2)
            sum = sqrt(1.0*gore(i) / dole(i,n) + sum);
        else
            sum = i * sqrt(1.0*gore(i) / dole(i,n) + sum);
    }
    return sum;
}
int main(){
    int n;
    scanf("%d", &n);
//    for(int i = 1; i <= n; i++){
//        printf("%d\t",gore(i));
//    }
//    printf("\n");
//    for(int i = 1; i <= n; i++){
//        printf("%d\t",dole(i,n));
//    }
    printf("[REK] %f\n", rek(1,n));
    printf("[ITE] %f\n", ite(n));
    return 0;
}
