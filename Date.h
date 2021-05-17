#ifndef DATE_H
#define DATE_H

/*
This is the Date class, the data members are initialized accordingly. After that it has a greaterThan() member function compares this date with a given date. The print() prints details about the event. There is also an additional equals() function which handles the edge case when two dates are same.
*/

class Date
{
  public:
    Date(int=2000, int=0, int=0);
    ~Date();
    void setDate(int, int, int);
    bool greaterThan(Date*);
    bool equals(Date*);
    void print();

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif
