#include <stdio.h>
#include <string.h>

/**
Primer: Recenice se Ne pisu ovakO
Rezultat: Recenice Ne ovakO
 */

void prepraviString(char *str,int start,int end){
        int len = end - start + 2;
        for(int i = start; i < strlen(str) - len; i++){
            str[i] = str[i + len];
        }
        str[strlen(str) - len] = 0;

}




int main(){

    char str[100];
    fgets(str,sizeof(str),stdin);

    str[strlen(str) - 1] = 0;
    int start,end;

    for(int i = 0; i < strlen(str); i++){
        if(i == 0 || str[i - 1] == ' '){
            start = i;
            continue;
        }
        if(i == strlen(str) - 1 || str[i + 1] == ' '){
            end = i;
            printf(" start %d  end %d\n",start,end);
            if(str[start] >= 'a' && str[start] <= 'z' && str[end] >= 'a' && str[end] <= 'z'){
                printf("rec pocinje i zavrsava se malim slovom\n");
                prepraviString(str,start,end);
            }
        }




        }


    fputs(str,stdout);





    return 0;
}