#ifndef __BST_H__
#define __BST_H__


typedef struct bst bst;

struct bst {
	int data;
	bst * parent;
	bst *left;
	bst *right;
};

extern bst *bst_new();
extern void bst_insert(bst **b, int val);
extern int bst_depth(bst *b);
extern void bst_delete(bst **b);
extern void bst_print(bst *b, int pos);


#endif /* __BST_H__ */
