#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
Unos: [a,b,c] [34,up,uup,34] [1,2] [1,2,1,4]
Ipsis: [a,b,c] [1,2]
**/

//Kod ovog zadatka je u pitanju provera da li se karakteri u zagradama ponavljaju... Pocetne i krajnje elemente zagrada razdvojimo u klasicne dve
//for petlje za start i end elemente i od starta do enda punimo neki string koji nam predstavlja zagradu... Kada izolujemo jednu zagradu, prosledjujemo
//tu zagradu dalje u funkciju gde vrsimo proveru ponavljanja... Takodje 2 stringa tu, jedan fiksiramo, tj prvi string bude pre prvog zareza,
//i onda njega proveravamo sa ostalima do kraja, i tako za svaki... Nesto poput sortiranja samo sa proverom... Voditi racuna o indeksima i resetovanju
//promenljivih i praznjenju pomocnih stringova na vreme

//Kod provere prva for petlja ide do pretposlednjeg elementa niza, dok unutrasnja ide do kraja, da bi se svaki sa svakim uporedio kako treba,
//a to nam je mnogo bitno

int isUnique(char* zagrada) {
    char str1[50], str2[50]; // jedan string razdvojen zarezom se poredi sta ostalima
    int index1 = 0, index2 = 0;
    int startni;
    for (int i = 0; i <= strlen(zagrada) - 1; i++) {
        if (zagrada[i] == ',') { // kad dodjemo da prvog zareza stavljamo kraj na prvi string i pocetni indeks od kog krece prvi sledeci
            str1[index1] = 0;
            index1 = 0;
            startni = i + 1;
            for (int j = startni; j <= strlen(zagrada); j++) {
                if (zagrada[j] == ',' || j == strlen(zagrada)) {
                    str2[index2] = 0;// kad dodjemo do prvog zareza u sledecom opet kraj na sledeci
//                    printf("str1 %s  str2 %s\n",str1,str2);
                    if (strcmp(str1, str2) == 0) // poredimo njih dvojicu
                        return 0;
                    str2[0] = 0;
                    index2 = 0;

                }
                else
                    str2[index2++] = zagrada[j];
            }
            str1[0] = 0;
        }
        else
            str1[index1++] = zagrada[i];
    }
    return 1;
}

int main(){

    char str[100];
    fgets(str,sizeof(str),stdin);
    str[(strlen(str) - 1)] = 0;
    char zagrada[100];
    int z_index = 0;

    for(int i = 0; i < strlen(str); i++){
        if(i == 0 || str[i - 1] == ' ' || str[i] == ' '){
            continue;
        }
        if(i == strlen(str) - 1 || str[i + 1] == ' '){
            zagrada[z_index] = 0;
            if(isUnique(zagrada) == 1){
                fputs(zagrada,stdout);
                putchar(' ');
            }
            z_index = 0;
            zagrada[0] = 0;
            continue;
        }
        zagrada[z_index++] = str[i];
    }


    return 0;
}
