//
// Created by Madalena Ye on 29/10/2022.
//
#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "ScheduleManagement.h"
#include <unistd.h>
#include <algorithm>
#include "Request.h"
#include <vector>
using namespace std;

//manager


// for later implementation

//creating menu
void createMenu(){
    printf("\n");
    printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");
    printf("\n");
    printf("\n");
    cout << setw(53) << "Bem-vind@ ao melhor gestor de horários! \n";
    ScheduleManagement manager;
    manager.readClasses();
    manager.readStudents();
    menuOperations(manager);
}

//types of operations
void menuOperations(ScheduleManagement manager){
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
    if (option == "1") listingOptions(manager);
    else if (option == "2"){
    modifyOptions(manager);
    }
        // end program
    else {
        terminate(manager);
        //
    }
}
//listing options
void listingOptions(ScheduleManagement manager){
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
        if (type == "1"){listClasses(manager);}
        else if (type == "2"){listStudents(manager);}
        else if (type == "3"){listSchedule(manager);}
        else if (type == "4"){listUCs(manager);}
        else{
            printf("\n");printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t"); cout << "\n" << "\n"; menuOperations(manager);}
}
void listClasses(ScheduleManagement manager){
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
    switch (stoi(mode)){
        case 1: manager.listingClasses(mode); break;
        case 2: manager.listingClasses(mode); break;
        case 3: manager.listingClassPerYear(); break;
        case 4: manager.listingClassesPerUC(manager.readClassesPerUC()); break;
        case 5: listingOptions(manager); break;
    }
}
void listStudents(ScheduleManagement manager){
    cout << "\nSelecione o modo de listagem de alunos:\n";
    cout << "1. Ordem alfabética\n" << "2. Por número de estudante\n" << "3. Por ano de entrada\n" << "4. Por ano curricular\n" << "5. Por turma\n" << "6. Alunos com mais de n UC's\n" << "7. Voltar";
    cout << "\nOpção: ";
    string mode;
    cin >> mode;
    // input error
    while (!(mode == "1" || mode == "2" || mode == "3" || mode == "4" || mode == "5" || mode == "6" || mode == "7")){
        cout << "Input inválido, tente novamente: ";
        cin >> mode;
    }
    switch (stoi(mode)){
        case 1: manager.listingAllStudentsName(); break;
        case 2: manager.listingAllStudentsCode(); break;
        case 3: manager.listingStudentsByYearOfEntry(); break;
        case 4: manager.listingStudentsInYear(); break;
        case 5: manager.listingStudentsInClass(); break;
        case 6: manager.listingStudentsWithNUCs(); break;
        case 7: listingOptions(manager); break;
    }
}
void listUCs(ScheduleManagement manager){
    cout << "\nSelecione o modo de listagem de unidades curriculares:\n";
    cout << "1. Ordem crescente\n" << "2. Ordem decrescente\n" << "3. Por ano\n" << "4. Por aluno\n" << "5. Por turma\n" << "6. Voltar";
    cout << "\nOpção: ";
    string mode;
    cin >> mode;
    // input error
    while (!(mode == "1" || mode == "2" || mode == "3" || mode == "4" || mode == "5" || mode == "6")){
        cout << "Input inválido, tente novamente: ";
        cin >> mode;
    }
    switch (stoi(mode)){
        case 1: manager.listingAllUCs("1", manager.readClassesPerUC()); break;
        case 2: manager.listingAllUCs("2", manager.readClassesPerUC()); break;
        case 3: manager.listingUCsByYear(); break;
        case 4: manager.listingUcsPerStudent(); break;
        case 5: manager.listingUcsByClass(); break;
        case 6: listingOptions(manager); break;
    }
}
void listSchedule(ScheduleManagement manager){
    cout << "\nSelecione o modo de listagem do horário:\n";
    cout << "1. Por aluno\n" << "2. Por turma\n" << "3. Por UC\n" << "4. Voltar\n";
    cout << "\nOpção: ";
    string mode;
    cin >> mode;
    // input error
    while (!(mode == "1" || mode == "2" || mode == "3" || mode == "4")){
        cout << "Input inválido, tente novamente: ";
        cin >> mode;
    }
    switch (stoi(mode)){
        case 1: manager.listingStudentSchedule(); break;
        case 2: manager.listingClassSchedule(); break;
        case 3: manager.listingUcSchedule(); break;
        case 4: listingOptions(manager); break;
    }
}
// modification options
void modifyOptions(ScheduleManagement manager){
    cout << "\nSelecione a alteração que pretende realizar: \n";
    cout << "1. Remover um estudante\n" << "2. Adicionar um estudante\n" << "3. Alterar a turma/UC de um estudante\n" << "4. Alterar um conjunto de turmas/UCs de um estudante\n" << "5. Voltar\n";
    cout << "\nOpção: ";
    string type;
    cin >> type;
    // input error
    while (!(type == "1" || type == "2" || type == "3" || type == "4" || type == "5")){
        cout << "Input inválido, tente novamente: ";
        cin >> type;
    }
    if (type == "1"){
        cout << "Introduza o número up do estudante que deseja remover (Ex:202025487): ";
        long int up; cin >> up;
        cout << "Em que unidade curricular? (Ex: L.EIC002): ";
        string uc; cin >> uc;
        cout << "E a turma? (Ex: 1LEIC08): ";
        string _class; cin >> _class;
        Request r(REMOVE, up,uc,_class, "");
        manager.push_request(r);

        cout << "\nDeseja realizar outra operação (Y/N)? ";
        cout << "(Nota: as modificações, caso aceites, só serão feitas ao final do dia) ";
        string answer; cin >> answer;
        while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
            cout << "Input inválido, tente novamente: ";
            cin >> answer;
        }
        if (answer == "Y" || answer == "y"){
            printf("\n");
            printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");
            printf("\n");
            printf("\n");
            menuOperations(manager);
        }
        else terminate(manager);

    }
    else if (type == "2"){
        cout << "Introduza o número up do estudante que deseja adicionar (Ex:202025487): ";
        long int up; cin >> up;
        cout << "Em que unidade curricular? (Ex: L.EIC002): ";
        string uc; cin >> uc;
        cout << "E a que turma? (Ex: 1LEIC08): ";
        string _class; cin >> _class;
        Request r(ADD, up,uc,_class, "");
        manager.push_request(r);
        cout << "\nDeseja realizar outra operação? (Y/N)? ";
        string answer; cin >> answer;
        while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
            cout << "Input inválido, tente novamente: ";
            cin >> answer;
        }
        if (answer == "Y" || answer == "y"){
            printf("\n");
            printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");
            printf("\n");
            printf("\n");
            menuOperations(manager);
        }
        else terminate(manager);

    }
    else if (type == "3"){
        cout << "Introduza o número up do estudante cuja turma/UC deseja alterar (Ex:202025487): ";
        long int up; cin >> up;
        cout << "Em que unidade curricular? (Ex: L.EIC002): ";
        string uc; cin >> uc;
        cout << "Em que turma se encontrava o estudante? (Ex: 1LEIC08): ";
        string _class; cin >> _class;
        cout << "Para que turma o estudante pretende ir? (Ex: 1LEIC08): ";
        string new_class; cin >> new_class;
        Request r(CHANGE_CLASS, up,uc,_class, new_class);
        manager.push_request(r);
        cout << "\nDeseja realizar outra operação? (Y/N)? ";
        string answer; cin >> answer;
        while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
            cout << "Input inválido, tente novamente: ";
            cin >> answer;
        }
        if (answer == "Y" || answer == "y"){
            printf("\n");
            printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");
            printf("\n");
            printf("\n");
            menuOperations(manager);
        }
        else terminate(manager);
    }
    else if (type == "4"){
        cout << "Introduza o número up do estudante cujas turmas/UCs deseja alterar (Ex:202025487): ";
        long int up; cin >> up;
        cout << "Quantas turmas/UCs pretende alterar?: ";
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            cout << i << "ª alteração: \n";
            cout << "Em que unidade curricular? (Ex: L.EIC002): ";
            string uc;
            cin >> uc;
            cout << "Em que turma se encontrava o estudante? (Ex: 1LEIC08): ";
            string _class;
            cin >> _class;
            cout << "Para que turma o estudante pretende ir? (Ex: 1LEIC08): ";
            string new_class;
            cin >> new_class;
            Request r(CHANGE_CLASS, up, uc, _class, new_class);
            manager.push_request(r);
        }
        cout << "\nDeseja realizar outra operação? (Y/N)? ";
        string answer; cin >> answer;
        while (!(answer == "Y" || answer == "N" || answer == "n" || answer == "y")){
            cout << "Input inválido, tente novamente: ";
            cin >> answer;
        }
        if (answer == "Y" || answer == "y") {
            printf("\n");
            printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");
            printf("\n");
            printf("\n");
            menuOperations(manager);
        }
        else terminate(manager);
    }

    else {
        printf("\n");
        printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");
        printf("\n");
        printf("\n");
        menuOperations(manager);
    }

}
void terminate(ScheduleManagement manager){

    while(!manager.get_requests().empty()){manager.doRequest();}
}
// end menu
void endMenu(){
    printf("\n");
    printf("\033[46m=============================================================\033[0m\t\t");
}


