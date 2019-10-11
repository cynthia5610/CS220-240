#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "insert_sort.h"
#include "select_sort.h"
#include "bubble_sort.h"
#include "quick_sort.h"

int *create_random_array(int size, unsigned int seed);
int str_to_int(char *str, int base);

int main (int argc, char *argv[]){
    
    int i;
    int selcomps = 0, inscomps = 0, bubblecomps = 0, quickcomps = 0;
    int selswaps = 0, insswaps = 0, bubbleswaps = 0, quickswaps = 0;
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
    }
    
    array = create_random_array(size_of_array, seed);
    
    insert_sort(array, size_of_array, &inscomps, &insswaps);
    
    free(array);
    array = create_random_array(size_of_array, seed);
    
    select_sort(array, size_of_array, &selcomps, &selswaps);
    
    free(array);
    array = create_random_array(size_of_array, seed);
    
    bubble_sort(array, size_of_array, &bubblecomps, &bubbleswaps);
    
    free(array);
    array = create_random_array(size_of_array, seed);
    
    quick_sort(array, 0, size_of_array-1, &quickcomps, &quickswaps);
    
    
    printf("Insert comps: %d\n", inscomps);
    printf("Select comps: %d\n", selcomps);
    printf("Bubble comps: %d\n", bubblecomps);
    printf("Quicksort comps: %d\n", quickcomps);

    
    printf("\n");
    
    printf("Insert swaps: %d\n", insswaps);
    printf("Select swaps: %d\n", selswaps);
    printf("Bubble swaps: %d\n", bubbleswaps);
    printf("Quicksort swaps: %d\n", quickswaps);
    
    
    free(array);
    exit(EXIT_SUCCESS);
}


int *create_random_array(int size, unsigned int seed){
    
    int i;
    int j;
    int temp;
    int *result = NULL;
    
    if((result = (int *)malloc(sizeof(int) * size)) == NULL){
        fprintf(stderr, "ERROR: Bad Memory Allocation");
        exit(EXIT_FAILURE);
    }
    
    srand(seed);
    for(i = 0; i < size; i++){
        result[i] = i;
    }
    
    for(i = 0; i < size; i++){
        j = rand() % size;
        temp = result[i];
        result[i] = result[j];
        result[j] = temp;
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

