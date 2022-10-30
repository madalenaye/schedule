//
// Created by sereno on 30-10-2022.
//

#ifndef SCHEDULE_SLOT_H
#define SCHEDULE_SLOT_H
#include <string>
using namespace std;
class Slot {
public:
    Slot();
    Slot(string wd,double sh,double d,string tp);
    string get_WeekDay();
    double get_StartHour();
    double get_Duration();
    string get_Type();
    void set_WeekDay(string wd);
    void set_StartHour(double sh);
    void set_Duration(double d);
    void set_Type(string tp);
private:
    string weekday;
    double startHour;
    double duration;
    string type;
};


#endif //SCHEDULE_SLOT_H
