#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;

Course::Course(std::string id, std::string title, Date startTime, Date endTime){
    this-> id  = id;
    this-> title = title;
    this-> startTime = startTime;
    this-> endTime = endTime;
}

void Course::addAttendanceRecord(AttendanceRecord ar){
    if (ar.getDate().getTime() >= getStartTime().getTime() && ar.getDate().getTime() <= getEndTime().getTime()){
        attendanceRecords.push_back(ar);
    }
}

void Course::outputAttendance(){
    if (attendanceRecords.size() != 0){
		for (int i = 0; i < attendanceRecords.size(); i++){
            cout << attendanceRecords.at(i).getDate().getDate() << "," << attendanceRecords.at(i).getCourseID() << "," << attendanceRecords.at(i).getStudentID() << endl; 
        }
    }
    else{
		cout << "No Records" << endl;
    }
}

void Course::outputAttendance(std::string student_id){
    int count = 0;
    if (attendanceRecords.size() != 0){
        for (int i = 0; i < attendanceRecords.size(); i++){
            if (attendanceRecords.at(i).getStudentID() == student_id){
				count += 1;
                cout << attendanceRecords.at(i).getDate().getDate() << "," << attendanceRecords.at(i).getCourseID() << "," << attendanceRecords.at(i).getStudentID() << endl; 
            }
        }
		if (count == 0) {
			cout << "No Records" << endl;
		}
    }
    else {
        cout << "No Records" << endl;
    }
}