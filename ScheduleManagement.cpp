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
/**
 * Construtor default.
 */
ScheduleManagement::ScheduleManagement(){
    students={};
    schedule={};
    requests={};
    invalid_requests={};
}
/**
 * Construtor parametrizado.
 * @param stu - set de estudantes.
 * @param sch - vetor com horário de turmas/UCs.
 */
ScheduleManagement::ScheduleManagement(set<Student> stu, vector<Lecture> sch){
    students = stu;
    schedule = sch;
}
//getters
/**
 * Obtém o horário das turmas por UC.
 * Complexidade: O(1)
 * @return vetor do horário das turmas por cada cadeira.
 */
vector<Lecture> ScheduleManagement::get_schedule() {return schedule;}
/**
 * Obtém uma fila para processar os pedidos.
 * Complexidade: O(1)
 * @return vetor com horários.
 */
queue<Request> ScheduleManagement::get_requests(){return requests;}
/**
 * Obtém os estudantes.
 * Complexidade: O(1)
 * @return set com estudantes.
 */
set<Student> ScheduleManagement::get_students() const {return students;}
/**
 * Obtém o vetor de pedidos inválidos.
 * Complexidade: O(1)
 * @return vetor com pedidos inválidos.
 */
vector<Request> ScheduleManagement::get_invalidRequests() {return invalid_requests;}
//setters
/**
 * Define o horário das turmas/UCs com o parâmetro sch.
 * Complexidade: O(1)
 * @param sch
 */
void ScheduleManagement::set_schedule(vector<Lecture> sch) {schedule=sch;}
/**
 * Define o set de estudantes com o parâmetro stu.
 * Complexidade: O(1)
 * @param stu
 */
void ScheduleManagement::set_students(set<Student> stu) {students=stu;}
/**
 * Define um vetor auxiliar de estudantes com o parâmetro stu.
 * Complexidade: O(1)
 * @param stu
 */
void ScheduleManagement::set_auxStudents(vector<Student> stu) {auxStudents=stu;}

//read files
/**
 * Lê o ficheiro "classes.csv" e guarda os elementos em diferentes atributos da classe Lecture.
 * Complexidade: O(n*m), n->ler o ficheiro "classes_per_uc.csv", m->ler o ficheiro "classes.csv"
 */
void ScheduleManagement::readClasses(){

    string line;
    string classCode, ucCode, weekday, startHour, duration, type;
    ifstream inFile;

    //inFile.open("/Users/Utilizador/Desktop/aedprojeto/schedule/scheduleFiles/classes_per_uc.csv");
    inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/classes_per_uc.csv");
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
        inFile2.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/classes.csv");
        //inFile2.open("/Users/Utilizador/Desktop/aedprojeto/schedule/scheduleFiles/classes.csv");
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
            getline(os,type,'\r');
            if ( uc == ucCode && cc == classCode ){
                slots.push_back(Slot(weekday,stod(startHour),stod(duration),type));
            }
        }
        lecture.set_classCode(classCode);
        lecture.set_ucCode(ucCode);
        lecture.set_Slot(slots);
        schedule.push_back(lecture);
        slots.clear();
        inFile2.close();
    }
    inFile.close();
}
/**
 * Lê o ficheiro "students_classes.csv" e guarda os elementos em diferentes atributos da classe Student.
 * Complexidade: O(n), n->tamanho do set de estudantes.
 * @param filename determina se é para ler o ficheiro inicial ou o atualizado depois das alterações.
 */
void ScheduleManagement::readStudents(string filename){
    string line;
    string stCode, stName, ucCode, classCode;
    ifstream inFile;

    //inFile.open("/Users/Utilizador/Desktop/aedprojeto/schedule/scheduleFiles/students_classes.csv");
    //inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/students_classes.csv");
    inFile.open(filename);
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
    inFile.close();
    students.insert(st_class);
    for(auto it: students){auxStudents.push_back(it);}
    std::sort(auxStudents.begin(), auxStudents.end(),[](Student a, Student b){return a.get_studentName()<b.get_studentName();});
}
/**
 * Lê o ficheiro "classes_per_uc.csv" e guarda os elementos num vetor.
 * Complexidade: O(n), n-> tamanho do ficheiro "class_per_uc.csv".
 * @return um vetor com objetos pertencentes à classe ClassPerUC.
 */
