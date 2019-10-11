#include "linear_search.h"

static int comp(int a, int b, int *comps);

void linear_search(int *array, int size, int val, int *comps)
{

    int i = 0;

    while(i < size)
    {
        comp(val, array[i], comps);
        if(val == array[i])
        {
            break;
        }
        else if(val < array[i])
        {
            break;
        }
        else
        {
            i++;
        }
        
    }
    return;
}

static int comp(int a, int b, int *comps)
{
    (*comps)++;

    return a - b;
}
