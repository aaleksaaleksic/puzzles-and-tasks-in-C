//
// Created by Korisnik on 12/29/2022.
//
#include <stdio.h>
#include <limits.h>
int fib(int x){
    if(x == 1 || x == 2){
        return 1;
    }
    int count = 2;
    int prethodni = 1;
    int sledeci = 1;
    int fibonacci;
    for(int i = 0; i < INT_MAX; i++){
        fibonacci = prethodni + sledeci;
        prethodni = sledeci;
        sledeci = fibonacci;
        count++;
        if(count == x)
            return fibonacci;

    }

}
int slovo(int i,int n){
    if(i < n/2)
        return 97 + n/2 - i;
    else{
        return 97 + n - i ;
    }
}
double znak(int i){
    return (i%2)?1:-1;
}
double rek(int i, int n){
    if(i == n)
        return slovo(i,n);
    return slovo(i,n) + znak(i) * fib(i) / rek(i + 1,n);
}
double ite(int n){
    double sum = slovo(n,n);
    for(int i = n - 1; i > 0; i--){
        sum = slovo(i,n) + fib(i) / sum;
    }
    return  sum;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%f\n", rek(1,n));
    printf("%f\n", ite(n));


    return 0;
}