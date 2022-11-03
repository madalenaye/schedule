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
using namespace std;


//constructors
ScheduleManagement::ScheduleManagement() {
    students={};
    schedule={};
}
ScheduleManagement::ScheduleManagement(set<Student> stu, vector<Lecture> sch){
    students = stu;
    schedule = sch;
}
//getters
vector<Lecture> ScheduleManagement::get_schedule() {return schedule;}
queue<Request> ScheduleManagement::get_requests(){return requests;}
set<Student> ScheduleManagement::get_students() const {return students;}
//setters
void ScheduleManagement::set_schedule(vector<Lecture> sch) {schedule=sch;}
void ScheduleManagement::set_students(set<Student> stu) {students=stu;}
void ScheduleManagement::set_auxStudents(vector<Student> stu) {auxStudents=stu;}
//read files

void ScheduleManagement::readClasses(){

    string line;
    string classCode, ucCode, weekday, startHour, duration, type;
    ifstream inFile;

    inFile.open("/Users/Utilizador/Desktop/aedprojeto/schedule/scheduleFiles/classes_per_uc.csv");
    //inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/classes_per_uc.csv");
    //inFile.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/classes_per_uc.csv");


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
        inFile2.open("/Users/Utilizador/Desktop/naoseringa/schedule/scheduleFiles/classes.csv");
        //inFile2.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/classes.csv");
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

    inFile.open("/Users/Utilizador/Desktop/aedprojeto/schedule/scheduleFiles/students_classes.csv");
    //inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/students_classes.csv");
    //inFile.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/students_classes.csv");
    getline(inFile,line);
    //Reading the first line with actual data
    getline(inFile,line);
    stringstream is(line);
    getline(is,stCode,',');
    getline(is,stName,',');
    getline(is,ucCode,',');
    getline(is,classCode,'\r');
    string prevStCode=stCode;
    list<ClassPerUC> cpu;
    cpu.push_back(ClassPerUC(ucCode,classCode));
    Student st_class;
    st_class.set_ClassPerUC(cpu);
    st_class.set_studentCode(stoul(prevStCode));
    st_class.set_studentName(stName);
    students.insert(st_class);
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
    cpu.push_back(ClassPerUC(ucCode,classCode));
    st_class.set_ClassPerUC(cpu);
    st_class.set_studentCode(stoul(prevStCode));
    st_class.set_studentName(stName);
    students.insert(st_class);
    for(auto it: students){auxStudents.push_back(it);}
    std::sort(auxStudents.begin(), auxStudents.end(),[](Student a, Student b){return a.get_studentName()<b.get_studentName();});
}
vector<ClassPerUC> ScheduleManagement::readClassesPerUC(){
    string line;
    string ucCode, classCode;
    ifstream inFile;
    
    //inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/classes_per_uc.csv");
    //inFile.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/classes_per_uc.csv");"L.EIC010
    inFile.open("/Users/Utilizador/Desktop/aedprojeto/schedule/scheduleFiles/classes_per_uc.csv");

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
    return classes;
}

