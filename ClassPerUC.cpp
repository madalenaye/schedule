//
// Created by Madalena Ye on 29/10/2022.
//
#include "ClassPerUC.h"
/**
 * Construtor pré-definido de uma turma de uma dada cadeira.
 */
ClassPerUC::ClassPerUC() {
    ucCode = "";
    classCode="";
}
/**
 * Construtor parametrizado de uma turmas de uma dada cadeira.
 * @param uc
 * @param cc
 */
ClassPerUC::ClassPerUC(std::string uc, std::string cc) {ucCode=uc;classCode=cc;}
string ClassPerUC::get_ucCode() const{return ucCode;}
string ClassPerUC::get_classCode() const{return classCode;}
//setters
void ClassPerUC::set_ucCode(string uc){ucCode=uc;}
void ClassPerUC::set_classCode(string cc){classCode=cc;}