vector<ClassPerUC> ScheduleManagement::readClassesPerUC(){
    string line;
    string ucCode, classCode;
    ifstream inFile;
    
    inFile.open("/Users/madalenaye/Downloads/AED/project/schedule/scheduleFiles/classes_per_uc.csv");
    //inFile.open("/home/sereno/CLionProjects/ProjetoAED/schedule/scheduleFiles/classes_per_uc.csv");
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
    inFile.close();
    return classes;
}

//listings of classes
/**
 * Faz a listagem das turmas por cada ano curricular.
 * Complexidade: O(n), n->tamanho do vetor schedule.
 */
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
    cout<<"Há "<< classes.size()<<" turmas no "<<year <<"º ano" << endl;
    print_exitOptions();
}
/**
 * Lista as turmas segundo ordem crescente ou decrescente.
 * @param order define a ordem a listar as turmas.
 * Complexidade: O(n), n-> corre o vetor lecture.
 */
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
    print_exitOptions();

}
/**
 * Lista as turmas por cada unidade curricular
 * Complexidade: O(n), n-> tamanho do vetor v.
 * @param v vetor de todas as unidades curriculares com as respetivas turmas
 */
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
        if (it.get_ucCode() == uni){ cout << it.get_classCode() << endl;}
    }
    print_exitOptions();

}
//listing of schedule
/**
 * Converte os dias da semana em números inteiros.
 * Complexidade: O(1)
 * @param weekday dia da semana.
 * @return número inteiro.
 */
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
// functors
/**
 * Encontrar um estudante do set de estudantes pelo seu atributo "studentCode".
 * Complexidade: O(1).
 */
struct find_by_studentCode{
    find_by_studentCode(long int code) : code(code) {}

    bool operator()(Student student) {
        return student.get_studentCode() == code;
    }

private:
    long int code;
};

/**
 * Listagem do horário por cada estudante.
 * Complexidade: O(n*m*k), n->tamanho do vetor cpu do estudante *result, m-> tamanho do vetor lecture, k->tamanho da lista de slots
 */

void ScheduleManagement::listingStudentSchedule(){
    cout << "Escolha o modo de pesquisa de horário por estudante: \n" << "1. Número UP\n" << "2. Nome\n";
    cout << "\nOpção: ";
    string mode; cin >> mode;
    while (!(mode == "1" || mode == "2")){
        cout << "Input inválido, tente novamente: ";
        cin >> mode;
    }
    if (mode == "1") {
        cout << "Introduza o número UP (Ex: 202041977): ";
        long int up; cin >> up;
        while(std::cin.fail() || to_string(up).length()!= 9 || up > 202080397 || up < 201920727) {
            cout << "Input inválido, tente novamente: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> up;
        }
        auto result = find_if(students.begin(), students.end(), find_by_studentCode(up));
        vector<pair<ClassPerUC, Slot>> aux;
        Student es = (*result);
        for (ClassPerUC cpu: es.get_classPerUC()) {
            for (Lecture lecture: schedule) {
                if (cpu.get_ucCode() == lecture.get_ucCode() && cpu.get_classCode() == lecture.get_classCode()) {
                    for (Slot slot: lecture.get_Slot()) {
                        aux.emplace_back(ClassPerUC(cpu.get_ucCode(), cpu.get_classCode()), slot);
                    }
                }
            }
        }
        std::sort(aux.begin(), aux.end(), [](pair<ClassPerUC, Slot> a, pair<ClassPerUC, Slot> b) {
            return weekDayToNum(a.second.get_WeekDay()) < weekDayToNum(b.second.get_WeekDay()) ||
                   (weekDayToNum(a.second.get_WeekDay()) == weekDayToNum(b.second.get_WeekDay()) &&
                    a.second.get_StartHour() < b.second.get_StartHour());
        });
        for (auto it = aux.begin(); it < aux.end(); it++) {
            cout << it->second.get_WeekDay() << endl;
            cout << it->first.get_ucCode() << ", " << it->first.get_classCode() << ", " << it->second.get_StartHour()
                 << ", " << it->second.get_Duration() << ", " << it->second.get_Type() << endl;
        }
    }
    else {
        cout << "Introduza o nome do aluno: ";
        string name; cin >> name;
        int i = binary_search(name);
        while(i == -1){
            cout << "Estudante não encontrado, tente novamente: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> name;
            i = binary_search(name);
        }
        vector<pair<ClassPerUC, Slot>> aux;
        for (ClassPerUC cpu: auxStudents[i].get_classPerUC()) {
            for (Lecture lecture: schedule) {
                if (cpu.get_ucCode() == lecture.get_ucCode() && cpu.get_classCode() == lecture.get_classCode()) {
                    for (Slot slot: lecture.get_Slot()) {
                        aux.emplace_back(ClassPerUC(cpu.get_ucCode(), cpu.get_classCode()), slot);
                    }
                }
            }
        }
        std::sort(aux.begin(), aux.end(), [](pair<ClassPerUC, Slot> a, pair<ClassPerUC, Slot> b) {
            return weekDayToNum(a.second.get_WeekDay()) < weekDayToNum(b.second.get_WeekDay()) ||
                   (weekDayToNum(a.second.get_WeekDay()) == weekDayToNum(b.second.get_WeekDay()) &&
                    a.second.get_StartHour() < b.second.get_StartHour());
        });
        for (auto it = aux.begin(); it < aux.end(); it++) {
            cout << it->second.get_WeekDay() << endl;
            cout << it->first.get_ucCode() << ", " << it->first.get_classCode() << ", " << it->second.get_StartHour()
                 << ", " << it->second.get_Duration() << ", " << it->second.get_Type() << endl;
        }
    }
    print_exitOptions();
}
/**
 * Listagem do horário de cada turma
 * Complexidade: O(n*m), n->tamanho do vetor schedule, m->tamanho da lista de slots
 */
