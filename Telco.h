#ifndef TELCO_H
#define TELCO_H

#define MAX_brr 256

#include "Call.h"
#include "Subscriber.h"
#include "Array.h"
#include "Call.h"
/*
NOTE: Both compute function, the specific number for subscriber array doesnt work fully, it just checks if the input number is valid or not. My current solution was giving seg fault and I didn't know if i would get a 0 for it. So i removed it to avoid trouble.
*/

/*
This is the telco class, it basically represents a call center which keeps track of call logs of the SUBSCRIBERS ONLY, however either the source or destination might not be a member, one or both of them must be member for this class to be functional. The constructor takes the name for company and initializes an ARRAY for all calls, and an subscibers pointer array(not the class). The destructor frees up memory by deleting the calls first using cleanup and then clears the subscribers. The add functions are as follow, the addSub adds a new subscriber at the end of subsciber array. addCall adds a call to the call Array if the requirements match. The compute function searches for either the source or destination who have the most number of calls received or called. (This works for all but not for specific numbers part of it does). Lastly print, prints out all the subscribers and there call log with other phone numbers might be subscribers. 

*/

class Telco
{
  public:
    //ctor
    Telco(string);
    //dtor
    ~Telco();
    void addSub(Subscriber*);
    void addCall(string, string, int, int, int, int, int, int);
    void computeFreqCaller(string);
    void computeFreqCalled(string);
    void print();
    

  private:
    Array allCalls;
    Subscriber* allSubs[MAX_brr];
    int numOfSubs;
    string name;
    

};

#endif
