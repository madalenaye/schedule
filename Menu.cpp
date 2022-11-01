//
// Created by Madalena Ye on 29/10/2022.
//

#include <iostream>
#include <iomanip>
#include "Menu.h"
using namespace std;

void createMenu(){
    printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");
    printf("\n");
    printf("\n");
    cout << setw(52) << "Welcome to the best schedule manager! \n" << setw(54) << "What operation would you like to perform today?"
         << endl;
    printf("\n");
    cout << setw(36) << "1. Listings\n" << setw(38) <<"2. Modifications\n" << setw(33) << "3. Exit\n";
}

void endMenu(){
    printf("\n");
    printf("\033[46m=============================================================\033[0m\t\t");
}