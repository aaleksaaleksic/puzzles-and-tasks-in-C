#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
 Mojne štekaš sе u odbrani jebeš James Hardena
Ko igra protiv Grubija, neće videti poena
Dok svi trče u napad, ja ostaću u odbrani
Ludaci kao ja i na basketu su golmani
Sa klupe ortaci viču "Bravo Grubi Rodmane
Na kraju sezone bićeš Branko Lazić godine"
Cepam teretanu ne mogu pogodim vola
I sa slobodnog bacanja ja bacim air ball-a
Al sam tata defanzive, Mirosavljević Draganče
 */

int stepen(int a, int b){
    int x = b;
    int res = 1;
    while(x){
        res *= a;
        x--;
    }
    return res;
}

int gornji(int n, int iteracija){
    int gornji;
    if(iteracija % 2){
        gornji = (iteracija <= n/2)? stepen(2 * n - iteracija,iteracija) : stepen(2 * n - iteracija,(iteracija - n / 2) % (n/2));
    }else{
        gornji = n - iteracija + 1;
    }
    printf("ITERACIJA : %d, GORNJI : %d \n",iteracija ,gornji);
    return gornji;
}
int donji(int n, int iteracija){
    int donji;
    if(iteracija % 2){
        donji = n - iteracija + 1;
    }else{
        donji = (iteracija <= n/2)? stepen(2 * n - iteracija,iteracija) : stepen(2 * n - iteracija,(iteracija - n / 2)  );
    }
    printf("ITERACIJA : %d, DONJI : %d \n",iteracija,donji);
    return donji;
}

double rek(int n, int i){
    if(i == n){
        return sqrt(gornji(n,i)*1.0/ donji(n,i));
    }
    return sqrt(gornji(n,i)*1.0/ donji(n,i) + (rek(n,i+1)));
}
double iter(int n){
    double res = sqrt(gornji(n,n)*1.0 / donji(n,n));
    for(int i = n - 1; i >= 1;i--){
        res = sqrt(gornji(n,i)*1.0/ donji(n,i)+res);
    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("{REKURZIVNO} %lf \n", rek(n,1));
    //printf("{ITERATIVNO} %lf \n", iter(n));
    return 0;
}
