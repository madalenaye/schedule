//
// Created by Madalena Ye on 30/10/2022.
//

#include "ScheduleManagement.h"

ScheduleManagement::ScheduleManagement(set<Student> stu, vector<Lecture> sch){
    students = stu;
    schedule = sch;
}
//getter
vector<Lecture> ScheduleManagement::get_schedule() {return schedule;}
set<Student> ScheduleManagement::get_students() {return students;}
//setter
void ScheduleManagement::set_schedule(vector<Lecture> sch) {schedule=sch;}
void ScheduleManagement::set_students(set<Student> stu) {students=stu;}