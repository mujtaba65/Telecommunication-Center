#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Date.h"
#include "Time.h"
#include "Call.h"
#include "Array.h"

/*
This is the subscriber class, the constructor takes in the phone number string as the name/phoneNumber. Then it has 2 arrays for each subscriber once it has been registered, one array keeps track of incoming calls, and the other for outgoing calls. Now to add calls to the specific array it makes use of addincomingCalls() and addOutgoingCalls() respectively, to acheive this addition it, calls the add function in array class. It has a print() function which makes a temporary array using incoming calls and merges it with outgoing call using the add(array&) function in Array class. Lastly there are getter functions to accomodate telco class.
*/

class Subscriber
{
	public:

	Subscriber(string);
	~Subscriber();
	//getter functions for: incoming, outgoing calls.. if so collection must be returned by reference not value.
	void addIncoming(Call*);
	void addOutgoing(Call*);
	void print();
	string getPhoneNumber();
	Array& getIncomingCalls();
	Array& getOutgoingCalls();

	private:
	string phoneNumber;
	Array incomingCalls;
	Array outgoingCalls;


};



#endif
