//
// Created by Korisnik on 1/16/2023.
//

#include <string.h>
#include <stdio.h>
/**
Unos: P: fcghtdcbacvbbbffa S: dcba
Ispis: cvbbbffa
**/
int isValid(int x,int y,char* p, char* s){
    int koord = strchr(s,p[x]) - s;
    for(int i = x; i <= y; i++){
        if(strchr(s,p[i])){ // u koliko se slovo pojavaljuje
            if(strchr(s,p[i]) - s == koord)
                continue; // naleteli smo na isto slovo kao pocetno
            if(strchr(s,p[i]) - s == koord + 1)
                koord++; // naisli smo na drugo slovo
            else
                return 0;

        }

    }
    return y - x + 1; // vraca dimenziju podstringa
}
int main(){
    char p[100],s[100];
    fgets(p,sizeof(p),stdin);
    fgets(s,sizeof(s),stdin);
    p[strlen(p) - 1] = 0;
    s[strlen(s) - 1] = 0;
    int koordP,koordK;
    int max = 0,temp;

    for(int i = 0; i < strlen(p); i++){
        for(int j = i + 1; j < strlen(p); j++){
            if(strchr(s,p[i]) && strchr(s,p[j])){ // imamo i pocetak i kraj podstringa u S
                temp = isValid(i,j,p,s);
                if(temp > max){
                    max = temp;
                    koordP = i;
                    koordK = j;
                }
            }
        }
    }
    for(int i = koordP; i <= koordK; i++){
        printf("%c",p[i]);
    }

}
