#ifndef __TREAP_H__
#define __TREAP_H__

typedef struct treap treap;

struct treap {
	treap *parent;
	int val;
	int key;
	treap *left;
	treap *right;
};

extern treap *treap_new();
extern void treap_insert(treap **t, int val);
extern int treap_depth(treap *t);
extern void treap_delete(treap **t);
extern void treap_print(treap *t, int pos);

#endif /* __TREAP_H__ */
