#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "treap.h"

static void rotate(treap **t, bool is_left);
static int depth(treap *t, int d);

treap *treap_new() {
	return NULL;
}


void treap_insert(treap **t, int val) {
	if(*t == NULL) {
		treap *node = (treap *)malloc(sizeof(treap));
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
		node->val = val;
		node->key = rand();
		*t = node;
	}
	else if(val <= (*t)->val) {
		treap_insert(&((*t)->left), val);
		(*t)->left->parent = *t;
		if((*t)->key < (*t)->left->key) {
			rotate(t, false);
		}
	}
	else {
		treap_insert(&((*t)->right), val);
		(*t)->right->parent = *t;
		if((*t)->key < (*t)->right->key) {
			rotate(t, true);
		}
	}
	return;
}


int treap_depth(treap *t) {
	return depth(t, 0);
}



void treap_delete(treap **t) {
	if(*t == NULL) {
		return;
	}

	treap_delete(&((*t)->left));
	treap_delete(&((*t)->right));
	free(*t);
	*t = NULL;
	return;
}


void treap_print(treap *t, int pos) {
	if(t == NULL) {
		return;
	}

	printf("%d : %d at pos %d\n", t->val, t->key, pos);
	treap_print(t->left, 2*pos + 1);
	treap_print(t->right, 2*pos + 2);

	return;
}


static void rotate(treap **t, bool is_left) {
	treap *P = *t;
	treap *C = (is_left ? P->right : P->left);
	treap *root = P->parent;
	treap *CC = (is_left ? C->left : C->right);

	*t = C;
	C->parent = root;
	if(is_left) {
		P->right = CC;
		C->left = P;
	}
	else {
		P->left = CC;
		C->right = P;
	}

	if(CC != NULL) {
		CC->parent = P;
	}
	P->parent = C;

	return;
}


static int depth(treap *t, int d) {
	int ldepth;
	int rdepth;
	int deepest;

	if(t == NULL) {
		return 0;
	}
	ldepth = depth(t->left, d + 1);
	rdepth = depth(t->right, d + 1);

	deepest = d;
	if(ldepth > deepest) {
		deepest = ldepth;
	}
	if(rdepth > deepest) {
		deepest = rdepth;
	}

	return deepest;
}
