//  (II Kolokvijum 2018. Grupa: 4; Zadatak: 3;)
//  Napisati program koji učitava string koji sadrži reči razdvojene spejsom i od njega pravi novi string
//  koji sadrži samo reči koje se ponavljaju u unetom stringu (pojavljuju se u unetom stringu više od jednom).
///  Primer: prvi drugi prvi treci drugi
///  Rezultat: prvi drugi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main()
{
    char str[100],novi[100];
    novi[0] = 0;
    fgets(str,sizeof(str),stdin);
    str[(strlen(str) - 1)] = 0;

    char* token = strtok(str," "); // token pokazuje na mesto pocetka podstringa u VELIKOM STRINGU i to koristi majmune
     while(token){
         if(!strstr(novi,token) && strstr(token + strlen(token) + 1,token)){
             strcat(novi,token);
             strcat(novi," ");
         }
         token = strtok(NULL," ");
     }
    fputs(novi,stdout);

    return 0;
}