void ScheduleManagement::listingClassSchedule() {
    cout << "Deseja ver o horário de que turma? (Ex: 1LEIC07): ";
    string _class; cin >> _class;
    while(_class.length()!=7) {
        cout << "Input inválido, tente novamente: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> _class;
    }
    cout << "A turma " << _class << " tem o seguinte horário:" << endl;
    vector<pair<string,Slot> >aux;
    for (Lecture lecture : schedule){
        if (lecture.get_classCode() == _class){
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
        cout << it->first << ", "  << it->second.get_StartHour() << ", " << it->second.get_Duration() << ", " << it->second.get_Type() << endl;
    }
    print_exitOptions();
}
/**
 * Listagem do horário de uma cadeira.
 * Complexidade: O(n*m), n->tamanho do vetor schedule, m->tamanho da lista Slot de uma lectures
 */
void ScheduleManagement::listingUcSchedule() {
    cout << "Deseja ver o horário de que unidade curricular? (Ex: L.EIC003): ";
    string uc; cin >> uc;
    while(uc.length()!=8 || uc[1]!='.') {
        cout << "Input inválido, tente novamente: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> uc;
    }
    cout << "A UC " << uc << " tem o seguinte horário:" << endl;
    vector<pair<string,Slot>> aux;
    for (Lecture lecture : schedule){
        if (lecture.get_ucCode() == uc){
            for (Slot slot: lecture.get_Slot()) {
                aux.emplace_back(lecture.get_classCode(),slot);
            }
        }
    }
    std::sort(aux.begin(),aux.end(),[](pair<string,Slot> a ,pair<string,Slot> b){
        return weekDayToNum(a.second.get_WeekDay()) < weekDayToNum(b.second.get_WeekDay()) || (weekDayToNum(a.second.get_WeekDay()) == weekDayToNum(b.second.get_WeekDay()) && a.second.get_StartHour() < b.second.get_StartHour());
        ;});
    for (auto it = aux.begin();it < aux.end();it++){
        cout << it->second.get_WeekDay() << endl;
        cout << it->first << ", "  << it->second.get_StartHour() << ", " << it->second.get_Duration() << ", " << it->second.get_Type() << endl;
    }
    print_exitOptions();
}
//listing of students
/**
 * Listagem de todos os estudantes por número up.
 * Complexidade:O(n) , n-> tamanho do set students
 */
void ScheduleManagement::listingAllStudentsCode() {
    for(auto i:students){
        cout<<i.get_studentCode()<<" - "<<i.get_studentName()<<endl;
    }
    print_exitOptions();

}
/**
 * Listagem dos estudantes em função do nome.
 * Complexidade: O(n) ,n-> tamanho do vetor auxStudents
 */
void ScheduleManagement::listingAllStudentsName(){
    for(auto i:auxStudents){
        cout<<i.get_studentName()<<"-"<<i.get_studentCode()<<endl;
    }
    print_exitOptions();
}
/**
 * Listagem dos estudantes em função do ano curricular.
 * Complicado: O(n*m) , n-> tamanho do vetor auxStudents , m-> tamanho da lista j
 * e dá output aos estudantes de um respetivo ano.
 */
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
    cout << "Há " << count << " alunos neste ano." << endl;
    print_exitOptions();
}
/**
 * Listagem dos estudantes com base no ano de entrada na faculdade.
 * Complexidade: O(n), n-> tamanho do vetor de estudantes
 */
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
    print_exitOptions();
}
/**
 * Listagem dos estudantes de uma turma.
 * Complexidade: O(n*m) , n-> tamanho do vetor auxiliar de estudantes , m-> tamanho da lista<ClassPerUc> do estudante i.
 */
