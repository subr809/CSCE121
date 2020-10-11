#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Date.h"
#include "AttendanceRecord.h"

class Course {
  std::string id;
  std::string title;
  Date startTime;
  Date endTime;
  std::vector<AttendanceRecord> attendanceRecords;

  public:
    Course(std::string id, std::string title, Date startTime, Date endTime);
    std::string getID(){
      return this-> id;
    }
    std::string getTitle(){
      return this-> title;
    }
    Date getStartTime(){
      return this-> startTime;
    }
    Date getEndTime(){
      return this-> endTime;
    }
    void addAttendanceRecord(AttendanceRecord ar);
    void outputAttendance();
    void outputAttendance(std::string student_id);
};

#endif