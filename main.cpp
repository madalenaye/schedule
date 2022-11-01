#include "Menu.h"
#include "ScheduleManagement.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "BinarySearchTree.h"

int main(){
    /*
    createMenu();*/

    ScheduleManagement manager;
    manager.readClasses();
    manager.readStudents();
    manager.readClassesPerUC();
    vector<Student> v;
    for(auto it: manager.get_students()){v.push_back(it);}
    TreeNode* StudentBST= sortedVectorToBST(v);
    cout<<findInBST(binarySearchTreeStudents(manager.get_students()),202054812)->value.get_studentName();
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
    /*
    manager.listingClasses("1");*/
    /*
    endMenu();*/
}
