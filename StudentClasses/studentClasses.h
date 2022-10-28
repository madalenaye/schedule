//
// Created by sereno on 28-10-2022.
//
#ifndef PROJETOAED_STUDENTCLASSES_H
#define PROJETOAED_STUDENTCLASSES_H

#include <string>
using namespace std;
class studentsClass{
public:
    studentsClass(int stc,string stn, string ucc, string cc);
    int get_studentCode();
    string get_studentName();
    string get_ucCode();
    string get_classCode();
//setters
    void set_studentCode(int stc);
    void set_studentName(string stn);
    void set_ucCode(string uc);
    void set_classCode(string cc);

private:
    //FALTA PREENCHER ESTA CLASSES AQUI COM OS ATRIBUTOS DA TABELA students_classes.csv
    int studentCode;
    string studentName;
    string ucCode;
    string classCode;
};



#endif //PROJETOAED_STUDENTCLASSES_H