void ScheduleManagement::listingStudentsInClass() {
    cout << "Pretende ver os alunos de que turma? (Ex: 1LEIC13/2LEIC01/3LEIC06): ";
    string _class;
    cin >> _class;
    while(_class.length()!=7) {
        cout << "Input inválido, tente novamente: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> _class;
    }
    cout << "De que unidade curricular? (Ex: L.EIC003): ";
    string _uc; cin >> _uc;
    while(_uc.length()!=8) {
        cout << "Input inválido, tente novamente: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> _uc;
    }
    int count=0;
    for(auto i:auxStudents) {
        for (auto j: i.get_classPerUC()) {
            if (j.get_classCode() == _class && j.get_ucCode() == _uc) {
                cout << i.get_studentCode() << "-" << i.get_studentName() << endl;
                count++;
                break;
            }
        }
    }
    if(count==0){cout<<"Não há estudantes nesta turma e nesta unidade curricular";}
    cout << "Há " << count << " alunos nesta turma e nesta unidade curricular." << endl;
    print_exitOptions();
}
/**
 * Listagem dos estudantes com mais inscrições em unidades curriculares com base no input mínimo de unidades curriculares
 * desejado.
 * Complexidade: O(n) , n-> tamanho do vetor auxStudents
 */
void ScheduleManagement::listingStudentsWithNUCs(){
    cout << "Estudantes com mais de quantas UCs? ";
    int n; cin >> n;
    while(std::cin.fail()) {
        cout << "Input inválido, tente novamente: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> n;
    }
    int count = 0;

    for (Student student : auxStudents){
        count = student.get_classPerUC().size();
        if (count >= n){
            cout << student.get_studentName() << "-" << student.get_studentCode() << endl;
        }
    }
    print_exitOptions();
}
//student request
/**
 * Coloca um pedido na fila de pedidos.
 * Complexidade: O(1).
 * @param r  pedido a ser colocado
 */
void ScheduleManagement::push_request(Request r) {
    requests.push(r);
}
/**
 * Remove o estudante de uma turma de uma determinada UC
 * Complexidade: 0(nlog(n)), n->tamanho do set/número de estudantes
 * @param code código up do estudante
 * @param _uc unidade curricular
 * @param _class turma da qual pretende sair
 */
