//
// Created by Utilizador on 03/11/2022.
//
#include "Request.h"

RequestType Request::getType(){
    return type;
}

void Request::setType(RequestType type) {
    this->type = type;
}