#include <iostream>
#include <iomanip>
#include <string>
#include "ScheduleManagement.h"
#include "Menu.h"

int main(){
    //createMenu();
    ScheduleManagement manager;
    manager.readStudents();
    manager.listingAllStudentsName();
    //manager.listingAllStudentsName();


    //manager.listingClassPerYear((char)year[0]);

    //manager.listingClassSchedule("1LEIC01");
    //manager.listingStudentSchedule("202071557");
    //manager.listingUcSchedule("L.EIC003");
    /*
    manager.listingClasses("1");*/
    endMenu();
}
