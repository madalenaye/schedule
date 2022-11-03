//
// Created by Utilizador on 03/11/2022.
//
#include "Request.h"

Request::Request(RequestType t, long sc, std::string uc, std::string c,std::string nc) {
    type=t;
    studentCode=sc;
    _uc=uc;
    _class=c;
    new_class=nc;
}

Request::Request() {
    type=REMOVE;
    studentCode=0;
    _uc="";
    _class="";
    new_class="";
}

RequestType Request::getType(){return type;}
long Request::getStudentCode(){return studentCode;}
string Request::getUc(){return _uc;}
string Request::getClass(){return _class;}
string Request::getNewClass(){return new_class;}

void Request::setType(RequestType type) {this->type = type;}
void Request::setStudentCode(long sc) {studentCode=sc;}
void Request::setUc(std::string uc){_uc=uc;}
void Request::setClass(std::string c){_class=c;}
void Request::setNewClass(std::string nc){new_class=nc;}