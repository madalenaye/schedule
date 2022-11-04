//
// Created by sereno on 30-10-2022.
//

#include "Slot.h"
/**
 * Construtor pré-definido dos slots.
 */
Slot::Slot(){
    weekday="";
    startHour=0.0;
    duration=0.0;
    type="";
}
/**
 * Construtor parametrizado dos slots.
 * @param wd
 * @param sh
 * @param d
 * @param tp
 */
Slot::Slot(string wd,double sh,double d,string tp){
    weekday=wd;
    startHour=sh;
    duration=d;
    type=tp;
}
string Slot::get_WeekDay(){
    return weekday;
}
double Slot::get_StartHour() {
    return startHour;
}
double Slot::get_Duration(){
    return duration;
}
string Slot::get_Type(){
    return type;
}
void Slot::set_WeekDay(string wd){
    weekday=wd;
}
void Slot::set_StartHour(double sh){
    startHour=sh;
}
void Slot::set_Duration(double d){
    duration=d;
}
void Slot::set_Type(string tp){
    type=tp;
}