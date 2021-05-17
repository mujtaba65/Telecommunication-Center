#include <iostream>
using namespace std;

#include "Subscriber.h"
#include "Array.h"
#include "Call.h"

Subscriber::Subscriber(string s)
{
	phoneNumber = s;
}


Subscriber::~Subscriber()
{
	//cout << "Subscriber Dtor" << endl;
}


void Subscriber::addIncoming(Call* c)
{
	incomingCalls.add(c);
}
void Subscriber::addOutgoing(Call* c)
{
	outgoingCalls.add(c);
}

void Subscriber::print()
{
	cout << "Subscriber  " << phoneNumber << ":" << endl;
	Array temp(incomingCalls);
	temp.add(outgoingCalls);
	temp.print();
}

string Subscriber::getPhoneNumber()
{
	return phoneNumber;
}

Array& Subscriber::getIncomingCalls()
{
	return incomingCalls;
}

Array& Subscriber::getOutgoingCalls()
{
	return outgoingCalls;
}
