//
// Created by Madalena Ye on 29/10/2022.
//
#include "ClassPerUC.h"

ClassPerUC::ClassPerUC() {
    ucCode = "";
    classCode="";
}
ClassPerUC::ClassPerUC(std::string uc, std::string cc) {ucCode=uc;classCode=cc;}
string ClassPerUC::get_ucCode(){return ucCode;}
string ClassPerUC::get_classCode(){return classCode;}
//setters
void ClassPerUC::set_ucCode(string uc){ucCode=uc;}
void ClassPerUC::set_classCode(string cc){classCode=cc;}