//
// Created by Madalena Ye on 29/10/2022.
//

#include "Student.h"
Student::Student() {
    studentCode = 0;
    studentName = "";
}
Student::Student(long int stc, string stn, list<ClassPerUC> cpuc){
    studentCode = stc;
    studentName = stn;
    this->cpu = cpu;
}
int Student::get_studentCode() const {return studentCode;}
string Student::get_studentName() const {return studentName;}
list<ClassPerUC> Student::get_classPerUC() {return cpu;}
void Student::set_studentCode(long int stc){studentCode = stc;}
void Student::set_studentName(string stn){studentName = stn;}
void Student::set_ClassPerUC(list<ClassPerUC> cpu) {this->cpu= cpu;}
