#include "quick_sort.h"

static int comp(int a, int b, int *comps);
static void swap(int *a, int *b, int *swaps);
int partition(int *array, int left, int right, int *comps, int *swaps);

void quick_sort(int *array, int left, int right, int *comps, int *swaps){
    
    if(left >= right){
        return;
    }
    int x = partition(array, left, right, comps, swaps);
    quick_sort(array, left, x-1, comps, swaps);
    quick_sort(array, x+1, right, comps, swaps);
    
    return;
}

int partition(int *array, int left, int right, int *comps, int *swaps){
    
    int pivot = left;
    int p_val = array[pivot];
    
    while(left < right){
        while(array[left] <= p_val){
            comp(array[left], p_val, comps);
            left++;
        }
        while(array[right] > p_val){
            comp(array[right], p_val, comps);
            right--;
        }
        if(left < right){
            swap(&array[left], &array[right], swaps);
        }
    }
    swap(&array[pivot], &array[right], swaps);
    return right;
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
