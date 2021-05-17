#include <iostream>
using namespace std;

#include "Array.h"
#include "Call.h"

Array::Array()
{
  numberOfElems = 0;
}

Array::~Array()
{
	//3.5.2
	//cout << "Array Dtor" << endl;
}
Array::Array(Array& oldArr)
{
	//numberOfElems = 0;
	numberOfElems = oldArr.numberOfElems;
	for(int b = 0; b < oldArr.numberOfElems; b++)
	{
		elements[b] = oldArr.elements[b];
		//add(oldArr.elements[b]);
	}

}

bool Array::add(Call* c)
{
	if (numberOfElems >= MAX_ARR)
	{
		delete c;
		cout << "GET FKED" << endl;
		return false;
	}	
	if(numberOfElems == 0)
	{
		//cout<< "success" << endl;
		elements[0] = c;
		numberOfElems++;
		return true;
	}
	for(int i = 0; i < numberOfElems; i++)
	{
		if (!(c->greaterThan(elements[i])))
		{			
			for(int x = numberOfElems; x > i; x--)
			{
				elements[x] = elements[x-1];
			}
			//cout<< "helo" << endl;
			elements[i] = c;
			numberOfElems++;
			return true;
			
		}

			
	}
	//cout << "added here" << endl;
	elements[numberOfElems] = c;
	numberOfElems++;
	return true;	
	//cout<< "Invalid call" << endl;
	//delete c;
	//return false;	
}

bool Array::add(Array& arr)
{	
	bool d;
	for(int j = 0; j < arr.numberOfElems; j++)
	{
		//add each arr to this array..
		d = add(arr.elements[j]);
	}
	return d;
}
void Array::cleanup()
{
	for (int i=0; i<numberOfElems; i++)
		delete elements[i];
	
}


void Array::print()
{
  //cout << endl << endl << "Call log:" << endl;
  for (int i=0; i<numberOfElems; ++i)
    elements[i]->print();

  cout << endl;
}



int Array::getNumElems()
{
	return numberOfElems;
}

Call* Array::getElement(int x)
{
	return elements[x];
}






