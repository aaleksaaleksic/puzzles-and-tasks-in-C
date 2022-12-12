//
// Created by Korisnik on 12/12/2022.
//
#include <stdio.h>
#include <math.h>

double rek(int i,int x, int y,int n){

    if(i == n)
        return x;
    return x + y / rek(i + 1, x + i, y - 11, n);
}

double ite(int n){
    int x = n;

    for(int i = 1; i < n; i++){
        x += i;
    }

    double sum = x;
    x -= n - 1;
    int y = n * 10 + (n-1);

    for(int i = 2; i < n; i++){
        y -= 11;
    }

    for(int i = n - 1; i >= 1; i--){
        sum = x + y / sum;
        x -= i - 1;
        y += 11;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);

    printf("[REK]  %f\n", rek(1,n,n * 10 + (n-1),n));
    printf("[INT]  %f\n", ite(n));

}