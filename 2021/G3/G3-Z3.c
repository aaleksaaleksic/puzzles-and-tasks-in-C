#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



void increaseString(char* str, int p, int k){
    //za pronalazak indeks pozicije unutar podstringa koji zapravo gledamo samo iz orginalnog stringa
    for(int i = p; i < k; i++){
        int razL = i - p + 1;
        int razD = k - i;
        int raz = razL < razD? razL : razD;
        int broj = str[i] - '0' + raz;
        broj %= 10;
        str[i] = broj + '0';

    }
}


//unos 4385 53913 335
//rez 5506 65234 456
int main(){
    char str[255];
    fgets(str,255,stdin);
    int n = strlen(str);
    str[n-1] = 0;
    n = strlen(str);
    int start = 0;
    int end;
    for(int i = 0; i < n; i++){
        if(str[i] == ' '){
            increaseString(str,start,i);
            start = i+1;
        }
    }
    increaseString(str,start,n);
    fputs(str,stdout);
    return 0;
}
