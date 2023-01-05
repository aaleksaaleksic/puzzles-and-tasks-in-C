//
// Created by Korisnik on 1/5/2023.
//
#include <stdio.h>
int slovo(int i,int n){
    if(i % 2)
        return 65 + i / 2;
    return 65 + n - i / 2;
}
int broj(int i, int n){
    if(!(n % 2)){
        if(i < n / 2)
            return n / 2 + 1 - i;
        return i - n/2 + 1;
    }
    else{
        if(i <= n / 2)
            return n / 2 + 1 - i;
        else if(i == n/2 + 1)
            n / 2 + 1 - i - 1;
        return i - n/2;
    }

    }

double rek(int i, int n){
    if(i == n)
        return slovo(i,n);
    return slovo(i,n) + broj(i,n) / rek(i + 1,n);
}
double ite(int n){
    double sum = slovo(n,n);
    for(int i = n -1; i > 0; i--){
        sum = slovo(i,n) + broj(i,n) / sum;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
//    for(int i = 1; i < n; i++){
//        printf("%d\t", broj(i,n));
//    }
    printf("[REK] %f\n", rek(1,n));
    printf("[ITE] %f\n", ite(n));
    return 0;
}
