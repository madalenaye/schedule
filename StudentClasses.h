//
// Created by sereno on 28-10-2022.
//
#ifndef PROJETOAED_STUDENTCLASSES_H
#define PROJETOAED_STUDENTCLASSES_H

#include <string>
#include "ClassPerUC.h"
#include <list>
using namespace std;
class StudentClasses{
public:
    StudentClasses();
    StudentClasses(long int stc , string stn, string ucc, string cc);
    int get_studentCode();
    string get_studentName();
    string get_ucCode();
    string get_classCode();
    //setters
    void set_studentCode(long int stc);
    void set_studentName(string stn);
    void set_ucCode(string uc);
    void set_classCode(string cc);

private:
    long int studentCode;
    string studentName;
    list <ClassPerUC> clas;
};

#endif //PROJETOAED_STUDENTCLASSES_H
