//
// Created by sereno on 28-10-2022.
//

#ifndef PROJETOAED_LECTURE_H
#define PROJETOAED_LECTURE_H

#include <string>
#include "Slot.h"
#include <list>

using namespace std;

class Lecture{
public:
    //constructors
    Lecture();
    Lecture(string uc,string cc,list<Slot> slt);
    //getters
    string get_ucCode();
    string get_classCode();
    list<Slot> get_Slot();
    //setters
    void set_ucCode(string uc);
    void set_classCode(string cc);
    void set_Slot(list<Slot> slt);

private:
    string ucCode;
    string classCode;
    list<Slot> slots;
};


#endif //PROJETOAED_LECTURE_H
