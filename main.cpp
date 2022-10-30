#include "ReadFiles.h"
#include <iostream>
#include <iomanip>
#include "Menu.h"
using namespace std;
int main() {

    readClasses();
    readStudentClasses();
    readClassesPerUC();
    createMenu();
}