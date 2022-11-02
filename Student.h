//
// Created by sereno on 28-10-2022.
//
#ifndef PROJETOAED_STUDENTCLASSES_H
#define PROJETOAED_STUDENTCLASSES_H

#include <string>
#include "ClassPerUC.h"
#include <list>
#include "ClassPerUC.h"
#include <set>


using namespace std;

class Student{
public:
    //constructors
    Student();
    Student(long int stc , string stn, list<ClassPerUC> cpuc);
    //getters
    int get_studentCode() const;
    string get_studentName() const;
    list<ClassPerUC> get_classPerUC();
    //setters
    void set_studentCode(long int stc);
    void set_studentName(string stn);
    void set_ClassPerUC(list<ClassPerUC> cpu1);
    //operator overloading
    const bool operator<( Student P) const
    {
        return (studentCode < P.get_studentCode());
    }
private:
    long int studentCode;
    string studentName;
    list<ClassPerUC> cpu;
};

#endif //PROJETOAED_STUDENTCLASSES_H
