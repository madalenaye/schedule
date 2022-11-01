//
// Created by Madalena Ye on 29/10/2022.
//

#include <iostream>
#include <iomanip>
#include "Menu.h"
#include <unistd.h>
using namespace std;

void createMenu(){
    printf("\n");
    printf("\033[44m======================== IɴғᴏPᴏᴄᴋᴇᴛ =========================\033[0m\t\t");
    printf("\n");
    printf("\n");
    cout << "Bem-vind@ ao melhor gestor de horários! \n"<< "O que deseja fazer hoje?"
         << endl;
    printf("\n");
    cout << "1. Listagens\n" << "2. Alterações\n" << "3. Sair do programa\n";

    string option;
    cin >> option;
    while (!(option == "1" || option == "2" || option == "3")){
        cout << "Input inválido, tente novamente: ";
        cin >> option;
    }
    if (option == "1"){
        cout << "Selecione o tipo de listagem:\n";
        cout << "1. Listagem de turmas\n" << "2. Listagem de alunos\n" << "3. Listagem de unidades curriculares\n" << "4. Listagem de horário\n" << "5. Voltar\n";
    }
    else if (option == "2"){

    }
    else endMenu();
}

void endMenu(){
    printf("\n");
    printf("\033[46m=============================================================\033[0m\t\t");
}