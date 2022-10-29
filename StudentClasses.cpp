//
// Created by Madalena Ye on 29/10/2022.
//

#include "StudentClasses.h"
StudentClasses::StudentClasses() {
    studentCode = 0;
    studentName = "";
    ucCode = "";
    classCode = "";
}
StudentClasses::StudentClasses(long int stc, string stn, string ucc, string cc){
    studentCode = stc;
    studentName = stn;
    ucCode = ucc;
    classCode = cc;
}
int StudentClasses::get_studentCode(){return studentCode;}
string StudentClasses::get_studentName(){return studentName;}
string StudentClasses::get_ucCode(){return ucCode;}
string StudentClasses::get_classCode(){return classCode;}
void StudentClasses::set_studentCode(long int stc){studentCode = stc;}
void StudentClasses::set_studentName(string stn){studentName = stn;}
void StudentClasses::set_ucCode(string uc){ucCode = uc;}
void StudentClasses::set_classCode(string cc){classCode = cc;}
