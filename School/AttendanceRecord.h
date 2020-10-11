#ifndef ATTENDANCERECORD_H
#define ATTENDANCERECORD_H

#include <string>
#include "Date.h"

class AttendanceRecord {
  std::string course_id;
  std::string student_id;
  Date time;

public:
  AttendanceRecord(std::string course_id, std::string student_id, Date time);
  std::string getCourseID(){
    return this-> course_id;
  }
  std::string getStudentID(){
    return this-> student_id;
  }
  Date getDate(){
    return this-> time;
  }
};

#endif