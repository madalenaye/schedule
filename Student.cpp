//
// Created by Madalena Ye on 29/10/2022.
//

#include <algorithm>
#include "Student.h"
//constructors
/**
 * Construtor pré-definido de um estudante.
 */
Student::Student() {
    studentCode = 0;
    studentName = "";
    cpu= {};
}
/**
 * Construtor parametrizado de um estudante.
 * @param stc
 * @param stn
 * @param cpu
 */
Student::Student(long int stc, string stn, list<ClassPerUC> cpu){
    studentCode = stc;
    studentName = stn;
    this->cpu = cpu;
}
//getters and setters
int Student::get_studentCode()  {return studentCode;}
string Student::get_studentName()  {return studentName;}
list<ClassPerUC> Student::get_classPerUC()  {return cpu;}

void Student::set_studentCode(long int stc){studentCode = stc;}
void Student::set_studentName(string stn){studentName = stn;}
void Student::set_ClassPerUC(list<ClassPerUC> cpu) {this->cpu= cpu;}
/**
 * Verifica se é o mesmo estudante portanto é a primary key.
 * @param rhs
 * @return true caso o código do estudante seja o mesmo.
 */
bool Student::operator==(Student rhs) {
    return studentCode == rhs.studentCode;
}
/**
 * Verifica se o objeto estudante é diferente.
 * @param rhs
 * @return  false caso o estudante seja o mesmo.
 */
bool Student::operator!=(Student rhs) {
    return studentCode != rhs.studentCode;

}
