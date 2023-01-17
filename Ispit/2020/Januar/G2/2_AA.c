#include <stdio.h>
#include <string.h>

/**
Unos: [adf] {bmno} {mm} {nm} (jkl) [dv]
Ispis: [addfv] {bmmmno} (jkl)
**/
void sortiraj(char* str){ // uz strTok
    for(int i = 1; i < strlen(str) - 2; i++){ // izbegavamo da zahvatimo indekse zagrada 0 i n - 1
        for(int j = i + 1; j < strlen(str) - 1; j++){
            if(str[i] > str[j]){
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}
void sortiraj1(int pocetak,int kraj, char* str){ // bez strtoka
    for(int i = pocetak; i <= kraj - 1; i++){
        for(int j = i + 1; j <= kraj; j++){
            if(str[i] > str[j]){
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}
int main(){
    char str[100],novi[100];

    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    strcat(str," "); // dodajemo spejs zbog uslova dole

    int novi_idx = 0;
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if((str[i] == '(' || str[i] == '{' || str[i] == '[') && strchr(novi,str[i]) == NULL){
            //ako naletim na zagradu koja prvi put pojavljuje u novom stringu
            novi[novi_idx++] = str[i];
            for(int j = i; j < len; j++){ // od tog mesta krecem i do kraja stringa trazim karaktere
                // cije su pocetne zagrade iste
                if(str[j] == str[i]){
                    for(int k = j + 1; str[k + 1] != ' '; k++)
                        novi[novi_idx++] = str[k];
                }
            }
            // sad sa kojom zagradom smo u if-u gornjem radili, tom sad i zatvaramo
            if(str[i] == '(')
                novi[novi_idx++] = ')';
            else if(str[i] == '{')
                novi[novi_idx++] = '}';
            else
                novi[novi_idx++] = ']';

            novi[novi_idx++] = ' '; // i razdvajamo spejsom
        }
    }
    novi[novi_idx] = 0;
    str[0] = 0;
    int pocetak,kraj;

    for(int i = 0; i < novi_idx; i++){
        if(novi[i] == '(' || novi[i] == '{' || novi[i] == '['){
            pocetak = i + 1;
            for(int j = i; novi[j] != ' ';j++){
                kraj = i - 1;
            }
            sortiraj1(pocetak,kraj,novi);

        }
    }

//// STRTOK VERZIJA

//    char* token = strtok(novi," ");
//    while(token){
//        sortiraj(token);
//        strcat(str,token);
//        strcat(str," ");
//        token = strtok(NULL," ");
//    }
    fputs(novi,stdout);

    return 0;
}
