//
// Created by Korisnik on 1/9/2023.
//
#include <stdio.h>
#include <string.h>
#define MAX 100

void toLower(char* s){
    while(*s){
        if(*s >= 'A' && *s <= 'Z')
            *s += 32;
        s++;
    }
}
void toUpper(char* c){
    while(*c){
        if(*c >= 'a' && *c <= 'z')
            *c -= 32;
        c++;
    }
}

int main(){

    char s[MAX];
    fgets(s,MAX,stdin);
    int n = strlen(s);
    s[n - 1] = '\0';  // obavezno umesto entera staviti 0 da bi program registrovao pravi broj karatkera

    printf("Standardno: ");
    fputs(s,stdout);
    printf("\n");
    printf("Mala slova: ");
    toLower(s);
    fputs(s,stdout);
    printf("\n");
    printf("Velika slova: ");
    toUpper(s);
    fputs(s,stdout);
    printf("\n");
    printf(" Strtok: \n");
    char* token = strtok(s," ");
    while(token){
        fputs(token,stdout);
        printf("\n");
        token = strtok(NULL," ");
    }



    return 0;
}
