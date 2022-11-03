
#include "Menu.h"
#include "ScheduleManagement.h"
#include <iostream>
using namespace std;
int main(){
    createMenu();
    /*ScheduleManagement manager;
    manager.readStudents();
    manager.listingStudentsInClass();
    cout<<manager.studentsPerClass("L.EIC002","1LEIC08")<<endl;
    Request r1(REMOVE,202025487,"L.EIC002","1LEIC08","");
    Request r2 (ADD,202025487,"L.EIC002","1LEIC08","");
    Request r3(CHANGE_CLASS,202023532,"L.EIC002","1LEIC02","1LEIC08");
    manager.push_request(r1);
    manager.push_request(r2);
    manager.push_request(r3);
    manager.doRequest();
    cout<<manager.studentsPerClass("L.EIC002","1LEIC08")<<endl;
    manager.listingStudentsInClass();
    manager.doRequest();
    cout<<manager.studentsPerClass("L.EIC002","1LEIC08")<<endl;
    manager.listingStudentsInClass();
    manager.doRequest();
    cout<<manager.studentsPerClass("L.EIC002","1LEIC08")<<endl;
    manager.listingStudentsInClass();*/
    endMenu();
}
