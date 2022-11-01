#include "Menu.h"
#include "ScheduleManagement.h"
#include <iostream>
#include <iomanip>

int main(){
    createMenu();
    endMenu();
    /*
    ScheduleManagement manager;
    manager.readClasses();
    manager.readStudents();
    manager.readClassesPerUC();*/

    /*
    string year;
    cin >> year;
    while(!(year == "1" || year == "2" || year == "3")){

        cout << "Please enter a valid input: ";
        cin >> year;
    }
    */
    /*
    manager.listingClassPerYear((char)year[0]);
    manager.listingClassSchedule("1LEIC01");
    manager.listingStudentSchedule("202071557");
    manager.listingUcSchedule("L.EIC003");*/
    return 0;
}