void ScheduleManagement::removeStudent(long code,string _uc,string _class) {
    Student s;
    s.set_studentCode(code);
    const set<Student>::iterator &it = students.find(s);
    Student es = (*it);
    s.set_studentName(es.get_studentName());
    list<ClassPerUC> cpu;

    for(auto i: es.get_classPerUC()){
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
/**
 * Adiciona um estudante a uma turma de uma determinada UC
 * Complexidade: O(nlog(n)), n->tamanho do set/número de estudantes
 * @param code código up do estudante
 * @param _uc  unidade curricular
 * @param _cc  turma para a qual pretende entrar
 */
void ScheduleManagement::addStudent(long code, string _uc, string _cc) {
    Student s;
    s.set_studentCode(code);
    const set<Student>::iterator &it = students.find(s);
    Student es = *it;
    s.set_studentName(es.get_studentName());
    list<ClassPerUC> cpu=es.get_classPerUC();
    if(studentsPerClass(_uc,_cc)<30 && isAlreadyInThisUc(code,_uc))cpu.push_back(ClassPerUC(_uc,_cc));

    students.erase(it);
    s.set_ClassPerUC(cpu);
    students.insert(s);
    auxStudents.clear();
    for(auto it: students){auxStudents.push_back(it);}
    std::sort(auxStudents.begin(), auxStudents.end(),[](Student a, Student b){return a.get_studentName()<b.get_studentName();});
}
/**
 * Muda o estudante de turma a uma determinada cadeira
 * Complexidade: O(nlog(n)) ,n -> tamanho do vetor auxStudents
 * @param code código up do estudante
 * @param _uc unidade curricular
 * @param _class turma para a qual quer sair
 * @param new_class turma para a qual quer entrar
 */
void ScheduleManagement::changeStudentclass(long code, string _uc, string _class, string new_class) {
    Student s;
    s.set_studentCode(code);
    const set<Student>::iterator &it = students.find(s);
    Student es = *it;
    s.set_studentName(es.get_studentName());
    list<ClassPerUC> cpu;

    for(auto i: es.get_classPerUC()){
        if(i.get_ucCode()!=_uc || i.get_classCode()!=_class){
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
/**
 * Realizar os pedidos
 * Complexidade: O(1)
 */
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
/**
 * Conta o número de estudantes que existe numa turma.
 * Complexidade: O(n*m) , n-> itera sobre o set de estudantes, m-> itera sobre a lista de ClassPerUc do estudante
 * @param u - unidade curricular
 * @param c - turma
 * @return obtém-se o número de estudantes inscritos naquela turma numa dada unidade curricular.
 */
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
//listing ucs
/**
 * Listagem de todas as unidades curriculares (ordem crescente ou decrescente, a definir pelo utilizador)
 * Complexidade: O(n*log(m)) , n-> tamanho do vetor ClassPerUc, m-> tamanho do set ucs.
 * @param order caso seja 1 , organiza por ordem crescente senão organiza de forma descrescente.
 * @param v  vetor de ClassPerUc para iterar sobre.
 */
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
    print_exitOptions();

}
/**
 * Listagem de todas as unidades curriculares com base no ano em que estas são lecionadas.
 * Complexidade: O(n*log(m)) , n-> tamannho do vetor schedule , m-> tamanh0 do set UCs
 */
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
    print_exitOptions();
}
/**
 * Listagem das unidades curriculares de um estudante, a partir do código do estudante ou nome do estudante (a definir
 * pelo utilizador).
 * Complexidade: O(n) n-> tamanho da lista cpu do estudante *result.
 */
void ScheduleManagement::listingUcsPerStudent() {
    cout << "Escolha o modo de pesquisa de UCs por estudante: \n" << "1. Número UP\n" << "2. Nome" << endl;
    cout << "\nOpção: ";
    string mode; cin >> mode;
    while (!(mode == "1" || mode == "2")){
        cout << "Input inválido, tente novamente: ";
        cin >> mode;
    }
    if (mode == "1"){
        cout << "Introduza o número UP (Ex: 202041977): ";
        long int up; cin >> up;
        //input fail
        while(std::cin.fail() || to_string(up).length()!= 9 || up > 202080397 || up < 201920727) {
            cout << "Input inválido, tente novamente: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> up;
        }
        auto result = find_if(students.begin(), students.end(), find_by_studentCode(up));
        cout << up << ": ";
        Student es = (*result);
        for (auto i: es.get_classPerUC()){
                    cout << i.get_ucCode() << ",";
                }
        cout<<'\b';  //Cursor moves 1 position backwards
        cout<<" ";
    }
    else{
        cout << "Introduza o nome do aluno: ";
        string name; cin >> name;
        int i = binary_search(name);
        while(i == -1){
            cout << "Estudante não encontrado, tente novamente: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> name;
            i = binary_search(name);
        }
        cout << name << ": ";
        for (auto it: auxStudents[i].get_classPerUC()){
            cout << it.get_ucCode() << ",";
        }
        cout<<'\b';  //Cursor moves 1 position backwards
        cout<<" ";

    }
    print_exitOptions();
}
/**
 * Listagem das unidades curriculares com base na turma.
 * Complexidade: O(n), n-> tamanho do vetor v.
 */
void ScheduleManagement::listingUcsByClass() {
    cout << "Introduza a turma (Ex: 1LEIC01): ";
    string _class; cin >> _class;
    while(_class.length()!=7) {
        cout << "Input inválido, tente novamente: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> _class;
    }
    vector<ClassPerUC> v = readClassesPerUC();
    cout << _class << ": ";
    for (auto it : v){
        if (it.get_classCode() == _class){
            cout << it.get_ucCode() << ",";
        }
    }
    cout<<'\b';  //Cursor moves 1 position backwards
    cout<<" ";
    print_exitOptions();
}
/**
 * Verifica se é possível fazer a mudanção ou adição de turma.
 * Complexidade= O(n*m*k), n -> tamanho da lista cpu do estudante x, m-> tamanho do vetor schedule, k-> tamanho da lista slot
 * do objeto lecture.
 * @param stu estudante em questão.
 * @param uc cadeira em que deseja mudar de turma.
 * @param cc turma em que o estudante se deseja mudar para.
 * @return é verdadeiro caso seja possível fazer a mudança.
 */
bool ScheduleManagement::compatibleClass(long int up,string uc, string cc){
    auto student = find_if(students.begin(), students.end(), find_by_studentCode(up));
    Student x = *student;
    list<Slot> newClass= {};
    vector<pair<ClassPerUC,Slot>> allStudentSlots= {};
    list<ClassPerUC> cpu= {};
    for (ClassPerUC c: readClassesPerUC()) {
        if (uc == c.get_ucCode()) {
            cpu.push_back(c);
        }
    }
    cpu.sort([this]( ClassPerUC a, ClassPerUC b){
        return  studentsPerClass(a.get_ucCode(),a.get_classCode()) < studentsPerClass(b.get_ucCode(),b.get_classCode());
    });

    if (abs(studentsPerClass((cpu.back()).get_ucCode(),(cpu.back()).get_classCode()) - studentsPerClass((cpu.front()).get_ucCode(),(cpu.front()).get_classCode())) >= 4 ){
        return false;
    }

    for (Lecture lecture: schedule){
        if (lecture.get_ucCode() == uc && lecture.get_classCode()== cc) {
            newClass= lecture.get_Slot();
            break;
        }
    }

    for (ClassPerUC cpu1: x.get_classPerUC()){
        for (Lecture le: schedule){
            if (le.get_ucCode() == cpu1.get_ucCode() && le.get_classCode() == cpu1.get_classCode()){
                for (Slot slot: le.get_Slot()){
                    allStudentSlots.emplace_back(cpu1,slot);
                }
            } //-> todas as aulas do estudante
        }
    }

    for (auto it= allStudentSlots.begin();it != allStudentSlots.end();it++){ //percorrer todas as aulas do estudante
        for (auto it2 = newClass.begin();it2 != newClass.end();it2++){       //percorrer todas as aulas da turma a adicionar
            if (it->first.get_ucCode() != uc){                              //se não forem da mesma uc?
                if (it->second.get_WeekDay() == (*it2).get_WeekDay() &&         //se ocorrerem ao mesmo tempo, então é falso?
                    (it->second.get_StartHour() <= (*it2).get_StartHour() && (*it2).get_StartHour() <= it->second.get_StartHour()+it->second.get_Duration() ||
                     (*it2).get_StartHour() <= it->second.get_StartHour() &&  it->second.get_StartHour() <= (*it2).get_StartHour()+ (*it2).get_Duration()) &&
                    ((((*it2).get_Type()!="T") && (it->second.get_Type()!="T")))){
                    return false;
                }
            }
        }
    }
    return true;
}

/**
 * Dá push de um pedido inválido para vetor
 * Complexidade: O(1)
 * @param r Pedido inválido
 */
void ScheduleManagement::pushInvalidRequest(Request r){
    invalid_requests.push_back(r);
}
/**
 * Para os pedidos ADD, verifica se o estudante em questão já está inscrito na unidade curricular
 * e se já tem uma turma associada
 * Complexidade: 0(n), n-> tamanho da lista de Turmas do estudante s.
 * @param up
 * @param uc
 * @return true se não estiver inscrito na unidade curricular.
 */
bool ScheduleManagement::isAlreadyInThisUc(long int up, string uc){
    Student s;
    s.set_studentCode(up);
    const set<Student>::iterator &it = students.find(s);
    Student es = *it;
    s.set_ClassPerUC(es.get_classPerUC());
    for (ClassPerUC i:s.get_classPerUC()){
        if (i.get_ucCode() == uc){return false;}
    }
    return true;
}
/**
 * Algoritmo de pesquisa binária
 * Complexidade: O(log(n))
 * @param name nome do estudante
 * @return Index da posição do aluno no vetor
 */
int ScheduleManagement::binary_search(string name) {
    int low = 0, high = auxStudents.size()-1;
    while(low <= high){
        int middle = low + (high-low)/2;
        if(name < auxStudents[middle].get_studentName()) high = middle - 1;
        else if (name > auxStudents[middle].get_studentName()) low = middle + 1;
        else return middle;
    }
    return - 1;
}
void ScheduleManagement::print_exitOptions(){
    cout << "\nDeseja realizar outra operação? (S/N)? ";
    string answer; cin >> answer;
    while (!(answer == "S" || answer == "N" || answer == "n" || answer == "s")){
        cout << "Input inválido, tente novamente: ";
        cin >> answer;
    }
    if (answer == "S" || answer == "s") {
        cout << endl;printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");printf("\n");cout << endl;
        menuOperations(*this);
    }
    else terminate(*this);
}