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
    set<Student> get_students() const;
    vector<Lecture> get_schedule();
    //setters
    void set_students(set<Student> stu);
    void set_schedule(vector<Lecture> sch);
    //readers
    void readClasses();
    void readStudents();
    void readClassesPerUC();
    //listing
    void listingClassPerYear();
    void listingStudentSchedule(string studentCode) const;
    void listingClassSchedule(string cl) ;
    void listingUcSchedule(string uc);
    void listingClasses(string order);
    void listingAllStudentsCode();
    void listingAllStudentsName();
private:
    set<Student> students;
    vector<Lecture> schedule;
};

#endif //SCHEDULE_SCHEDULEMANAGEMENT_H
