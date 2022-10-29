//
// Created by sereno on 28-10-2022.
//

#include "classperUC.h"
classperUC::classperUC() {
    ucCode = "";
    classCode="";
}
classperUC::classperUC(std::string uc, std::string cc) {ucCode=uc;classCode=cc;}
string classperUC::get_ucCode(){return ucCode;}
string classperUC::get_classCode(){return classCode;}
//setters
void classperUC::set_ucCode(string uc){ucCode=uc;}
void classperUC::set_classCode(string cc){classCode=cc;}