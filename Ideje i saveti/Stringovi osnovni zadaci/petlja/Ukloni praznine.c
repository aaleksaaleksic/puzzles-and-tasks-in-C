//
// Created by Korisnik on 1/10/2023.
//
#include <stdio.h>
#include <string.h>
#define MAX 100

void moveLeft(int p, char* s){
    int n = strlen(s);
    for(int i = p; i < n - 1; i++){
        s[i] = s[i + 1];
    }
    s[n - 1] = 0;
}
void izbaciPraznine(char* s){
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        if(s[i] == ' ')
            moveLeft(i,s);
    }

}


int main(){

    char s[MAX];
    fgets(s,MAX,stdin);
    int n = strlen(s);
    s[n - 1] = 0;

    izbaciPraznine(s);

    fputs(s,stdout);

    return 0;
}
