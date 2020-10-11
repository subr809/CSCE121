#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"
#include "Course.h"

using namespace std;

void School::addCourses(std::string filename){
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string id;
    getline(ss, id, ',');
    string startTimehour;
    getline(ss, startTimehour, ':');
    string startTimemin;
    getline(ss, startTimemin, ',');
    string endTimehour;
    getline(ss, endTimehour, ':');
    string endTimemin;
    getline(ss, endTimemin, ',');
    string title;
    getline(ss, title);
    if (!ss.fail()) {
      courses.push_back(Course(id, title, Date(stoi(startTimehour), stoi(startTimemin), 0), Date(stoi(endTimehour), stoi(endTimemin), 0)));
    }
  }
}

void School::addAttendanceData(std::string filename){
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string year;
    getline(ss, year, '-');
    string month;
    getline(ss, month, '-');
    string day;
    getline(ss, day, ' ');
    string hour;
    getline(ss, hour, ':');
    string min;
    getline(ss, min, ':');
    string sec;
    getline(ss, sec, ',');
    string id;
    getline(ss, id, ',');
    string uin;
    getline(ss, uin);
    if (!ss.fail()) {
      for (int j = 0; j < students.size(); j++){
        if (uin == students.at(j).get_id()){
          students.at(j).addCourse(id);
        }
      }
      for (int i = 0; i < courses.size(); i++){
        if (courses.at(i).getID() == id){
          courses.at(i).addAttendanceRecord(AttendanceRecord(id, uin, Date(stoi(year), stoi(month), stoi(day), stoi(hour), stoi(min), stoi(sec))));
        } 
      }
    }
  }
}

void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
      students.push_back(Student(uin, name));
    }
  }
}

void School::listCourses(){
  if (courses.size() == 0){
    cout << "No Courses" << endl;
  }
  else{
    for(int i = 0; i < courses.size(); i++){
      cout << courses.at(i).getID() << "," << courses.at(i).getStartTime().getTime() << "," << courses.at(i).getEndTime().getTime() << "," << courses.at(i).getTitle() << endl;
    }
  }
}

void School::listStudents(){
  if (students.size() == 0){
    cout << "No Students" << endl;
  }
  else{
    for (int i = 0; i < students.size(); i++){
      cout << students.at(i).get_id() << "," << students.at(i).get_name() << endl;
    }
  }
}

void School::outputCourseAttendance(std::string course_id){
  for (int i = 0; i < courses.size(); i++){
    if (courses.at(i).getID() == course_id){
      courses.at(i).outputAttendance();
    }
  }
}

void School::outputStudentAttendance(std::string student_id, std::string course_id){
  for (int i = 0; i < courses.size(); i++){
    if (courses.at(i).getID() == course_id){
      courses.at(i).outputAttendance(student_id);
    }
  }
}