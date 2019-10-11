#include <cstdlib>
#include <stdbool.h>
#include <iostream>
#include "Clock.h"

using namespace std;
	ostream& operator<<(ostream& os, Clock& clk)
	{
		if(clk.get_Twentyfour() == true)
		{
			if(clk.get_Hours() < 10)
				os << '0' << clk.get_Hours() << ':';
			else
				os << clk.get_Hours() << ':';
			if(clk.get_Min() < 10)
				os << '0' << clk.get_Min();
			else 
				os << clk.get_Min();
		}
		else 
		{
			if(clk.get_Hours() <= 12)
			{
				if(clk.get_Hours() == 0)
					os << "12:";
				else if(clk.get_Hours() < 10)
					os << '0' << clk.get_Hours() << ':';
				else
					os << clk.get_Hours() << ':';
				if(clk.get_Min() < 10)
					os << '0' << clk.get_Min() << ' ' << "am";
				else 
					os << clk.get_Min() << ' ' << "am";
			}
			else
			{
				os << clk.get_Hours() - 12 << ':';
				if(clk.get_Min() < 10)
					os << '0' << clk.get_Min() << ' ' << "pm";
				else 
					os << clk.get_Min() << ' ' << "pm";
			}
		}
		return os;
	}

	Clock::Clock()
	{
		hour = 0;
		min = 0;
	}
	Clock::Clock(int hours)
	{
		if(hours < 0 || hours > 23)
		{
			cout << "Hours can't be " << hours << "...assuming 0" << endl;
			hour = 0;
			min = 0;
		}
		else
		{
			hour = hours;
			min = 0;
		}
	}
	Clock::Clock(int hours, int minutes)
	{
		if(hours < 0 || hours > 23)
		{
			cout << "Hours can't be " << hours << "...assuming 0" << endl;
			hour = 0;
			if(minutes < 0 || minutes > 59)
			{
				cout << "Minutes can't be " << minutes << "...assuming 0" << endl;
				min = 0;
			}
			else
				min = minutes;
		}
		else
		{
			hour = hours;
			if(minutes < 0 || minutes > 59)
			{
				cout << "Minutes can't be " << minutes << "...assuming 0" << endl;
				min = 0;
			}
			else
				min = minutes;
		}
	}
	void Clock::set_12()
	{
		twelve = true;
		twentyfour = false;
	}
	void Clock::set_24()
	{
		twentyfour = true;
		twelve = false;
	}
	int Clock::get_Hours()
	{
		return hour;
	}
	int Clock::get_Min()
	{
		return min;
	}
	bool Clock::get_Twelve()
	{
		return twelve;
	}
	bool Clock::get_Twentyfour()
	{
		return twentyfour;
	}