//
// Created by Madalena Ye on 29/10/2022.
//
#include "Lecture.h"
#include "ClassPerUC.h"
#include "StudentClasses.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include "ReadFiles.h"

using namespace std;

void readClasses(){

    string line;
    string classCode, ucCode, weekday, startHour, duration, type;
    ifstream inFile;
    inFile.open("/Users/madalenaye/Downloads/AED/Project/schedule/scheduleFiles/classes.csv");
    getline(inFile,line);
    Lecture lecture;
    vector<Lecture> lectures;
    while(getline(inFile,line)){
        stringstream is(line);
        getline(is,classCode,',');
        getline(is,ucCode,',');
        getline(is,weekday,',');
        getline(is,startHour,',');
        getline(is,duration,',');
        getline(is,type,',');
        lecture.set_classCode(classCode);
        lecture.set_ucCode(ucCode);
        lecture.set_weekday(weekday);
        lecture.set_startHour(stof(startHour));
        lecture.set_duration(stof(duration));
        lecture.set_type(type);
        lectures.push_back(lecture);

    }
}

void readStudentClasses(){
    string line;
    string stCode, stName, ucCode, classCode;
    ifstream inFile;
    inFile.open("/Users/madalenaye/Downloads/AED/Project/schedule/scheduleFiles/students_classes.csv");
    getline(inFile,line);
    vector<StudentClasses> st_classes;
    list<ClassPerUC> cpu;
    StudentClasses st_class;
    string testline="";
    while(getline(inFile,line)){
        stringstream is(line);
        getline(is,stCode,',');
        if (testline == ""){
            testline = stCode;
        }
        else if(testline != stCode){
            st_class.set_ClassPerUC(cpu);
            st_class.set_studentCode(stoul(testline));
            st_class.set_studentName(stName);
            st_classes.push_back(st_class);
            cpu.clear();
            testline = stCode;
        }
        getline(is,stName,',');
        getline(is,ucCode,',');
        getline(is,classCode,',');
        cpu.push_back(ClassPerUC(ucCode,classCode));

    }
}
void readClassesPerUC(){
    string line;
    string stCode, stName, ucCode, classCode;
    ifstream inFile;
    inFile.open("/Users/madalenaye/Downloads/AED/Project/schedule/scheduleFiles/classes_per_uc.csv");
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
    cout << classes[5].get_ucCode() << " " << classes[5].get_classCode() << endl;
}