//listings of classes
void ScheduleManagement::listingClassPerYear() {
    cout << "Pretende ver as turmas de que ano? (1/2/3): ";
    string y; cin >> y;
    // input error
    while(!(y == "1" || y == "2" || y == "3")){

        cout << "Não há nenhuma turma nesse ano, tente novamente: ";
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
void ScheduleManagement::listingClassesPerUC(vector<ClassPerUC> v){
    cout << "Introduza o código da cadeira (L.EIC0XX - 2 dígitos / UPXXX - 3 dígitos): ";
    string uc; cin >> uc;
    // input error
    while(uc.length() < 2 || uc > "25"){

        cout << "Não há nenhuma UC com este código, tente novamente: ";
        cin >> uc;
    }
    string uni;
    if (uc == "001") uni = "UP" + uc;
    else uni = "L.EIC0" + uc;
    for (auto it: v){
        if (it.get_ucCode() == uni){ cout << it.get_classCode() << "\n";}
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
//listing of schedule
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
//listing of students
void ScheduleManagement::listingAllStudentsCode() {
    for(auto i:students){
        cout<<i.get_studentCode()<<" - "<<i.get_studentName()<<endl;
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
void ScheduleManagement::listingAllStudentsName(){
    for(auto i:auxStudents){
        cout<<i.get_studentName()<<"-"<<i.get_studentCode()<<endl;
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
void ScheduleManagement::listingStudentsInYear(){
    cout << "Pretende ver os alunos de que ano curricular? (1/2/3): ";
    string y; cin >> y;
    int count = 0;
    // input error
    while(!(y == "1" || y == "2" || y == "3")){

        cout << "Não há nenhum aluno nesse ano, tente novamente: ";
        cin >> y;
    }
    char year = y[0];
    for(auto i:auxStudents){
        for(auto j:i.get_classPerUC()) {
            if (j.get_classCode()[0] == year) {
                cout << i.get_studentCode() << "-" << i.get_studentName()<<endl;
                count++;
                break;
            }
        }
    }
    cout << "Há " << count << " alunos neste ano.\n";
    cout << "\nDeseja realizar outra operação? (Y/N)? ";
    string answer; cin >> answer;
    while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
        cout << "Input inválido, tente novamente: ";
        cin >> answer;
    }
    if (answer == "Y" || answer == "y") createMenu();
    else return;
}
void ScheduleManagement::listingStudentsByYearOfEntry(){
    cout << "Pretende ver os alunos de que ano de entrada? (2019/2020): ";
    string y; cin >> y;
    // input error
    while(!(y == "2019" || y == "2020")){

        cout << "Não há nenhum aluno que entrou nesse ano, tente novamente: ";
        cin >> y;
    }
    int year = stoi(y);
    int count=0;
    for(auto i:students){
        if((int)(i.get_studentCode()/100000)==year){
            cout<<i.get_studentCode()<<"-"<<i.get_studentName()<<endl;
            count++;
        }
    }
    if(count==0) cout << "Não há estudantes que entraram neste ano.";
    cout << "\nDeseja realizar outra operação? (Y/N)? ";
    string answer; cin >> answer;
    while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
        cout << "Input inválido, tente novamente: ";
        cin >> answer;
    }
    if (answer == "Y" || answer == "y") createMenu();
    else return;
}
void ScheduleManagement::listingStudentsInClass() {
    cout << "Pretende ver os alunos de que turma? (Ex: 1LEIC13/2LEIC01/3LEIC06): ";
    string _class; cin >> _class;
    cout << "De que unidade curricular? (Ex: L.EIC003): ";
    string _uc; cin >> _uc;
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
void ScheduleManagement::push_request(Request r) {
    requests.push(r);
}
void ScheduleManagement::removeStudent(long code,string _uc,string _class) {
    Student s;
    s.set_studentCode(code);
    const set<Student>::iterator &it = students.find(s);
    s.set_studentName(it->get_studentName());
    list<ClassPerUC> cpu;

    for(auto i: it->get_classPerUC()){
        if(i.get_ucCode()!=_uc && i.get_classCode()!=_class){
            cpu.push_back(ClassPerUC(i.get_ucCode(),i.get_classCode()));
        }
    }
    students.erase(it);
    s.set_ClassPerUC(cpu);
    students.insert(s);
    auxStudents.clear();
    for(auto it: students){auxStudents.push_back(it);}
    std::sort(auxStudents.begin(), auxStudents.end(),[](Student a, Student b){return a.get_studentName()<b.get_studentName();});
}
void ScheduleManagement::addStudent(long code, std::string _uc, std::string _cc) {
    Student s;
    s.set_studentCode(code);
    const set<Student>::iterator &it = students.find(s);
    s.set_studentName(it->get_studentName());
    list<ClassPerUC> cpu=it->get_classPerUC();
    if(studentsPerClass(_uc,_cc)<30)cpu.push_back(ClassPerUC(_uc,_cc));

    students.erase(it);
    s.set_ClassPerUC(cpu);
    students.insert(s);
    auxStudents.clear();
    for(auto it: students){auxStudents.push_back(it);}
    std::sort(auxStudents.begin(), auxStudents.end(),[](Student a, Student b){return a.get_studentName()<b.get_studentName();});
}
void ScheduleManagement::changeStudentclass(long code, string _uc, string _class, string new_class) {
    Student s;
    s.set_studentCode(code);
    const set<Student>::iterator &it = students.find(s);
    s.set_studentName(it->get_studentName());
    list<ClassPerUC> cpu;

    for(auto i: it->get_classPerUC()){
        if(i.get_ucCode()!=_uc && i.get_classCode()!=_class){
            cpu.push_back(ClassPerUC(i.get_ucCode(),i.get_classCode()));
        }else if(studentsPerClass(_uc,new_class)<30){
            cpu.push_back(ClassPerUC(_uc,new_class));
        }
    }

    students.erase(it);
    s.set_ClassPerUC(cpu);
    students.insert(s);
    auxStudents.clear();
    for(auto it: students){auxStudents.push_back(it);}
    std::sort(auxStudents.begin(), auxStudents.end(),[](Student a, Student b){return a.get_studentName()<b.get_studentName();});
}
void ScheduleManagement::doRequest(){
    Request req;
    req=requests.front();
    requests.pop();
    if(req.getType()==REMOVE){
        removeStudent(req.getStudentCode(),req.getUc(),req.getClass());
    }
    if(req.getType()==ADD){
        addStudent(req.getStudentCode(),req.getUc(),req.getClass());
    }
    if(req.getType()==CHANGE_CLASS){
        changeStudentclass(req.getStudentCode(),req.getUc(),req.getClass(),req.getNewClass());
    }
}
int ScheduleManagement::studentsPerClass(string u, string c) {
    int count=0;
    for(auto i: students){
        for(auto j: i.get_classPerUC()){
            if(j.get_classCode() == c && j.get_ucCode()== u){
                count++;
            }
        }
    }
    return count;
}
void ScheduleManagement::listingStudentsWithNUCs(){
    cout << "Estudantes com mais de quantas UCs? ";
    int n; cin >> n;
    int count = 0;

    for (Student student : auxStudents){
        count = student.get_classPerUC().size();
        if (count >= n){
            cout << student.get_studentName() << "\n";
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
void ScheduleManagement::listingAllUCs(string order, vector<ClassPerUC> v){
    if (order == "1") {
        set<string> ucs;
        for (auto it: v) {
            ucs.insert(it.get_ucCode());
        }
        for (auto it: ucs) {
            cout << it << endl;
        }
    }
    else{
        std::set<string, std::greater<string>> ucs;
        for (auto it: v) {
            ucs.insert(it.get_ucCode());
        }
        for (auto it: ucs) {
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
void ScheduleManagement::listingUCsByYear(){
    cout << "Pretende ver as UCs de que ano? (1/2/3): ";
    string y; cin >> y;
    // input error
    while(!(y == "1" || y == "2" || y == "3")){

        cout << "Não há nenhuma UC nesse ano, tente novamente: ";
        cin >> y;
    }
    char year = y[0];
    set<string> UCs;
    for(Lecture lecture: schedule){
        if(lecture.get_classCode()[0]==year){
            UCs.insert(lecture.get_ucCode());
        }
    }
    for(auto it:UCs){
        cout<<it<<endl;
    }
    cout<<"Há "<< UCs.size()<<" UCs no "<<year <<"º ano";
    cout << "\nDeseja realizar outra operação? (Y/N)? ";
    string answer; cin >> answer;
    while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
        cout << "Input inválido, tente novamente: ";
        cin >> answer;
    }
    if (answer == "Y" || answer == "y") createMenu();
    else return;

}
void ScheduleManagement::listingUcsPerStudent() {
    cout << "Escolha o modo de pesquisa de UCs por estudante: \n" << "1. Número UP\n" << "2. Nome\n";
    cout << "Opção: ";
    string mode; cin >> mode;
    while (!(mode == "1" || mode == "2")){
        cout << "Input inválido, tente novamente: ";
        cin >> mode;
    }
    if (mode == "1"){
        cout << "Introduza o número UP (Ex: 202041977): ";
        long int up; cin >> up;
        for (Student it: students){
            if (it.get_studentCode() == up){
                cout << up << ": ";
                for (auto i: it.get_classPerUC()){
                    cout << i.get_ucCode() << ",";
                }
                cout<<'\b';  //Cursor moves 1 position backwards
                cout<<" ";
            }

        }
    }
    else{
        cout << "Introduza o nome do aluno: ";
        string name; cin >> name;
        for (Student student : students){
            if (student.get_studentName() == name){
                cout << name << ": ";
                for (auto it: student.get_classPerUC()){
                    cout << it.get_ucCode() << ",";
                }
                cout<<'\b';  //Cursor moves 1 position backwards
                cout<<" ";
            }
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
void ScheduleManagement::listingUcsByClass() {
    cout << "Introduza a turma (Ex: 1LEIC01): ";
    string _class; cin >> _class;
    vector<ClassPerUC> v = readClassesPerUC();
    cout << _class << ": ";
    for (auto it : v){
        if (it.get_classCode() == _class){
            cout << it.get_ucCode() << ",";
        }
    }
    cout<<'\b';  //Cursor moves 1 position backwards
    cout<<" ";
    cout << "\nDeseja realizar outra operação? (Y/N)? ";
    string answer; cin >> answer;
    while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
        cout << "Input inválido, tente novamente: ";
        cin >> answer;
    }
    if (answer == "Y" || answer == "y") createMenu();
    else return;
}

