#ifndef ARRAY_H
#define ARRAY_H

#define MAX_ARR 64

#include "Call.h"
/*
This is the array class, not the standard library array. It initializes the number of elements in ctor, and the destructor is empty but it is there to prevent any issues. The copy constructor copies calls* from one(old) array to a new array (which is used for temporary in subscriber class print() function). The cleanup function basically frees the memory which is to be done in telco when all the calls are to be removed, this is why the dtor is empty. 2 adds, one of them adds the call into the array of call array. The other is for merging 2 arrays makes use of the first add function. The print function prints out all the calls in the array. Lastly couple of getter functions to help other classes, which need to read the private data from this class.
*/

class Array
{
  public:
    //ctor
    Array();
    //dtor
    ~Array();
    //copy constructor
    Array(Array&);
    
    void cleanup();
    bool add(Call*);
    bool add(Array&);
    void print();
    Call* getElement(int);
    int getNumElems();

  private:
    Call* elements[MAX_ARR];
    int   numberOfElems;
};

#endif

