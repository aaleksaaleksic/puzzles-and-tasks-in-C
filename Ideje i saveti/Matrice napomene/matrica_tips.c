#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

//ovako brsimo swapovanje elemenata unutar niza
//pomocu pokazivaca
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}




int main(){

    int array[5] = {7,4,6,9,1};
    for (int i = 0; i < 5; ++i) {
        printf(" %d ",array[i]);
    }
    printf("\n");

    swap(&array[0],&array[2]);
    for (int i = 0; i < 5; ++i) {
        printf(" %d ",array[i]);
    }
    int n = 5;
    //sortiranje elemenata
    //SELECTION SORT
    for (int i = 0; i < n-1; i++) { //4 jer je n - 1 za n = 5
        int minimum = i;
        for(int j = i+1; j < n;j++){
            if(array[j] < array[minimum]) {
                minimum = j;
            }
        }
        if(minimum != i){
            swap(&array[minimum],&array[i]);

        }
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf(" %d ",array[i]);
    }
    // za siftovanje elemenata niza za k broj pozicija u lijveo

    int k = 4;
    for (int i = 0; i < k; ++i){
        int last = array[0];
        for (int j = 0; j < n-1; ++j) {
            array[j] = array[j+1];
        }
        array[n-1] = last;
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf(" %d ",array[i]);
    }

    //za rotiranje put desno k-puta
    int z = 3;
    for (int i = 0; i < z; ++i){
        int last = array[n-1];
        for (int j = n-1; j > 0; j--) {
            array[j] = array[j-1];
        }
        array[0] = last;
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf(" %d ",array[i]);
    }



    return 0;
}
