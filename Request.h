//
// Created by Utilizador on 02/11/2022.
//

#ifndef SCHEDULE_REQUEST_H
#define SCHEDULE_REQUEST_H
#include <string>
using namespace std;
enum RequestType {REMOVE,ADD,CHANGE_CLASS,CHANGE_CLASSES};
class Request{
    public:
        Request();
        Request(RequestType t, long sc, string uc, string c);
        //getters
        RequestType getType();
        long getStudentCode();
        string getUc();
        string getClass();
        //setters
        void setType(RequestType type);
        void setStudentCode(long sc);
        void setUc(string uc);
        void setClass(string c);

    private:
        RequestType type;
        long studentCode;
        string _uc;
        string _class;
    };

#endif //SCHEDULE_REQUEST_H
