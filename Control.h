#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"
#include "Subscriber.h"

/*
This is the control class, it initializes a dynamic array for telco, also frees up the memory. This is basically the tester code, it sends in all the data for the program. launch() initializes the data members for telco class, and then with the help of view class, it takes user input for the required action.
*/

class Control
{
  public:
  Control();
  ~Control();
  void launch();

  private:
  Telco* telco;
  //View* v;
 
  void initData(Telco*);
  void initSubscribers(Telco*);
  void initCalls(Telco*);

};

#endif
