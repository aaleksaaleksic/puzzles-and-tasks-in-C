#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int brPonavljanja(char* str,char* ponavljanje){

    int len_str = strlen(str),len_ponavljanje = strlen(ponavljanje);
     char tmp[100];
     int brPon = 0, tmpIndex = 0;

     for(int i = 0; i < len_str;i++){
         if(str[i] == ' ' || str[i] == '\0'){
             tmp[tmpIndex] = '\0';
             if(strlen(tmp) == len_ponavljanje){
                 int ponavljanjeFlag = 1;
                 for(int j = 0; j < len_ponavljanje;j++){
                     if(tmp[j] != ponavljanje[j]) {
                         ponavljanjeFlag = 0;
                         break;
                     }
                 }
                 brPon+= ponavljanjeFlag;
             }
             tmpIndex = 0;
             continue;
         }
         tmp[tmpIndex++] = str[i];
     }
    return brPon;
}

//ispisati najucestaliju rijec i njen broj ponavljanja
int main(){
    char str[100],tmp[100];
    gets(str);
    int maxBrPonavljanja = 0;
    int trenutniBrPonavljanja;
    char maxPonavljanja[100];
    int len = strlen(str), tmpIndex = 0;
    for(int i = 0; i <= len; i++){
        if(str[i] == ' ' || str[i] == '\0'){
            tmp[tmpIndex] = '\0';
            trenutniBrPonavljanja = brPonavljanja(str,tmp);
            if(trenutniBrPonavljanja > maxBrPonavljanja){
                maxBrPonavljanja = trenutniBrPonavljanja;
                strcpy(maxPonavljanja,tmp);
            }
            tmpIndex = 0;
            continue;
        }
        tmp[tmpIndex++] = str[i];
    }
    printf("%s %d",maxPonavljanja,maxBrPonavljanja);
    return 0;
    //prvi drugi drugi prvi prvi prvi
}
