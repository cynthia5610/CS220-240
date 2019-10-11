#include "binary_search.h"

bool binary_search(int *array, int size, int val, int *comps){

  bool found = false;
  int middle = 0;
  int L = 0;
  int R = size - 1;

  while(!found && L <= R){
    middle = (L + R) / 2;

    if(val == array[middle]){
      found = true;
    }
    else if (val < array[middle]){
      R = middle - 1;
    }
    else{
      L = middle + 1;
    }
  }
    return found;
}
