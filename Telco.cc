#include <iostream>
using namespace std;

#include "Subscriber.h"
#include "Array.h"
#include "Call.h"

#include "Telco.h"

Telco::Telco(string s)
{
	name = s;
	numOfSubs = 0;
}

Telco::~Telco()
{
	allCalls.cleanup();	
	for(int i = 0; i < numOfSubs; i++)
	{
		delete allSubs[i];
	}
}
void Telco::addSub(Subscriber* s)
{
	if(numOfSubs >= MAX_brr)
	{
		cout<< "Error subscriber could not be added.." << endl;
		return;
	}
	allSubs[numOfSubs] = s;
	numOfSubs++;
	return;
}
void Telco::addCall(string srcNum, string destNum, int y, int m, int d, int h, int min, int dur)
{


	Call* c = new Call(srcNum,destNum, y, m, d, h, min, dur);

	bool added = false;
	bool i, o;
	for(int s = 0; s < numOfSubs; s++)
	{
		if((o = allSubs[s]->getPhoneNumber() == srcNum) ||(i = allSubs[s]->getPhoneNumber()== destNum))
		{
			added = true;
			if(o)
			{
				allSubs[s]->addOutgoing(c);	
			}
			else if(i)
			{
				allSubs[s]->addIncoming(c);	
			}
		}
	}
	if(added){
		allCalls.add(c);
	}
	if(!(added))
	{
		cout << "CALL COULD NOT BE ADDED" << endl;
		delete c;
		return;
	}


}

void Telco::computeFreqCaller(string destNum)
{
	int counter = 0;
	int maximum = 0;
	string arr[50];
	int c = 0;
	if (destNum == "all")
	{
		for(int x = 0; x < allCalls.getNumElems(); x++)
		{

			counter = 0;
			for(int j = 0; j < allCalls.getNumElems(); j++)
			{
				if(allCalls.getElement(x)->getSource() == allCalls.getElement(j)->getSource())
				{
					counter++;
					if(maximum < counter)
					{

						string s = allCalls.getElement(x)->getSource();
						maximum = counter;
						c = 0;
	
						arr[c] = s;
						c++;
					}else if(maximum == counter)
					{
						bool yes = true;
						for(int i = 0; i < c; i++)
						{
							if(arr[i] == allCalls.getElement(x)->getSource())
								yes = false;
						}
						if(yes)
						{
							string o = allCalls.getElement(x)->getSource();
							arr[c] = o;
							c++;
				
						}	
					}
				
				}
			
			}
		}
		cout << endl;
		for(int i = 0; i < c; i++)
		{
			cout << "Most frequent caller to " << destNum << ": " << arr[i] << endl;
			for(int b = 0; b < allCalls.getNumElems(); b++)
			{
				if(arr[i] == allCalls.getElement(b)->getSource())
				{
					allCalls.getElement(b)->print();
				
				}
			}
			cout<<endl;
		
		}
	
	}
	else
	{
		bool flag = false;
		int index;
		
		for(int x = 0; x < numOfSubs; x++)
		{
			if(allSubs[x]->getPhoneNumber() == destNum)
			{
				flag = true;
				index = x;
			}
		
		}
		if(!(flag))
		{
			cout<< "error with finding destination number.. " << endl;
			return;
		}
		cout << "Found the number!" <<endl;
		for(int x = 0; x < allSubs[index]->getIncomingCalls().getNumElems(); x++)
		{			
			counter = 0;
			for(int j = 0;  j < allSubs[index]->getIncomingCalls().getNumElems(); j++)
			{
				if(allSubs[index]->getIncomingCalls().getElement(x)->getSource() == allSubs[index]->getIncomingCalls().getElement(j)->getSource())
				{
					counter++;
				}	
			}
		}
	}


}

void Telco::computeFreqCalled(string sourceNum)
{
	int counter = 0;
	int maximum = 0;
	string arr[50];
	int c = 0;
	if (sourceNum == "all")
	{
		for(int x = 0; x < allCalls.getNumElems(); x++)
		{
			counter = 0;
			for(int j = 0; j < allCalls.getNumElems(); j++)
			{
				if(allCalls.getElement(x)->getDestination() == allCalls.getElement(j)->getDestination())
				{
					counter++;
					if(maximum < counter)
					{
						string s = allCalls.getElement(x)->getDestination();
						maximum = counter;
						c = 0;
						arr[c] = s;
						c++;
					}else if(maximum == counter)
					{
						bool yes = true;
						for(int i = 0; i < c; i++)
						{
							if(arr[i] == allCalls.getElement(x)->getDestination())
								yes = false;
						}
						if(yes)
						{
							string o = allCalls.getElement(x)->getDestination();
							arr[c] = o;
							c++;
						}	
					}
				}
			}
		}
		cout << endl;
		for(int i = 0; i < c; i++)
		{
			cout << "Most frequent called by all: " << arr[i] << endl;
			for(int b = 0; b < allCalls.getNumElems(); b++)
			{
				if(arr[i] == allCalls.getElement(b)->getDestination())
				{
					allCalls.getElement(b)->print();
				}
			}
		}	
	}
	else
	{
		bool flag = false;
		int index;
		
		for(int x = 0; x < numOfSubs; x++)
		{
			if(allSubs[x]->getPhoneNumber() == sourceNum)
			{
				flag = true;
				index = x;
			}
		}
		if(!(flag))
		{
			cout<< "error with finding destination number.. " << endl;
			return;
		}
		cout << "Found the number!" <<endl;
		for(int x = 0; x < allSubs[index]->getOutgoingCalls().getNumElems(); x++)
		{			
			counter = 0;
			for(int j = 0;  j < allSubs[index]->getOutgoingCalls().getNumElems(); j++)
			{
				if(allSubs[index]->getOutgoingCalls().getElement(x)->getSource() == allSubs[index]->getOutgoingCalls().getElement(j)->getSource())
				{
					counter++;
				}			
			}
		}
	}


}

void Telco::print()
{
	cout << "TELCO " << name << "'s Telephone Co." << endl;
	cout << endl;
	for(int s = 0; s < numOfSubs; s++)
	{
		allSubs[s]->print();
	}

}
