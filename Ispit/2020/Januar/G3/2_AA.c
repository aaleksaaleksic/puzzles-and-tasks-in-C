
#include <stdio.h>
#include <string.h>
/**
Unos: a:dfg b:drt a:ght g:ase g:zua
Ispis: a:dfght b:drt g:asezu
**/
int existing(char* str, char ch){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ch && str[i + 1] == ':')
            return 1;
    }
    return 0;
}

int main(){

    char str[100], novi[100];
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    str[strlen(str)] = ' ';

    char key; int novi_idx = 0;

    for(int i = 0; i < strlen(str); i++){
        if(str[i + 1] == ':' && !(existing(novi,str[i])) ){
            key = str[i];
            novi[novi_idx++] = str[i];
            novi[novi_idx++] = ':';
            for(int j = i; j < strlen(str); j++){
                if(str[j] == key && str[j + 1] == ':'){
                    for(int k = j + 2; str[k] != ' '; k++){
                        if(strchr(novi + novi_idx,str[k]) == NULL){
                            novi[novi_idx++] = str[k];
                        }
                    }

                }

            }
            novi[novi_idx++] = ' ';
        }

    }
    novi[novi_idx] = 0;
    fputs(novi,stdout);

    return 0;
}