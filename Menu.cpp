//
// Created by Madalena Ye on 29/10/2022.
//

#include "Menu.h"

#include <iostream>
#include <windows.h>
using namespace std;

// Function to creating loading bar
void loadingBar()
{
    // 0 - black background,
    // A - Green Foreground
    system("color 0A");

    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;

    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t"
           + "Loading...\n\n");
    printf("\t\t\t\t\t");

    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        printf("%c", a);

    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");

    // Print loading bar progress
    for (int i = 0; i < 26; i++) {
        printf("%c", b);

        // Sleep for 1 second
        Sleep(1000);
    }
}

// Driver Code
int main()
{
    // Function Call
    loadingBar();
    return 0;
}