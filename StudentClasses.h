//
// Created by sereno on 28-10-2022.
//
#ifndef PROJETOAED_STUDENTCLASSES_H
#define PROJETOAED_STUDENTCLASSES_H

#include <string>
#include "ClassPerUC.h"
#include <list>
#include "ClassPerUC.h"


using namespace std;
class StudentClasses{
public:
    StudentClasses();
    StudentClasses(long int stc , string stn, list<ClassPerUC> cpuc);
    int get_studentCode();
    string get_studentName();
    list<ClassPerUC> get_classPerUC();
    //setters
    void set_studentCode(long int stc);
    void set_studentName(string stn);
    void set_ClassPerUC(list<ClassPerUC> cpu1);

private:
    long int studentCode;
    string studentName;
    list<ClassPerUC> cpu;
};

#endif //PROJETOAED_STUDENTCLASSES_H
