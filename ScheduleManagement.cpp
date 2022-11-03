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
#include <algorithm>
#include "Slot.h"
#include "Menu.h"

ScheduleManagement::ScheduleManagement() {
    students={};
    schedule={};
}

ScheduleManagement::ScheduleManagement(set<Student> stu, vector<Lecture> sch){
    students = stu;
    schedule = sch;
}
//getter
vector<Lecture> ScheduleManagement::get_schedule()  {return schedule;}
set<Student> ScheduleManagement::get_students() const {return students;}
//setter
void ScheduleManagement::set_students(set<Student> stu) {students=stu;}
void ScheduleManagement::set_auxStudents(vector<Student> stu) {auxStudents=stu;}
void ScheduleManagement::set_schedule(vector<Lecture> sch) {schedule=sch;}

void ScheduleManagement::readClasses(){

    string line;
    string classCode, ucCode, weekday, startHour, duration, type;
    ifstream inFile;

    //inFile.open("/Users/Utilizador/Desktop/aedprojeto/schedule/scheduleFiles/classes_per_uc.csv");
    //inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/classes_per_uc.csv");
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
        //inFile2.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/classes.csv");
        //inFile2.open("/Users/Utilizador/Desktop/naoseringa/schedule/scheduleFiles/classes.csv");
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

    //inFile.open("/Users/Utilizador/Desktop/aedprojeto/schedule/scheduleFiles/students_classes.csv");
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
        getline(is,classCode,'\r');
        cpu.push_back(ClassPerUC(ucCode,classCode));

    }
    for(auto it: students){auxStudents.push_back(it);}
    std::sort(auxStudents.begin(), auxStudents.end(),[](Student a, Student b){return a.get_studentName()<b.get_studentName();});
}

void ScheduleManagement::readClassesPerUC(){
    string line;
    string  ucCode, classCode;
    ifstream inFile;
    
    //inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/classes_per_uc.csv");
    inFile.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/classes_per_uc.csv");
    //inFile.open("/Users/Utilizador/Desktop/aedprojeto/schedule/scheduleFiles/classes_per_uc.csv");

    getline(inFile,line);
    vector<ClassPerUC> classes;
    ClassPerUC uc_class;
    while(getline(inFile,line)){
        stringstream is(line);
        getline(is,ucCode,',');
        getline(is,classCode,'\r');
        uc_class.set_ucCode(ucCode);
        uc_class.set_classCode(classCode);
        classes.push_back(uc_class);
    }
}

