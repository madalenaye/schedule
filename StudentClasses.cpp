//
// Created by Madalena Ye on 29/10/2022.
//

#include "StudentClasses.h"
Student::Student() {
    studentCode = 0;
    studentName = "";
}
Student::Student(long int stc, string stn, list<ClassPerUC> cpuc){
    studentCode = stc;
    studentName = stn;
    cpu = cpuc;
}
int Student::get_studentCode(){return studentCode;}
string Student::get_studentName(){return studentName;}
list<ClassPerUC> Student::get_classPerUC() {return cpu;}
void Student::set_studentCode(long int stc){studentCode = stc;}
void Student::set_studentName(string stn){studentName = stn;}
void Student::set_ClassPerUC(list<ClassPerUC> cpu1) {cpu= cpu1;}
