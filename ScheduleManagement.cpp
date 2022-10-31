//
// Created by Madalena Ye on 30/10/2022.
//

#include "ScheduleManagement.h"
#include "Lecture.h"
#include "ClassPerUC.h"
#include "Student.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include "Slot.cpp"

ScheduleManagement::ScheduleManagement() {
    students={};
    schedule={};
}

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
void ScheduleManagement::readClasses(){

    string line;
    string classCode, ucCode, weekday, startHour, duration, type;
    ifstream inFile;
    inFile.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/classes_per_uc.csv");

    getline(inFile,line);
    Lecture lecture;
    list<Slot> slots;
    //Slot slot;
    while(getline(inFile,line)){
        stringstream is(line);
        getline(is,ucCode,',');
        getline(is,classCode,'\r');
        string line2;
        ifstream inFile2;
        inFile2.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/classes.csv");
        getline(inFile2,line2);
        string cc,uc;
        while (getline(inFile2,line2)){

            stringstream os(line2);
            getline(os,cc,',');
            getline(os,uc,',');
            getline(os,weekday,',');
            getline(os,startHour,',');
            getline(os,duration,',');
            getline(os,type,',');
            if ( uc == ucCode && cc == classCode ){
                slots.push_back(Slot(weekday,stod(startHour),stod(duration),type));
            }
        }
        lecture.set_classCode(classCode);
        lecture.set_ucCode(ucCode);
        lecture.set_Slot(slots);
        schedule.push_back(lecture);
        slots.clear();
    }
}

void ScheduleManagement::readStudents(){
    string line;
    string stCode, stName, ucCode, classCode;
    ifstream inFile;
    //inFile.open("/Users/Utilizador/Desktop/naoseringa/schedule/scheduleFiles/students_classes.csv");
    //inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/students_classes.csv");
    inFile.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/students_classes.csv");
    getline(inFile,line);
    //Reading the first line with actual data
    getline(inFile,line);
    stringstream is(line);
    getline(is,stCode,',');
    getline(is,stName,',');
    getline(is,ucCode,',');
    getline(is,classCode,',');
    string prevStCode=stCode;
    //set<Student> st_classes;
    list<ClassPerUC> cpu;
    Student st_class;
    while(getline(inFile,line)){
        stringstream is(line);
        getline(is,stCode,',');
        if(prevStCode != stCode){
            st_class.set_ClassPerUC(cpu);
            st_class.set_studentCode(stoul(prevStCode));
            st_class.set_studentName(stName);
            students.insert(st_class);
            cpu.clear();
            prevStCode = stCode;
        }
        getline(is,stName,',');
        getline(is,ucCode,',');
        getline(is,classCode,',');
        cpu.push_back(ClassPerUC(ucCode,classCode));

    }
}
void ScheduleManagement::readClassesPerUC(){
    string line;
    string stCode, stName, ucCode, classCode;
    ifstream inFile;
    //inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/classes_per_uc.csv");
    inFile.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/classes_per_uc.csv");
    //inFile.open("/Users/Utilizador/Desktop/naoseringa/schedule/scheduleFiles/classes_per_uc.csv");
    getline(inFile,line);
    vector<ClassPerUC> classes;
    ClassPerUC uc_class;
    while(getline(inFile,line)){
        stringstream is(line);
        getline(is,ucCode,',');
        getline(is,classCode,',');
        uc_class.set_ucCode(ucCode);
        uc_class.set_classCode(classCode);
        classes.push_back(uc_class);
    }
}
void ScheduleManagement::listingClassPerYear(char year) {

    set<string> classes;
    for(Lecture lecture: schedule){
        if(lecture.get_classCode()[0]==year){
            classes.insert(lecture.get_classCode());
        }
    }
    for(auto it:classes){
        cout<<it<<endl;
    }
    cout<<"There are "<< classes.size()<<" classes in year "<<year;
}