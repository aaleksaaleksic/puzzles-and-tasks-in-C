#include <stdio.h>
#include <string.h>
#define MAX 100

void removeS(int k, char* s1, char* s2){
    int n1= strlen(s1);
    int n2 = strlen(s2);
    for(int i = k; i < n1 - n2; i++){
        s1[i] = s1[i + n2];
    }
    s1[n1 - n2] = 0;
}

void ukloniString(char *s1,char *s2){
    int n1= strlen(s1);
    int n2 = strlen(s2);
    for(int i = 0; i < n1; i++){
        if(s1[i] == s2[0]){
            int flag = 1;
            for(int j = 0; j < n2; j++){
                if(s2[j] != s1 [i+j])
                    flag = 0;
            }
            if(flag)
                removeS(i,s1,s2);

        }
    }



}


int main(){

    char s1[MAX];
    fgets(s1,MAX,stdin);
    char s2[MAX];
    fgets(s2,MAX,stdin);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    s1[n1 - 1] = 0;
    s2[n2 - 1] = 0;
    ukloniString(s1,s2);
    fputs(s1,stdout);







    return 0;
}

