//
// Created by Madalena Ye on 29/10/2022.
//
#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "ScheduleManagement.h"
#include <unistd.h>
#include <algorithm>
using namespace std;


// functors

struct find_by_studentName{
    find_by_studentName(string n) : name(n) {}

    bool operator()(Student student) const{
        return student.get_studentName() == name;
    }

private:
    string name;
};

// for later implementation
void listingOptions();
void listOperations();
void listClasses();

//creating menu
void createMenu(){
    printf("\n");
    printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");
    printf("\n");
    printf("\n");
    cout << setw(53) << "Bem-vind@ ao melhor gestor de horários! \n";
    listOperations();
}

//types of listings
void listOperations(){
    cout << setw(42) << "O que deseja fazer hoje?" << endl;
    printf("\n");
    cout << setw(14) << "1. Listagens" << setw(22) << "2. Alterações" << setw(25) << "3. Sair do programa\n";
    printf("\n  Opção: ");
    // prompting for operation
    string option;
    cin >> option;
    // input error
    while (!(option == "1" || option == "2" || option == "3")){
        cout << "  Input inválido, tente novamente: ";
        cin >> option;
    }
    if (option == "1") listingOptions();
    else if (option == "2"){

    }
        // end program
    else return;
}

//listing options
void listingOptions(){
        cout << "\nSelecione o tipo de listagem:\n";
        cout << "1. Listagem de turmas\n" << "2. Listagem de alunos\n" << "3. Listagem de horário\n" << "4. Listagem de unidades currriculares\n" << "5. Voltar\n";
        cout << "\nOpção: ";
        string type;
        cin >> type;
        // input error
        while (!(type == "1" || type == "2" || type == "3" || type == "4" || type == "5")){
            cout << "Input inválido, tente novamente: ";
            cin >> type;
        }
        if (type == "1"){listClasses();}
        else if (type == "2"){}
        else if (type == "3"){}
        else if (type == "4"){}
        else{
            printf("\n");printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t"); cout << "\n" << "\n"; listOperations();}
}
void listClasses(){
    cout << "\nSelecione o modo de listagem de turmas:\n";
    cout << "1. Ordem crescente\n" << "2. Ordem decrescente\n" << "3. Por ano\n" << "4. Por UC\n" << "5. Voltar\n";
    cout << "\nOpção: ";
    string mode;
    cin >> mode;

    // input error
    while (!(mode == "1" || mode == "2" || mode == "3" || mode == "4" || mode == "5")){
        cout << "Input inválido, tente novamente: ";
        cin >> mode;
    }
    ScheduleManagement manager;
    manager.readClasses();
    manager.readStudents();
    vector<ClassPerUC> v = manager.readClassesPerUC();
    switch (stoi(mode)){
        case 1: manager.listingClasses(mode); break;
        case 2: manager.listingClasses(mode); break;
        case 3: manager.listingClassPerYear(); break;
        case 4: manager.listingClassesPerUC(v); break;
        case 5: listingOptions(); break;
    }
}
// end menu
void endMenu(){
    printf("\n");
    printf("\033[46m=============================================================\033[0m\t\t");
}

/*
ScheduleManagement manager;
manager.readClasses();
manager.readStudents();
manager.readClassesPerUC();
set<Student> students = manager.get_students();


auto it = find_if(students.begin(), students.end(), find_by_studentName("Ludovico"));
cout << (*it).get_studentCode();
printf("\n");
/*

