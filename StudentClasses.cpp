//
// Created by Madalena Ye on 29/10/2022.
//

#include "StudentClasses.h"
StudentClasses::StudentClasses() {
    studentCode = 0;
    studentName = "";
}
StudentClasses::StudentClasses(long int stc, string stn, list<ClassPerUC> cpuc){
    studentCode = stc;
    studentName = stn;
    cpu = cpuc;
}
int StudentClasses::get_studentCode(){return studentCode;}
string StudentClasses::get_studentName(){return studentName;}
list<ClassPerUC> StudentClasses::get_classPerUC() {return cpu;}
void StudentClasses::set_studentCode(long int stc){studentCode = stc;}
void StudentClasses::set_studentName(string stn){studentName = stn;}
void StudentClasses::set_ClassPerUC(list<ClassPerUC> cpu1) {cpu= cpu1;}