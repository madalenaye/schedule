#include "Lecture.cpp"
#include "Lecture.h"
#include "classperUC.cpp"
#include "studentClasses.cpp"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string line;
    string ucCode,classCode,weekday,startHour,duration,type;

    ifstream inFile;
    inFile.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFIles/classes.csv");
    getline(inFile,line);
    Lecture lecture;
    vector<Lecture> lectures;
    while(getline(inFile,line)){
        stringstream is(line);
        getline(is,ucCode,',');
        getline(is,classCode,',');
        getline(is,weekday,',');
        getline(is,startHour,',');
        getline(is,duration,',');
        getline(is,type,',');
        lecture.set_ucCode(ucCode);
        lecture.set_classCode(classCode);
        lecture.set_weekday(weekday);
        lecture.set_startHour(stof(startHour));
        lecture.set_duration(stof(duration));
        lecture.set_type(type);
        lectures.push_back(lecture);

    }
    for (Lecture i: lectures){
        cout << i.get_classCode() << endl;
    }
}