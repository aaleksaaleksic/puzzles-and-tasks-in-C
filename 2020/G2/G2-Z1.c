#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lijevi(int n,int i){
    int lijevi = 0;
    if(i % 2){
        lijevi = 'A' + i/2;
    }else{
        lijevi = 'A' + n - i/2;
    }
    printf("ITERACIJA : %d  LIJEVI : %c\n",i,lijevi);
    return lijevi;
}

int gornji(int n,int i){
    int gornji = 0;
    if(i <= n /2){
        gornji = n/2-i+1;
    }else{
        if(n % 2 == 1){
            gornji =  i - n / 2;
        }else{
            gornji =  i - n / 2 + 1;
        }
    }
    printf("ITERACIJA : %d  GORNJI : %d\n",i,gornji);
    return gornji;
}

double rek(int n,int i){
    if(i == n){
        return  lijevi(n,i);
    }else{
        return lijevi(n,i) + gornji(n,i) * 1.0 / rek(n,i+1);
    }
}

double iter(int n){
    double res = 'A' + n / 2.0;
    for(int i = n - 1; i >= 1;i--){
        res = lijevi(n,i) + gornji(n,i) * 1.0 / res;
    }
    return res;
}

int main() {
    int n;
    scanf("%d",&n);
    printf("Rekurzivno : %lf\n",rek(n,1));
    printf("Iterativno : %lf\n",iter(n));
    return 0;
}

