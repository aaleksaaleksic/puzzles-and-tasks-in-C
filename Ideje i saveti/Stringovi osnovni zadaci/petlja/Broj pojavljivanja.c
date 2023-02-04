#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
    Funkcija strstr(char *str1, char *str2) uzima 2 stringa, kao argumente i kao povratnu vrednost
    vraca pokazivac na prvo pojavljivanje str2 u str1.

    Primer:
        str1 = "Danas je jako lep dan"
        str2 = "jako"

        strstr(str1, str2) -> povratna vrednost bice: "jako lep dan"
        vracen je pokazivac na prvo pojavljivanje str2 u str1
*/


int main() {
    char s1[100];
    char s2[20];

    fgets(s1, 100, stdin);
    fgets(s2, 20, stdin);

    s1[strlen(s1) - 1] = '\0';
    s2[strlen(s2) - 1] = '\0';

    char *p = s1;
    int cnt = 0;
    while((p = strstr(p, s2)) != NULL) {
        cnt++;
        p = p + strlen(s2);  //na ovaj nacin preskacemo rec s2, na koju smo dobili pokazivac
    }

    printf("%d\n", cnt);
    return 0;
}