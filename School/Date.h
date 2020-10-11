#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
  long timestamp;

  int year;
  int month;
  int day;
  int hour;
  int min;
  int sec;
  int dayOfWeek;
  
public:
  Date();
  Date(int year, int month, int day, int hour, int min, int sec);
  Date(int hour, int min, int sec=0); 
  int getYear() { 
    return this-> year; 
  }
  int getMonth() { 
    return this-> month; 
  }
  int getDay() { 
    return this-> day; 
  }
  int getHour() { 
    return this-> hour; 
  }
  int getMin() { 
    return this-> min; 
  }
  int getSec() { 
    return this-> sec; 
  }
  std::string getDate();
  std::string getTime();
  bool operator<=(Date d);
  bool operator>=(Date d);
};

#endif