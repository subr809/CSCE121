#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(std::string student_id, std::string name){
    this->id = student_id;
    this->name = name;
}

void Student::addCourse(std::string course_id){
    course_ids.push_back(course_id);   
}

void Student::listCourses(){
    cout << "Courses for " << get_id() << endl;;
    for (int i = 0; i < this-> course_ids.size() - 1; i++){
        cout << course_ids.at(i) << endl;
    }
}