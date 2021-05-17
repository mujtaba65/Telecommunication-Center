#ifndef CALL_H
#define CALL_H
//2 parties, atleast one party must be subscriber of telco and it is possible both of them might be members of telco..

#include "Date.h"
#include "Time.h"

/*
This is the call class, it takes in the details for source and destination of phone number as a string, takes the date right after it, and lastly the starting hour and minute and duration of the call. The destructor frees the date and time as they are being allocated memory, in the ctor. The greaterThan function compare the specifcs for 2 calls, the specifics being the date and the startTime, the call which happens earlier is greater than the call happening at a later time/date. It has getter functions to help other classes, mainly telco. The print() prints out details for the call.

*/

class Call
{
	public:
	Call(string = " ", string = " ", int = 2000, int = 0, int = 0, int = 0, int = 0, int = 0);
	~Call();
	bool greaterThan(Call*);
	void print();
	string getSource();
	string getDestination();


	private:
	string source;
	string destination;
	int dura;
	Date* date;
	Time* startTime; 

};



#endif
