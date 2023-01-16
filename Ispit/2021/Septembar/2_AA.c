//
// Created by Korisnik on 1/16/2023.
//
#include <stdio.h>
#include <string.h>
/**
Unos: acdj"knaan"nhn"prcf"ak"dfffs"j
Ispis: acdj"naan"nhn""ak"fff"j
**/
int counter(char* str, char slovo, int index){
    int counter = 0;
    for(int i = index; str[i] != '\"'; i++){
        counter = (str[i] == slovo) ? counter + 1 : counter;
    }
    return counter;
}
int main(){

    char str[100],novi[100]; // kada pravis novi string treba ti index za novi string tj neka promenljiva int za index
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;

    novi[0] = 0;
    int novi_idx = 0;
    int flag = 0;
    int navodnici_idx;

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '\"'){
            novi[novi_idx++] = str[i];
            flag++;
            flag %= 2; // ne brinem vise da li je 0 ili 1 sa ovim, vec svaki put kada ga inkrementiram modujem ga
            navodnici_idx = (flag) ? i + 1 : -1; // namestamo index na prvo slovo posle navodnika
            continue;
        }
        if(flag){
            if(counter(str,str[i],navodnici_idx) > 1){
                novi[novi_idx++] = str[i];
            }
        }
        else
            novi[novi_idx++] = str[i];
    }

    fputs(novi,stdout);
/*
 Kod ovakvog tipa zadatka, neka ideja za kod bi bila da pamtis indeks za deo stringa koji ispitujes
 i da pomocnoj funkciji kasnije mozes da prosledis taj indeks... Kada ti trazi da kreiras novi string
 obicno bi bilo najbolje da kroz uslove lepo pokrijes sve slucajeve kada dodajes karakter u novi string, a ove gde
 ne dodajes ignorises...Znaci razmisljaj linearno a ne na hiljadu strana od jednom... Polako, sve moze da se uradi

 * */

    return 0;
}
