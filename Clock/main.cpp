// NAME: CYNTHIA HA
#include <iostream>
#include "Clock.h"

using namespace std;

int main(int argc, char *argv[]) {

	Clock c1;
	Clock c2(14);
	Clock c3(-10);
	Clock c4(9, 28);
	Clock c5(22, 72);
	Clock c6(123, 45);
	Clock c7(34, -67);
	Clock *c8 = new Clock(17, 28);

	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c5 << endl;
	cout << c6 << endl;
	cout << c7 << endl;
	cout << *c8 << endl;

	cout << "... 24 ..." << endl;

	c1.set_24();
	c2.set_24();
	c3.set_24();
	c4.set_24();
	c5.set_24();
	c6.set_24();
	c7.set_24();
	c8->set_24();

	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c5 << endl;
	cout << c6 << endl;
	cout << c7 << endl;
	cout << *c8 << endl;

	cout << "... 12 ..." << endl;

	c1.set_12();
	c2.set_12();
	c3.set_12();
	c4.set_12();
	c5.set_12();
	c6.set_12();
	c7.set_12();
	c8->set_12();

	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c5 << endl;
	cout << c6 << endl;
	cout << c7 << endl;
	cout << *c8 << endl;

	delete c8;

	return 0;
}
