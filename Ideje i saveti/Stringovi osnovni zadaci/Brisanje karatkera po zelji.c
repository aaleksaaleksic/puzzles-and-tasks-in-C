//
// Created by Korisnik on 1/9/2023.
//
#include <stdio.h>
#include <string.h>
#define MAX 100

void moveLeft(char* s, int p){
    int n = strlen(s);
    for(int i = p; i < n - 1; i++){
        s[i] = s[i + 1]; // da ne bi automatski pomerili 0 na poslednji karatker idemo u petlji do n - 1 jer je formula za i + 1 sto
        // znaci da je poslednji karatker dokle moze da se dodje n - 2 sto zapravo i hocemo
    }
    s[n - 1]  = '\0';
}

void ukloniKarakter(char* s, char c){

    int n = strlen(s);
    for(int i = 0; s[i] != 0; i++){
        if(s[i] == c){
            moveLeft(s,i);
        }
    }
}


int main(){

    char s[MAX];
    fgets(s,MAX,stdin);
    char ch;
    scanf("%c",&ch);
    int n = strlen(s);
    s[n - 1] = '\0';
    ukloniKarakter(s,ch);
    fputs(s,stdout);





    return 0;
}

