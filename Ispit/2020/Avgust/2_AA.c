#include <stdio.h>
#include <string.h>
/**
Unos: abccghj ujh hkllm weertz
Ispis: abccba jhgccghj hkllkh mllm weew ztreertz
 */
void zavrniGa(char* token,char* novi, int* index){ // sa strtokom
    int trebaZavrtanje = 0;
    int koordinata;
    for(int i = 0; i < strlen(token); i++){
        if(token[i] == token[i + 1]){
            trebaZavrtanje = 1;
            koordinata = i;
        }
    }
    if(trebaZavrtanje){
        for(int i = 0; i <= koordinata; i++){
            novi[(*index)++] = token[i];
        }
        for(int i = koordinata; i >= 0; i--){
            novi[(*index)++] = token[i];
        }
        novi[(*index)++] = ' ';

        for(int i = strlen(token) - 1; i > koordinata; i--){
            novi[(*index)++] = token[i];
        }
        for(int i = koordinata + 1; i < strlen(token); i++){
            novi[(*index)++] = token[i];
        }
        novi[(*index)++] = ' ';
    }
}
void zavrniGa2(char* str,int pocetak,int kraj,char* novi, int* index){ // bez strtoka
    int trebaZavrtanje = 0; // ovim proveravamo da li uopste treba da se okrece rec
    int koordinata;
    for(int i = pocetak; i <= kraj; i++){ // pronalazimo kordinatu ponavljanja slova
        if(str[i] == str[i + 1]){
            trebaZavrtanje = 1;
            koordinata = i;
        }
    }
    if(trebaZavrtanje){
        for(int i = pocetak; i <= koordinata; i++){
            novi[(*index)++] = str[i];
        }
        for(int i = koordinata; i >= pocetak; i--){
            novi[(*index)++] = str[i];
        }
        novi[(*index)++] = ' ';

        for(int i = kraj; i > koordinata; i--){
            novi[(*index)++] = str[i];
        }
        for(int i = koordinata + 1; i <= kraj; i++){
            novi[(*index)++] = str[i];
        }
        novi[(*index)++] = ' ';
    }
}
int main(){

    char str[100],novi[100];
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    int novi_idx = 0; // u funkciju kada popunjavamo novi string prosledimo pokazivac na brojac
    // jer cemo tako dinamicki pamtiti gde smo stali cak iako je ++ -- van "main-a"
    int pocetak,kraj;

    for(int i = 0; i < strlen(str); i++){
        if(i == 0 || str[i - 1] == ' ')
            pocetak = i;
        if(str[i + 1] == ' ' || i == strlen(str) - 1){
            kraj = i;
            zavrniGa2(str,pocetak,kraj,novi,&novi_idx);
        }
    }


//    char* token = strtok(str," ");
//    while(token){
//        zavrniGa(token,novi,&novi_idx);
//        token = strtok(NULL," ");
//    }
    novi[novi_idx] = 0;
    fputs(novi,stdout);


    return 0;
}