#include <iostream>
using namespace std;
#include <string>

#include "Control.h"
#include "View.h"
#include "Subscriber.h"
#include "Telco.h"


Control::Control()
{
	telco = new Telco("Mujtaba");

}
Control::~Control()
{
	delete telco;
}

void Control::launch()
{
	initData(telco);
	//b)  use view object?? to display main menu and read users selection, until user exits..
	View v;
	//c) ????
	int choice;
	bool x = true;
	while(x)
	{
		v.showMenu(choice);
		if(choice==0){
			x = false;
		}
		else if(choice == 1)
		{
			string s;
			v.readStr(s);
			telco->computeFreqCaller(s);
		}
		else if(choice == 2)
		{
			string b;
			v.readStr(b);
			telco->computeFreqCalled(b);
		}
		else if(choice == 3)
		{
			telco->print();
		}	
	}
}

void Control::initData(Telco* tel)
{
  initSubscribers(tel);
  initCalls(tel);
}

void Control::initSubscribers(Telco* tel)
{
  tel->addSub(new Subscriber("6139990000")); 
  tel->addSub(new Subscriber("6133334444"));
  tel->addSub(new Subscriber("6138889999")); 
  tel->addSub(new Subscriber("6131112222"));
  tel->addSub(new Subscriber("6132223333"));
  tel->addSub(new Subscriber("6134445555")); 
}

void Control::initCalls(Telco* tel)
{
  tel->addCall("6139990000", "6133334444", 2020, 1, 1, 0, 31, 12);
  tel->addCall("6139990000", "6132223333", 2019, 2, 2, 10, 54, 2);

  tel->addCall("6132223333", "6139990000", 2019, 2, 23, 6, 33, 11);
  tel->addCall("6132223333", "6139990000", 2019, 3, 2, 10, 54, 2);
  tel->addCall("6132223333", "6139990000", 2019, 2, 20, 14, 22, 5);
  tel->addCall("6132223333", "6131112222", 2019, 12, 18, 4, 5, 15);

  tel->addCall("6131112222", "6132223333", 2019, 6, 30, 6, 2, 5);
  tel->addCall("6131112222", "6139990000", 2019, 8, 9, 8, 29, 7);
  tel->addCall("6131112222", "6130000000", 2019, 8, 9, 8, 29, 7);
  tel->addCall("6131112222", "6138889999", 2019, 3, 10, 15, 12, 11);

  tel->addCall("6134445555", "6138889999", 2019, 3, 10, 15, 22, 1);
  tel->addCall("6134445555", "6138887777", 2019, 3, 10, 15, 24, 10);
  

}

