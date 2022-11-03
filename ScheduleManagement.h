//
// Created by Madalena Ye on 30/10/2022.
//
#ifndef SCHEDULE_SCHEDULEMANAGEMENT_H
#define SCHEDULE_SCHEDULEMANAGEMENT_H

#include "Student.h"
#include "ClassPerUC.h"
#include "Lecture.h"
#include "Request.h"
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
    queue<Request> get_requests();
    //setters
    void set_students(set<Student> stu);
    void set_auxStudents(vector<Student> stu);
    void set_schedule(vector<Lecture> sch);
    //readers
    void readClasses();
    void readStudents();
    vector<ClassPerUC> readClassesPerUC();
    //listing classes
    void listingClassPerYear();
    void listingClasses(string order);
    void listingClassesPerUC(vector<ClassPerUC> v);
    //listing schedule
    void listingClassSchedule();
    void listingUcSchedule();
    void listingStudentSchedule() const;
    //listing students
    void listingAllStudentsCode();
    void listingAllStudentsName();
    void listingStudentsInYear();
    void listingStudentsByYearOfEntry();
    void listingStudentsInClass();
    void listingStudentsWithNUCs();
    //listing ucs
    void listingAllUCs(string order, vector<ClassPerUC> v);
    void listingUCsByYear();
    void listingUcsPerStudent();
    void listingUcsByClass();
    //requests
    void removeStudent(long code, string _uc, string _cc);
    void addStudent(long code, string _uc, string _cc);
    void changeStudentclass(long code, string _uc, string _class,string new_class);
    void push_request(Request r);
    void doRequest();
    //counters
    int studentsPerClass(string _uc,string _class);

private:
    set<Student> students;
    vector<Student> auxStudents;
    vector<Lecture> schedule;
    queue<Request> requests;
};

#endif //SCHEDULE_SCHEDULEMANAGEMENT_H
