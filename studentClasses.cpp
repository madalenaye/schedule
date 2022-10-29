//
// Created by sereno on 28-10-2022.
//

#include "studentClasses.h"
studentsClass::studentsClass() {
    studentCode=0;
    studentName="";
    ucCode="";
    classCode="";
}
studentsClass::studentsClass(int stc,string stn, string ucc, string cc){
    studentCode=stc;
    studentName=stn;
    ucCode=ucc;
    classCode=cc;
}
int studentsClass::get_studentCode(){return studentCode;}
string studentsClass::get_studentName(){return studentName;}
string studentsClass::get_ucCode(){return ucCode;}
string studentsClass::get_classCode(){return classCode;}
void studentsClass::set_studentCode(int stc){studentCode=stc;}
void studentsClass::set_studentName(string stn){studentName=stn;}
void studentsClass::set_ucCode(string uc){ucCode=uc;}
void studentsClass::set_classCode(string cc){classCode=cc;}
