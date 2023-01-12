#include <stdio.h>
#include <string.h>
#define MAX 1000
/*
Primer: abba-affg-ccc-fgh
Rezultat: ab-afg-c-fgh
 */

int main(){

    char s1[MAX];
    char s2[MAX];
    int idx = 0;
    fgets(s1,MAX,stdin);
    int pocetak = 0, kraj = 0;

    for(int i = 0; i < strlen(s1); i++){
        if(i == 0 || (s1[i - 1] == '-' && s1[i] != '-'))
            pocetak = i;
        if(s1[i] == '\n' || (s1[i] == '-' && s1[i - 1] != '-')){
            kraj = i;
            int niz[26] = {0}; // niz intova od sa 26 mesta gde ce biti 0 i 1 koji ce oznacavati da li se slovo
            //pojavilo tj, na tom indeksu ce biti 1
            for(int f = pocetak; f < kraj; f++){
                if(niz[s1[f] - 97] == 0){
                    s2[idx++] = s1[f];
                }
                niz[s1[f] - 97]++;
            }
            s2[idx++] = '-';
        }

    }
    s2[idx - 1] = 0;
    fputs(s2,stdout);

    return 0;
}
