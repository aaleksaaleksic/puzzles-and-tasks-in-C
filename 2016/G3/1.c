//
// Created by Korisnik on 12/8/2022.
//
#include <stdio.h>
#include <math.h>
#include <fenv.h>

//za n = 6 -------> 2.361303

double rek(int n,int i,int br){
    if (br == 0)
        br = n / 2;
    if(i == n)
        return sqrt(i * br);
    return sqrt(i * br + rek(n,i+1,br-1));
}
double ite(int n){
    int br = n / 2;

    for(int i = 1; i < n; i++){
        br--;
        if(br == 0)
            br = n / 2;
    }
    int mul = br + 1;
    double sum = sqrt(n * br);
    for(int i = n - 1; i > 0; i--){
        sum = sqrt(i * mul + sum);
        mul++;
        if(i == n /2 + 1){
            mul = 1;
        }

//        printf("usao");
    }



    return sum;

}

int main(){
    int x;
    scanf("%d",&x);

    printf("[REK]  %lf\n",rek(x,1,x/2));
    printf("[ITE]  %lf\n",ite(x));

}

