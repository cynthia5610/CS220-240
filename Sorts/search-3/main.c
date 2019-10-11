#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "binary_search.h"
#include "linear_search.h"

int *create_sorted_array(int size, unsigned int seed);
int str_to_int(char *str, int base);

int main (int argc, char *argv[]){

  int i;
  int comps;
  int val = 0;
  unsigned int seed = 0;
  int size_of_array = 0;
  int *array = NULL;

  if(argc != 3){
    fprintf(stderr, "ERROR: To many/few arguments\n");
    exit(EXIT_FAILURE);
  }
  if(argc == 3){
    unsigned int arg = 0;
    if(sscanf(argv[1], "%u", &arg) != 1){
      fprintf(stderr, "ERROR: seed must be unsigned\n");
      exit(EXIT_FAILURE);
    }
    size_of_array = str_to_int(argv[2], 10);
    seed = arg;

    printf("seed = %u\n", seed);
    printf("array size = %d\n", size_of_array);
  }

  array = create_sorted_array(size_of_array, seed);

  for(i = 0; i < 3 * size_of_array; i++){
    val = i;

    if(binary_search(array, size_of_array, val, &comps)){
      printf(("Found! Number of Binary Search Compares: %d\n"), comps);
    }
    else{
      printf(("Not Found! Number of Binary Search Compares: %d\n"), comps);
    }
    comps = 0;

    if(linear_search(array, size_of_array, val, &comps)){
      printf("Found! Number of Linear Searchs Compares: %d\n\n", comps);
    }
    else{
      printf("Not Found! Number of Linear Searchs Compares: %d\n\n", comps);
    }
  }

  free(array);
  exit(EXIT_SUCCESS);
}


int *create_sorted_array(int size, unsigned int seed){

  int i;
  int num;
  int *result = NULL;

  if((result = (int *)malloc(sizeof(int) * size)) == NULL){
    fprintf(stderr, "ERROR: Bad Memory Allocation");
    exit(EXIT_FAILURE);
  }

  srand(seed);
  num = rand() % 3;
  for(i = 0; i < size; i++){
    num += rand() % 3;
    result[i] = num;
  }

  return result;
}

int str_to_int(char *str, int base){
  int result = 0;
  char *c = str;
  while(isalnum(*c)){
    result *= base;
    if(isdigit(*c)){
      result += *c - '0';
    }
    c++;
  }
  str = c;

  return result;
}
