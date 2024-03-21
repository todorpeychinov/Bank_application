#pragma once
#include <stdio.h>
#include <string.h>


typedef struct
{
    char account_type[10];
    char IBAN[23];
    float balance;
}bank_account;



class ClientBank
{
    char first_name[20];
    char last_name[20];
    int client_number;
    int accounts_count;
    bank_account accounts[10];

public:
    static int newClientNumber;

    ClientBank();
    ClientBank(const char* name, const char* family_name);
    ClientBank(ClientBank& obj);
    void AddBankAccount(const char* type, const char* iban, float ac_balance);
    void DeleteAccount(const char* iban);
    void SearchAccount(const char* iban);
    void AddMoney(const char* iban, float sum);
    float TotalBalance();
    void PrintAll();
    ClientBank& operator = (ClientBank& obj);
    int GetClientNum();
    void PrintPersonalData();

};