#include "Menu.h"
#include "ScheduleManagement.h"
#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    ScheduleManagement manager;

    manager.readClasses();
    manager.readStudents();
    manager.readClassesPerUC();
    createMenu();
}