//
// Created by Madalena Ye on 29/10/2022.
//

#include <algorithm>
#include "Student.h"
//constructors
Student::Student() {
    studentCode = 0;
    studentName = "";
}
Student::Student(long int stc, string stn, list<ClassPerUC> cpu){
    studentCode = stc;
    studentName = stn;
    this->cpu = cpu;
}
//getters and setters
int Student::get_studentCode() const {return studentCode;}
string Student::get_studentName() const {return studentName;}
list<ClassPerUC> Student::get_classPerUC() const {return cpu;}

void Student::set_studentCode(long int stc){studentCode = stc;}
void Student::set_studentName(string stn){studentName = stn;}
void Student::set_ClassPerUC(list<ClassPerUC> cpu) {this->cpu= cpu;}

bool Student::operator==(const Student &rhs) const {
    return studentCode == rhs.studentCode;
}

bool Student::operator!=(const Student &rhs) const {
    return !(rhs == *this);
}
