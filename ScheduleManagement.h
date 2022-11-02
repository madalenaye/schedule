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
    vector<Student> get_auxStudents();
    vector<Lecture> get_schedule();
    //setters
    void set_students(set<Student> stu);
    void set_auxStudents(vector<Student> stu);
    void set_schedule(vector<Lecture> sch);
    //readers
    void readClasses();
    void readStudents();
    void readClassesPerUC();
    //listing
    void listingClassPerYear();
    void listingStudentSchedule(string studentCode);
    void listingClassSchedule(string cl);
    void listingUcSchedule(string uc);
    void listingClasses(string order);
    //listing students
    void listingAllStudentsCode();
    void listingAllStudentsName();
    void listingStudentsInYear(char year);
    void listingStudentsByYearOfEntry(int year);
    void listingStudentsInClass(string _uc,string _class);


private:
    set<Student> students;
    vector<Student> auxStudents;
    vector<Lecture> schedule;
};

#endif //SCHEDULE_SCHEDULEMANAGEMENT_H
