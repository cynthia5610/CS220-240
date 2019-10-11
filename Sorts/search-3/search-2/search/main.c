#include <stdio.h>
#include <stdlib.h>

#include "search.h"

#define SIZE 1000

void cleanup();
int *create_sorted_array(int size, unsigned int seed);

int main(int argc, char *argv[]) {

	int i;
	int comps;
	int swaps;
	unsigned int seed = 0;
	int *array = NULL;

	atexit(cleanup);

	if(argc == 2) {
		unsigned int arg = 0;
		if(sscanf(argv[1], "%u", &arg) != 1) {
			fprintf(stderr, "seed should be unsigned\n");
			exit(EXIT_FAILURE);
		}
		seed = arg;
	}

	array = create_sorted_array(SIZE, seed);

	if(binary_search(array, SIZE, 123, &comps, &swaps)) {
		printf("found (C:S = %d:%d)\n", comps, swaps);
	}
	else {
		printf("not found (C:S = %d:%d)\n", comps, swaps);
	}

	free(array);

	exit(EXIT_SUCCESS);
}


void cleanup() {
	return;
}


int *create_sorted_array(int size, unsigned int seed) {

	int i;
	int num;
	int *result = NULL;

	if((result = (int *)malloc(sizeof(int) * size)) == NULL) {
		fprintf(stderr, "bad malloc\n");
		exit(EXIT_FAILURE);
	}

	srand(seed);
	num = 0;
	for(i = 0; i < size; i++) {
		num += rand() % 3;
		result[i] = num;
	}

	return result;
}
