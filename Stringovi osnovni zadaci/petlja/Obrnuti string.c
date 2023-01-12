#include <stdio.h>
#include <string.h>
#define MAX 100

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    char s[MAX];
    fgets(s,MAX,stdin);
    int n = strlen(s) - 1;
    s[n] = 0;

    for (int i = 0; i < n / 2; i++)
        swap(&s[i], &s[n - i - 1]);

    fputs(s, stdout);

    return 0;
}
//void swap(char* a, char* b) {
//    char t = *a;
//    *a = *b;
//    *b = t;
//}
//
//
//int main() {
//
//    char s[100];
//
//    fgets(s, 100, stdin);
//
//    int n = strlen(s) - 1;
//    int x = strlen(s);
//    s[x - 1] = 0;
//    printf("%d   %d\n",n,x);
//
//    for(int i = 0; i < n/2; i++) {
//        swap(&s[i], &s[n-1-i]);
//    }
//
//    fputs(s, stdout);
//    return 0;
//}
