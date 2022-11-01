#include "Menu.h"
#include "ScheduleManagement.h"
#include <iostream>
#include <iomanip>
#include <string>

int main(){
    createMenu();

    ScheduleManagement manager;
    manager.readClasses();
    manager.readStudents();
    manager.readClassesPerUC();
    /*
    string year;
    cin >> year;
    while(!(year == "1" || year == "2" || year == "3")){

        cout << "There is no such class, please try again: ";
        cin >> year;
    }
    manager.listingClassPerYear((char)year[0]);
    manager.listingClassSchedule("1LEIC01");
    manager.listingStudentSchedule("202071557");
    manager.listingUcSchedule("L.EIC003");*/
    endMenu();
}
