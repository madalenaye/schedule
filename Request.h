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
        RequestType getType();
        void setType(RequestType type);

    private:
        RequestType type;

    };

#endif //SCHEDULE_REQUEST_H
