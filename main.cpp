#include <iostream>
#include <iomanip>
#include <string>
#include "ScheduleManagement.h"
#include "Menu.h"

int main(){
    //createMenu();

    ScheduleManagement manager;
    manager.readStudents();
    manager.listingStudentsInClass("L.EIC002","1LEIC08");
    cout<<manager.studentsPerClass("L.EIC002","1LEIC08")<<endl;
    Request r1(REMOVE,202025487,"L.EIC002","1LEIC08","");
    Request r2 (ADD,202025487,"L.EIC002","1LEIC08","");
    Request r3(CHANGE_CLASS,202023532,"L.EIC002","1LEIC02","1LEIC08");
    manager.push_request(r1);
    manager.push_request(r2);
    manager.push_request(r3);
    manager.doRequest();
    cout<<manager.studentsPerClass("L.EIC002","1LEIC08")<<endl;
    manager.listingStudentsInClass("L.EIC002","1LEIC08");
    manager.doRequest();
    cout<<manager.studentsPerClass("L.EIC002","1LEIC08")<<endl;
    manager.listingStudentsInClass("L.EIC002","1LEIC08");
    manager.doRequest();
    cout<<manager.studentsPerClass("L.EIC002","1LEIC08")<<endl;
    manager.listingStudentsInClass("L.EIC002","1LEIC08");

    //manager.removeStudent(202025487,"L.EIC002","1LEIC08");
    //cout<<"====================================="<<endl;
    //manager.listingStudentsInClass("L.EIC002","1LEIC08");
    //manager.listingClassPerYear((char)year[0]);
    //manager.listingClassSchedule("1LEIC01");
    //manager.listingStudentSchedule("202071557");
    //manager.listingUcSchedule("L.EIC003");
    /*
    manager.listingClasses("1");*/

    //endMenu();
}