void ScheduleManagement::listingClassPerYear() {
    cout << "\nPretende ver as turmas de que ano? (1/2/3): ";
    string y; cin >> y;
    // input error
    while(!(y == "1" || y == "2" || y == "3")){

        cout << "There is no such class, please try again: ";
        cin >> y;
    }
    char year = y[0];
    set<string> classes;
    for(Lecture lecture: schedule){
        if(lecture.get_classCode()[0]==year){
            classes.insert(lecture.get_classCode());
        }
    }
    for(auto it:classes){
        cout<<it<<endl;
    }
    cout<<"Há "<< classes.size()<<" turmas no "<<year <<"º ano";
    cout << "\nDeseja realizar outra operação? (Y/N)? ";
    string answer; cin >> answer;
    while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
        cout << "Input inválido, tente novamente: ";
        cin >> answer;
    }
    if (answer == "Y" || answer == "y") createMenu();
    else return;
}
int weekDayToNum(string weekday){
    if (weekday =="Monday"){
        return 1;
    }
    if (weekday =="Tuesday"){
        return 2;
    }
    if (weekday =="Wednesday"){
        return 3;
    }
    if (weekday =="Thursday"){
        return 4;
    }
    if (weekday == "Friday") return 5;
    return 0;
}
void ScheduleManagement::listingStudentSchedule(string studentCode) const{
    struct find_by_studentCode{
        find_by_studentCode(long int code) : code(code) {}

        bool operator()(Student student) const{
            return student.get_studentCode() == code;
        }

    private:
        long int code;
    };
    auto student1 = std::find_if(students.begin(),students.end(),find_by_studentCode(stoul(studentCode)));
    vector<pair<ClassPerUC,Slot>> aux;
    for (ClassPerUC cpu: (*student1).get_classPerUC()) {
        for (Lecture lecture: schedule) {
            if (cpu.get_ucCode() == lecture.get_ucCode() && cpu.get_classCode() == lecture.get_classCode()) {
                for (Slot slot: lecture.get_Slot()){
                aux.emplace_back(ClassPerUC(cpu.get_ucCode(),cpu.get_classCode()),slot);}
            }
        }
    }
    std::sort(aux.begin(),aux.end(),[](pair<ClassPerUC,Slot> a, pair<ClassPerUC,Slot> b){
        return weekDayToNum(a.second.get_WeekDay()) < weekDayToNum(b.second.get_WeekDay()) || (weekDayToNum(a.second.get_WeekDay()) == weekDayToNum(b.second.get_WeekDay()) && a.second.get_StartHour() < b.second.get_StartHour());
    });
    for (auto it = aux.begin();it < aux.end();it++){
        cout << it->second.get_WeekDay() << endl;
        cout << it->first.get_ucCode() << " , " << it->first.get_classCode() << " , " << it->second.get_StartHour() << " , " << it->second.get_Duration() << " , " << it->second.get_Type() << endl;
    }
}
void ScheduleManagement::listingClassSchedule(string cl) {
    cout << "The class " << cl << " has the following schedule." << endl;
    vector<pair<string,Slot> >aux;
    for (Lecture lecture : schedule){
        if (lecture.get_classCode() == cl){
            for (Slot slot: lecture.get_Slot()){
                aux.emplace_back(lecture.get_ucCode(),slot);
            }
        }
    }
    std::sort(aux.begin(),aux.end(),[](pair<string,Slot> a ,pair<string,Slot> b){
        return weekDayToNum(a.second.get_WeekDay()) < weekDayToNum(b.second.get_WeekDay()) || (weekDayToNum(a.second.get_WeekDay()) == weekDayToNum(b.second.get_WeekDay()) && a.second.get_StartHour() < b.second.get_StartHour());
    ;});
    for (auto it = aux.begin();it < aux.end();it++){
        cout << it->second.get_WeekDay() << endl;
        cout << it->first << " , "  << it->second.get_StartHour() << " , " << it->second.get_Duration() << " , " << it->second.get_Type() << endl;
    }
}
void ScheduleManagement::listingUcSchedule(string uc) {
    cout << "The UC " << uc << " has the following schedule." << endl;
    vector<pair<string,Slot>> aux;
    for (Lecture lecture : schedule){
        if (lecture.get_ucCode() == uc){
            for (Slot slot: lecture.get_Slot()) {
                aux.emplace_back(uc,slot);
            }
        }
    }
    std::sort(aux.begin(),aux.end(),[](pair<string,Slot> a ,pair<string,Slot> b){
        return weekDayToNum(a.second.get_WeekDay()) < weekDayToNum(b.second.get_WeekDay()) || (weekDayToNum(a.second.get_WeekDay()) == weekDayToNum(b.second.get_WeekDay()) && a.second.get_StartHour() < b.second.get_StartHour());
        ;});
    for (auto it = aux.begin();it < aux.end();it++){
        cout << it->second.get_WeekDay() << endl;
        cout << it->first << " , "  << it->second.get_StartHour() << " , " << it->second.get_Duration() << " , " << it->second.get_Type() << endl;
    }
}

void ScheduleManagement::listingClasses(string order){

    if (order == "1") {
        set<string> classes;
        for (Lecture lecture: schedule) {
            classes.insert(lecture.get_classCode());
        }
        for (auto it: classes) {
            cout << it << endl;
        }
    }
    else{
        std::set<string, std::greater<string>> classes;
        for (Lecture lecture: schedule) {
            classes.insert(lecture.get_classCode());
        }
        for (auto it: classes) {
            cout << it << endl;
        }
    }
    cout << "\nDeseja realizar outra operação? (Y/N)? ";
    string answer; cin >> answer;
    while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
        cout << "Input inválido, tente novamente: ";
        cin >> answer;
    }
    if (answer == "Y" || answer == "y") createMenu();
    else return;

}

void ScheduleManagement::listingAllStudentsCode() {
    for(auto i:students){
        cout<<i.get_studentCode()<<"-"<<i.get_studentName()<<endl;
    }
}

void ScheduleManagement::listingAllStudentsName(){
    for(auto i:auxStudents){
        cout<<i.get_studentCode()<<"-"<<i.get_studentName()<<endl;
    }
}

void ScheduleManagement::listingStudentsInYear(char year){
    for(auto i:auxStudents){
        for(auto j:i.get_classPerUC()) {
            if ((int)j.get_classCode()[0] == year) {
                cout << i.get_studentCode() << "-" << i.get_studentName()<<endl;
                break;
            }
        }
    }
}
void ScheduleManagement::listingStudentsByYearOfEntry(int year){
    int count=0;
    for(auto i:students){
        if((int)(i.get_studentCode()/100000)==year){
            cout<<i.get_studentCode()<<"-"<<i.get_studentName()<<endl;
            count++;
        }
    }
    if(count==0) cout<<"There are no students who entered this year";
}

void ScheduleManagement::listingStudentsInClass(std::string _uc, std::string _class) {
    int count=0;
    for(auto i:auxStudents){
        for(auto j: i.get_classPerUC()){
            if(j.get_classCode()==_class && j.get_ucCode()==_uc){
                cout<<i.get_studentCode()<<"-"<<i.get_studentName()<<endl;
                count++;
            }
        }
    }
    if(count==0){cout<<"There are no students who attend this class";}
}