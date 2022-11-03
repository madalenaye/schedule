//
// Created by sereno on 28-10-2022.
//
#ifndef PROJETOAED_STUDENTCLASSES_H
#define PROJETOAED_STUDENTCLASSES_H

#include <queue>
#include <string>
#include "ClassPerUC.h"
#include <list>
#include <set>


using namespace std;

class Student{
public:
    Student();
    Student(long int stc , string stn, list<ClassPerUC> cpu);
    int get_studentCode() const;
    string get_studentName() const;
    list<ClassPerUC> get_classPerUC() const;
    //setters
    void set_studentCode(long int stc);
    void set_studentName(string stn);
    void set_ClassPerUC(list<ClassPerUC> cpu);
    //seekers
    const bool operator<( Student P) const
    {
        return (studentCode < P.get_studentCode());
    }

    bool operator==(const Student &rhs) const;

    bool operator!=(const Student &rhs) const;

private:
    long int studentCode;
    string studentName;
    list<ClassPerUC> cpu;
};

#endif //PROJETOAED_STUDENTCLASSES_H
