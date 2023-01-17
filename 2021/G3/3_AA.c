
#include <stdio.h>
#include <string.h>
/**

Primer: 4385 53913 335

Rezultat: 5506 65234 456


 */

void change(char* broj){
    int inkrement = 1;
    int n = strlen(broj);
    for(int i = 0; i < n / 2; i++){
        broj[i] = (((broj[i] - '0') + inkrement) % 10) + '0';
        broj[n - i - 1] = (((broj[n - i - 1] - '0') + inkrement) % 10) + '0';
        inkrement++;
    }
    if(n % 2 == 1)
        broj[n / 2] = (((broj[n / 2] - '0') + inkrement) % 10) + '0';
}

int main(){
    char str[100],novi[100];
    novi[0] = 0;
    fgets(str,sizeof(str),stdin);
    str[(strlen(str) - 1)] = 0;
    char* token;
    char brojevi[50][50];
    int idx = 0;

    token = strtok(str," ");

    while(token){
        strcpy(brojevi[idx++],token);
        token = strtok(NULL, " ");
    }
    for(int i = 0; i < idx; i++) {
        change(brojevi[i]);
        strcat(novi,brojevi[i]);
        strcat(novi," ");
    }
    fputs(novi,stdout);


    return 0;
}
