//
// Created by Madalena Ye on 29/10/2022.
//

#include "Lecture.h"
/**
 * Construtor pré-definido das aulas.
 */
Lecture::Lecture() {
    ucCode = "";
    classCode = "";
    slots= {};
}
/**
 * Construtor parametrizado do conjunto de aulas de uma unidade curricular.
 * @param uc
 * @param cc
 * @param slt
 */
Lecture::Lecture(string uc, string cc, list<Slot> slt){
    ucCode= uc;
    classCode = cc;
    slots=slt;
}
//getters
string Lecture::get_ucCode(){return ucCode;}
string Lecture::get_classCode(){return classCode;}
list<Slot> Lecture::get_Slot() {return slots;}
//setters
void Lecture::set_ucCode(string uc){ucCode=uc;}
void Lecture::set_classCode(string cc){classCode=cc;}
void Lecture::set_Slot(list<Slot> slt) {slots=slt;}