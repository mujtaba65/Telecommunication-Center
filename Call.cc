#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Call.h"
#include "Date.h"
#include "Time.h"

Call::Call(string src, string desti, int y, int m , int d, int h, int min, int dur)

{
	//cout<<"in CALL default ctor"<<endl;
	source = src;
	destination = desti;
	dura = dur; 
	date = new Date(y, m, d);
	startTime = new Time(h, min);

	
}

Call::~Call()
{
	if(date != NULL && startTime != NULL)
	{
		delete date;
		delete startTime;
	}		
}

//getter functions for src and dest..
// 3.4.6
string Call::getSource()
{
	return source;
}
string Call::getDestination()
{
	return destination;
}	

bool Call::greaterThan(Call* c)
{
	if(date->equals(c->date))
	{
		if(startTime->greaterThan(c->startTime))
		{
			return false;
		}
		return true;
		
	}

	if(date->greaterThan(c->date))
	{
		//cout<< "this date is later" << endl;
		return false;
	}
	return true;

}

void Call::print()
{
	
	date->print();
	startTime->print();
	cout<< setfill(' ') << setw(5) << dura << " mins:   From: " << source << setfill(' ')<< setw(10)<< "To: " << destination << endl;

}

