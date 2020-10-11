#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include "Date.h"

using namespace std;

Date::Date(int year, int month, int day, int hour, int min, int sec) :
    year(year), month(month), day(day), hour(hour), min(min), sec(sec) {
    }

    
Date::Date(int hour, int min, int sec) 
  : timestamp(0), year(0), month(0), day(0), 
    hour(hour), min(min), sec(sec) {
    }

Date::Date(){
  this-> year = 0;
  this-> month = 0;
  this-> day = 0;
  this-> hour = 0;
  this-> min = 0;
  this-> sec = 0;
}

string Date::getDate() {
  stringstream ss;
  switch (dayOfWeek) {
    case 0: ss << "Sun"; break;
    case 1: ss << "Mon"; break;
    case 2: ss << "Tue"; break;
    case 3: ss << "Wed"; break;
    case 4: ss << "Thu"; break;
    case 5: ss << "Fri"; break;
    case 6: ss << "Sat"; break;
  }
  ss << month << "/" << day << "/" << year << " ";
  ss << setw(2) << setfill('0') << hour << ":"; 
  ss << setw(2) << setfill('0') << min << ":";
  ss << setw(2) << setfill('0') << sec;
  return ss.str();
}

string Date::getTime() {
  stringstream ss;
  ss << setw(2) << setfill('0') << hour << ":"; 
  ss << setw(2) << setfill('0') << min;
  return ss.str();
}

bool Date::operator<=(Date d) {
  if (this->hour < d.hour) {
    return true;
  }
  else if ((this->hour == d.hour) && (this->min < d.min)) {
    return true;
  }
  else if ((this->min == d.min) && (this->sec < d.sec)) {
    return true;
  }
  else if (this->sec == d.sec) {
    return true;
  }

  return false;
}

bool Date::operator>=(Date d) {
  if (this->hour > d.hour) {
    return true;
  }
  else if ((this->hour == d.hour) && (this->min > d.min)) {
    return true;
  }
  else if ((this->min == d.min) && (this->sec > d.sec)) {
    return true;
  }
  else if (this->sec == d.sec) {
    return true;
  }

  return false;
}