// Bank_application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include "ClassClientBank.h" 
#include "ClassBank.h"
#include "ClassFibonacci.h"


int ClientBank::newClientNumber = 1;


int main()
{
   
    int array_size = 2;
    Bank test_bank(array_size);
    char name[20];
    char family_name[20];
    

    for (int i = 0; i < array_size; i++)
    {
        printf("Enter the first name of client[%d]: ",i + 1);
        gets_s(name);
        printf("Enter the family name of client[%d]: ",i + 1);
        gets_s(family_name);
        ClientBank help(name,family_name);
        test_bank.Append(help);

    }

    printf("\n\n\n=========================================================\n\n\n");

    test_bank.Print();

   
    
    


    

}

