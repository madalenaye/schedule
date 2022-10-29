//
// Created by sereno on 28-10-2022.
//

#ifndef PROJETOAED_CLASSPERUC_H
#define PROJETOAED_CLASSPERUC_H

#include <string>
using namespace std;

class classperUC{
public:
    classperUC();
    classperUC(string uc,string cc);
    //getters
    string get_ucCode();
    string get_classCode();
    //setters
    void set_ucCode(string uc);
    void set_classCode(string cc);
private:
    string ucCode;
    string classCode;
};


#endif //PROJETOAED_CLASSPERUC_H
