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
#include "Slot.cpp"

using namespace std;

void readClasses(){

    string line;
    string classCode, ucCode, weekday, startHour, duration, type;
    ifstream inFile;
    inFile.open("/Users/Utilizador/Desktop/naoseringa/schedule/scheduleFiles/classes_per_uc.csv");

    getline(inFile,line);
    Lecture lecture;
    vector<Lecture> lectures;
    list<Slot> slots;
    //Slot slot;
    while(getline(inFile,line)){
        stringstream is(line);
        getline(is,ucCode,',');
        getline(is,classCode,'\r');
        string line2;
        ifstream inFile2;
        inFile2.open("/Users/Utilizador/Desktop/naoseringa/schedule/scheduleFiles/classes.csv");
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
        lectures.push_back(lecture);
        slots.clear();
    }
    for (auto i:lectures){
        auto j = i.get_Slot();
        cout << i.get_classCode() << '-' << i.get_ucCode() << ':' << j.size()<< endl;
    }
}

void readStudents(){
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
    vector<Student> st_classes;
    list<ClassPerUC> cpu;
    Student st_class;
    while(getline(inFile,line)){
        stringstream is(line);
        getline(is,stCode,',');
        if(prevStCode != stCode){
            st_class.set_ClassPerUC(cpu);
            st_class.set_studentCode(stoul(prevStCode));
            st_class.set_studentName(stName);
            st_classes.push_back(st_class);
            cpu.clear();
            prevStCode = stCode;
        }
        getline(is,stName,',');
        getline(is,ucCode,',');
        getline(is,classCode,',');
        cpu.push_back(ClassPerUC(ucCode,classCode));

    }
    /*for (auto i: st_classes){
        auto j = i.get_classPerUC();
        cout << i.get_studentName() << "-" <<  j.size() << endl;
    }*/
}
void readClassesPerUC(){
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
    cout << classes[5].get_ucCode() << " " << classes[5].get_classCode() << endl;
}