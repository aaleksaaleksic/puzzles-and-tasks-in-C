#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#define MAX 1000

//unso amjZdghAshZfgh
int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1] = 0;
    int n = strlen(str);
    int max_len = 1;
    for(int i = 0; i < n; i++){
        int last_occ = i;
        for(int j = i+1; j < n;j++){
            if(str[i] == str[j] || abs(str[i] - str[j]) == 32){
                last_occ = j;
            }
        }
        int len = last_occ - i + 1;
        if(len > max_len)
            max_len = len;
    }
    for(int i = 0; i <= n - max_len; i++){
        if(str[i] == str[i+max_len-1] || abs(str[i] - str[i+max_len-1]) == 32){
            for(int j = i; j < i + max_len;j++)
                putchar(str[j]);
            putchar(' ');
        }
    }
    return 0;
}
