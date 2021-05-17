#ifndef TIME_H
#define TIME_H

/*
This is the time class, it takes the starting time for a call. The data members being the starting hour and minute. It makes uses of the greater Than function to determine the starting time of a call, if 2 calls are on the same day, month and year. And lastly there's a print function to print the starting time.
*/

class Time
{
  public:
    Time(int=0, int=0);
    bool greaterThan(Time*);
    void print();

  private:
    int  hours;
    int  minutes;
    void setTime(int, int);
    int  convertToMins();
};

#endif
