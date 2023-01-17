#include <stdio.h>
#include <string.h>

/**
Unos: 2:adfh 1:ijjklll 4:op 2:fghi 1:jk
Ispis: 2:adffghhi 1:ijjjkk 4:op
**/
void sortiraj(char* str){
    for(int i = 2; i < strlen(str) - 1; i++){
        for(int j = i + 1; j < strlen(str); j++){
            if(str[i] > str[j]){
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}
int cifra(char c){
    return (c >= '0' && c <= '9') ? 1 : 0;
}
int main(){
    char str[100],novi[100];
    fgets(str,sizeof(str),stdin);

    strcat(str," ");
    int len = strlen(str) - 10;
    char kljuc;
    int novi_idx = 0;

    for(int i = 0; i < len; i++){
        if(cifra(str[i]) && (strchr(novi,str[i]) == NULL)){
            kljuc = str[i];
            novi[novi_idx++] = kljuc;
            novi[novi_idx++] = ':';
            for(int j = i; j < len; j++){
                if(str[j] == kljuc){
                    for(int k = j + 2; str[k] != ' ';k++){
                        novi[novi_idx++] = str[k];
                    }
                }
            }
            novi[novi_idx++] = ' ';
        }
    }
    novi[novi_idx] = 0;
    str[0] = 0;

    char* token = strtok(novi," ");
    while(token){
        sortiraj(token);
        strcat(str,token);
        strcat(str," ");
        token = strtok(NULL," ");
    }
    fputs(str,stdout);

    return 0;
}