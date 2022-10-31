#include "Menu.h"
#include "ScheduleManagement.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
int main() {
    ScheduleManagement manager;

    manager.readClasses();
    manager.readStudents();
    manager.readClassesPerUC();
    //createMenu();
    string year;
    while(true){
        cin>>year;
        if(!(year=="1" || year=="2" || year=="3")){
            cout<<"Error: Class not Found"<<endl;
        }
        else{break;}
    }

    manager.listingClassPerYear((char)year[0]);
}