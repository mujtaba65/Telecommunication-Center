#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/*
This is the view class, it doesnt basically serves as showing options to user and taking their input, it has couple of helper functions to accomdate the purpose in control class.
*/

class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
