#include "binary_search.h"

static int comp(int a, int b, int *comps);

void binary_search(int *array, int size, int val, int *comps){
    

  int middle = 0;
  int L = 0;
  int R = size - 1;

  while(L <= R)
  {

      
      middle = (L + R) / 2;
      comp(val, array[middle], comps);
      if(val == array[middle])
      {
          break;
      }
      else if (val < array[middle])
      {
          R = middle - 1;
      }
      else
      {
          L = middle + 1;
      }
  }
  return;
}

static int comp(int a, int b, int *comps)
{
    (*comps)++;
    return a - b;
}
