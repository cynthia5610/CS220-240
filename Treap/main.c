/**
* NAME: CYNTHIA HA
* WORKED WITH LUKE KRENTZ
*
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "treap.h"
#include "bst.h"

void cleanup();
int *create_sorted_array(int size, unsigned int seed);

int main(int argc, char *argv[]) {

	int i;
	unsigned int seed;
	int size;
	clock_t s0,s1,t0,t1;
	treap *t = NULL;
	bst *b = NULL;

	atexit(cleanup);

	if(argc != 3) {
		fprintf(stderr, "Usage: %s seed size\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if(sscanf(argv[1], "%u", &seed) != 1) {
		fprintf(stderr, "seed should be unsigned\n");
		exit(EXIT_FAILURE);
	}

	if(sscanf(argv[2], "%d", &size) != 1 || size <= 0) {
		fprintf(stderr, "size should be > 0\n");
		exit(EXIT_FAILURE);
	}
	srand(seed);
	t = treap_new();
	b = bst_new();

	int array[size];
	for(i=0;i<size;i++) {
		array[i] = rand() % 100;
	}

	s0 = clock();
	for(i = 0; i < size; i++) {
		treap_insert(&t, array[i]);
	}
	t0 = clock();

	s1 = clock();

	for(i = 0; i < size; i++) {
		bst_insert(&b, array[i]);
	}
	t1 = clock();

//	treap_print(t, 0);

	printf("BST ticks = %ld\n", t1);
	printf("Treap ticks = %ld\n\n", t0);
	
	printf("BST depth = %d\n", bst_depth(b));
	printf("Treap depth = %d\n", treap_depth(t));
	

	treap_delete(&t);
	bst_delete(&b);

	exit(EXIT_SUCCESS);
}


void cleanup() {
	return;
}
