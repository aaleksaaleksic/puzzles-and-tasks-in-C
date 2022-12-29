//
// Created by Korisnik on 12/11/2022.
//
#include <stdio.h>
#include <math.h>

double rek(int i ,int upper,int n){

    if(i == n){
        return n;
    }
    if(i % 2)
        return i + upper / rek(i + 1,upper - 2, n);
    return i - upper / rek(i + 1, upper - 2, n);

}

double ite(int n){
    double sum = n;
    int upper = 2 * n;

    for(int i = 2; i < n; i++){
        upper -= 2;
    }
    for(int i = n - 1; i > 0; i--){
        if(i % 2)
            sum = i + upper / sum;
        else
            sum = i - upper / sum;
        upper += 2;
    }
    return sum;

}

int main(){
    int n;
    scanf("%d", &n);
    printf("[REK] %f\n",rek(1, 2 * n, n));
    printf("[ITE] %f\n",ite(n));

    return 0;
}
