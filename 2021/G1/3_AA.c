
#include <stdio.h>
#include <string.h>
/**
Ulaz:

pravac jug jugozapad moj zdrav zivot moja pravila

Izlaz:
pravac zdrav
pravac pravila
jug jugozapad
moj moja
zdrav pravila
 */

int provera(char* rec1, char* rec2){
    int len1 = strlen(rec1);
    int len2 = strlen(rec2);

    for(int i = 0; i < len1; i++){
        int idx = i;
        int cnt = 0;
        for(int j = 0; j < len2 && idx < len1; j++){
            if(rec1[idx] == rec2[j]){
                idx++;
                cnt++;
            }
            else{
                if(cnt > 2)
                    return 1;
            }
        }
        if(cnt > 2)
            return 1;
    }
    return 0;

}

int main(){

    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    char* token;
    char reci[50][50];
    int index = 0;

    token = strtok(str," ");
    while(token){
        strcpy(reci[index++],token);
        token = strtok(NULL," ");
    }
    for(int i = 0; i < index - 1; i++){
        for(int j = i + 1; j < index; j++){
            if(provera(reci[i], reci[j])){
                printf("%s  %s\n",reci[i],reci[j]);
            }
        }
    }

    return 0;
}
