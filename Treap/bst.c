#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "bst.h"

static int depth(bst *b, int d);

bst *bst_new() {
	return NULL;
}


void bst_insert(bst **b, int data) {
	if(*b == NULL) {
		bst *node = (bst *)malloc(sizeof(bst));
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
		node->data = data;
		*b = node;
	}
	else if(data <= (*b)->data) {
		bst_insert(&((*b)->left), data);
		(*b)->left->parent = *b;
	}
	else {
		bst_insert(&((*b)->right), data);
		(*b)->right->parent = *b;
	}
	return;
}


int bst_depth(bst *b) {
	return depth(b, 0);
}



void bst_delete(bst **b) {
	if(*b == NULL) {
		return;
	}

	bst_delete(&((*b)->left));
	bst_delete(&((*b)->right));
	free(*b);
	*b = NULL;
	return;
}


void bst_print(bst *b, int pos) {
	if(b == NULL) {
		return;
	}

	printf("%d at pos %d\n", b->data, pos);
	bst_print(b->left, 2*pos + 1);
	bst_print(b->right, 2*pos + 2);

	return;
}


static int depth(bst *b, int d) {
	int ldepth;
	int rdepth;
	int deepest;

	if(b == NULL) {
		return 0;
	}
	ldepth = depth(b->left, d + 1);
	rdepth = depth(b->right, d + 1);

	deepest = d;
	if(ldepth > deepest) {
		deepest = ldepth;
	}
	if(rdepth > deepest) {
		deepest = rdepth;
	}

	return deepest;
}
