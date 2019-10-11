#include "search.h"

static int comp(int a, int b, int *comps);
static void swap(int *a, int *b, int *swaps);

bool binary_search(int *array, int size, int val, int *comps, int *swaps) {
	int x = 4;
	int y = 17;

	*comps = 0;
	*swaps = 0;

	comp(3,6, comps);
	comp(7,1, comps);
	comp(2,2, comps);
	comp(9,3, comps);

	swap(&x, &y, swaps);

	return true;
}


static int comp(int a, int b, int *comps) {
	(*comps)++;

	return a - b;
}


static void swap(int *a, int *b, int *swaps) {
	int tmp;

	(*swaps)++;
	tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}
