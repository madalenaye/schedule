//
// Created by Madalena Ye on 30/10/2022.
//

#ifndef SCHEDULE_SCHEDULEMANAGEMENT_H
#define SCHEDULE_SCHEDULEMANAGEMENT_H

#include "Student.h"
#include "Lecture.h"
#include <set>
#include <vector>
class ScheduleManagement{
public:
    //constructors
    ScheduleManagement();
    ScheduleManagement(set<Student> stu, vector<Lecture> sch);
    //getters
    set<Student> get_students();
    vector<Lecture> get_schedule();
    //setters
    void set_students(set<Student> stu);
    void set_schedule(vector<Lecture> sch);
    //readers
    void readClasses();
    void readStudents();
    void readClassesPerUC();
    //listing
    void listingClassPerYear(char year);
    void listingStudentSchedule(string studentCode);
    void listingClassSchedule(string cl);
    void listingUcSchedule(string uc);
private:
    set<Student> students;
    vector<Lecture> schedule;
};

#endif //SCHEDULE_SCHEDULEMANAGEMENT_H
