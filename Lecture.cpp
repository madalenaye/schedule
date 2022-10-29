//
// Created by Madalena Ye on 29/10/2022.
//

#include "Lecture.h"

Lecture::Lecture() {
    ucCode = "";
    classCode = "";
    weekday = "";
    startHour = 0.0;
    duration = 0.0;
    type = "";
}
Lecture::Lecture(string uc, string cc, string wd, float sh, float dur, string t){
    ucCode= uc;
    classCode = cc;
    weekday = wd;
    startHour = sh;
    duration = dur;
    type = t;
}
//getters
string Lecture::get_ucCode(){return ucCode;}
string Lecture::get_classCode(){return classCode;}
string Lecture::get_weekday(){return weekday;}
float Lecture::get_startHour(){return startHour;}
float Lecture::get_duration(){return duration;}
string Lecture::get_type(){return type;}
//setters
void Lecture::set_ucCode(string uc){ucCode=uc;}
void Lecture::set_classCode(string cc){classCode=cc;}
void Lecture::set_weekday(string wd){weekday=wd;}
void Lecture::set_startHour(float sh){startHour=sh;}
void Lecture::set_duration(float dur){duration=dur;}
void Lecture::set_type(string t){type=t;}