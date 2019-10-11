#include "insert_sort.h"

static int comp(int a, int b, int *comps);
static void swap(int *a, int *b, int *swaps);

void insert_sort(int *array, int size, int *comps, int *swaps){
    
    int val, hole, i;
    
    for(i = 1; i < size; i++)
    {
        val = array[i];
        hole = i-1;
        
        while(hole>0 && val < array[hole])
        {
            comp(array[hole],array[i],comps);
            array[hole+1] = array[hole];
            hole--;
        }
        if(hole != i)
        {
            array[hole] = val;
            (*swaps)++;
        }
    }
}

static int comp(int a, int b, int *comps){
    (*comps)++;
    
    return a - b;
}
