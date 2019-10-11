#include "linear_search.h"

bool linear_search(int *array, int size, int val, int *comps){

  bool found = false;
  int i = 0;

  while(!found && i < size){
    if(val == array[i]){
      found = true;
    }
    else if(val < array[i]){
      break;
    }
    else{
      i++;
    }
  }
  return found;
}
