#include "select_sort.h"

static void swap(int *a, int *b, int *swaps);
static int comp(int a, int b, int *comps);

void select_sort(int *array,int  size, int *comps, int *swaps)
{
    
    int min, num, i, j;
    
    if(size < 2)
        return;
    
    for(i = 0; i < size; i++)
    {
        min = array[i];
        num = i;
        
        for( j = i +1; j < size; j++)
        {
            comp(array[j], min, comps);
            if(array[j] < min)
            {
                min = array[j];
                num = j;
            }
        }
        swap(&array[num], &min, swaps);
        
    }
    return;
}

static int comp(int a, int b, int *comps)
{
    (*comps)++;
    
    return a - b;
}

static void swap(int *a, int *b, int *swaps)
{
    int temp;
    
    (*swaps)++;
    temp = *a;
    *a = *b;
    *b = temp;
    
    return;
}
