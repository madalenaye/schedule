//
// Created by sereno on 28-10-2022.
//

#ifndef PROJETOAED_LECTURE_H
#define PROJETOAED_LECTURE_H

#include <string>
using namespace std;

class Lecture{
public:
    //constructors
    Lecture();
    Lecture(string uc,string cc,string wd,float sh,float dur,string t);
    //getters
    string get_ucCode();
    string get_classCode();
    string get_weekday();
    float get_startHour();
    float get_duration();
    string get_type();
    //setters
    void set_ucCode(string uc);
    void set_classCode(string cc);
    void set_weekday(string wd);
    void set_startHour(float sh);
    void set_duration(float dur);
    void set_type(string t);

private:
    string ucCode;
    string classCode;
    string weekday;
    float startHour;
    float duration;
    string type;
};


#endif //PROJETOAED_LECTURE_H
