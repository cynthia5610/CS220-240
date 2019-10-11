#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <iostream>
#include <stdbool.h>
using namespace std;

class Clock {
private:
	int hour; // 0 to 24
	int min; // 0 to 60
	bool twelve;
	bool twentyfour;
public:
	Clock();
	Clock(int hours);
	Clock(int hours, int minutes);
	int get_Hours();
	int get_Min();
	bool get_Twelve();
	bool get_Twentyfour();
	friend ostream &operator<<(ostream &os, Clock &clk);
	void set_12();
	void set_24();
};


#endif // _CLOCK_H_