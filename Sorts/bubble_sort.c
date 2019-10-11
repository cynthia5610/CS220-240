#include "bubble_sort.h"
#include <stdbool.h>

static int comp(int a, int b, int *comps);
static void swap(int *a, int *b, int *swaps);

void bubble_sort(int *array, int size, int *comps, int *swaps) {
    
    int i = 0, j = 0;
    bool loop;
    
    if(size < 2)
        return;
    
    do{
        loop = false;
        for(i = 0; i < size - j - 1; i++)
        {
            comp(array[i],array[i+1],comps);
            if(array[i] > array[i+1])
            {
                swap(&array[i],&array[i+1],swaps);
                loop = true;
            }
        }
        j++;
    }while(loop);
    
    return;
}
static int comp(int a, int b, int *comps){
    (*comps)++;

    return a - b;
}

static void swap(int *a, int *b, int *swaps){
    int temp;

    (*swaps)++;
    temp = *a;
    *a = *b;
    *b = temp;

    return;
}
