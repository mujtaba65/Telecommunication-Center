#include <iostream>
using namespace std;
#include <string>
#include "Date.h"
#include "Call.h"
#include "Time.h"
#include "Array.h"
#include "Subscriber.h"
#include "Telco.h"
#include "Control.h"

/*
NOTE: The computing functions in telco, for specific numbers doesn't work completely because it is partial code, it was giving segmentation fault so removed the part causing it. For "all" it works fine.
*/

/*
This is the main function, but all the work of a main function is done under control class with the help of view class. The purpose of this program is to represent a call center which has subscribers, now the call logs for only the subscribers are saved. If neither the source or destination are not subscribes this wont be stored anywhere. Telco is the company which stores the data for all calls, and subscribers, there incoming and outgoing calls respectively. Now telco is comprised of multiple classes, with each classes role being explained in the header of each class.

*/
/*
To test user input is required. options from 0,1,2,3 and if 1 or 2 chosen a specific number to be given or "all"
*/

int main()
{

	Control x;
	x.launch();
	return 0;

}
