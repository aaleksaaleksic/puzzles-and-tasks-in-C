
#include <stdio.h>
#include <string.h>

// preradicemo manji string S tako sto cemo u njemu da ostavimo samo slova koja se pojavljuju i u P

/**
Unos: P: aefughckl S: cdea
Ispis: cefughakl
**/

void modifikuj(char* p, char* s){ // funkcija za izbacivanje svih slova koja se ne pojavljuju u stringu p
    int idx_s = 0;
    for(int i = 0; i < strlen(s); i++){
        if(strchr(p,s[i]))
            s[idx_s++] = s[i];
    }
    s[idx_s] = 0;
}
int main(){

    char s[100],p[100];
    fgets(p,sizeof(s),stdin);
    fgets(s,sizeof(p),stdin);
    p[strlen(p) - 1] = 0;
    s[strlen(s) - 1] = 0;
    modifikuj(p,s); // izbacujemo iz stringa s sva slova koja nisu u p

    // sad cemo da idemo kroz duzi string i da kad god naletimo na slovo koje se pojavljuje
    // i u s menjamo ga sa prvim sledecim u s, jer smo tamo izbacili sav visak i sve je redom
    int idx_s =0;
    for(int i = 0; i < strlen(p); i++){
        if(strchr(s,p[i]))
            p[i] = s[idx_s++];
    }

    fputs(p,stdout);

    return 0;
}