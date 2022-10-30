#include "ReadFiles.h"

#include "Menu.h"
#include <iostream>
#include <iomanip>

using namespace std;
int main() {

    readClasses();
    readStudents();
    readClassesPerUC();
    createMenu();
}