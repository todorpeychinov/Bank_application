#include "ClassClientBank.h"




ClientBank::ClientBank()
{
    first_name[0] = 0;
    last_name[0] = 0;
    accounts_count = 0; 
    

}


ClientBank::ClientBank(const char* name, const char* family_name)
{
    strcpy_s(first_name, name);
    strcpy_s(last_name, family_name);
    accounts_count = 0;
    client_number = newClientNumber;
    newClientNumber++;


}

ClientBank::ClientBank(ClientBank& obj)
{
    strcpy_s(first_name, obj.first_name);
    strcpy_s(last_name, obj.last_name);
    client_number = obj.client_number;
    accounts_count = obj.accounts_count;
    memcpy(accounts, obj.accounts, sizeof(accounts));
}


void ClientBank::AddBankAccount(const char* type, const char* iban, float ac_balance)
{
    strcpy_s(accounts[accounts_count].account_type, type);
    strcpy_s(accounts[accounts_count].IBAN, iban);
    accounts[accounts_count].balance = ac_balance;
    accounts_count++;

}


void ClientBank::DeleteAccount(const char* iban)
{
    for (int i = 0; i < accounts_count; i++)
    {
        if (strcmp(accounts[i].IBAN, iban) == 0)
        {
            if (accounts[i].balance >= 0)
            {
                if (i != accounts_count)
                {
                    strcpy_s(accounts[i].account_type, accounts[accounts_count - 1].account_type);
                    strcpy_s(accounts[i].IBAN, accounts[accounts_count - 1].IBAN);
                    accounts[i].balance = accounts[accounts_count - 1].balance;
                    accounts[accounts_count - 1].account_type[0] = 0;
                    accounts[accounts_count - 1].IBAN[0] = 0;
                    accounts[accounts_count - 1].balance = 0;
                    accounts_count--;
                    printf("Account with IBAN: %s is deleted!\n\n", accounts[i].IBAN);
                }
                else
                {
                    accounts[accounts_count - 1].account_type[0] = 0;
                    accounts[accounts_count - 1].IBAN[0] = 0;
                    accounts[accounts_count - 1].balance = 0;
                    accounts_count--;
                    printf("Account with IBAN: %s is deleted!\n\n", accounts[i].IBAN);
                }
            }

            else
            {
                printf("Your balance is: %.2f. It's impossible to delete accounts with negative balance!\n\n", accounts[i].balance);
            }
            break;
        }

        if ((strcmp(accounts[i].IBAN, iban) != 0) && (i == accounts_count - 1))
        {
            printf("There is no account with IBAN: %s\n\n", iban);
        }

    }
}

void ClientBank::SearchAccount(const char* iban)
{
    for (int i = 0; i < accounts_count; i++)
    {
        if (strcmp(accounts[i].IBAN, iban) == 0)
        {
            printf("\nIBAN: %s\nAccount type: %s\nBalance: %.2f\n\n", accounts[i].IBAN, accounts[i].account_type, accounts[i].balance);
            break;
        }
        if ((strcmp(accounts[i].IBAN, iban) != 0) && (i == accounts_count - 1))
        {
            printf("There is no account with IBAN: %s\n\n", iban);
        }

    }
}

void ClientBank::AddMoney(const char* iban, float sum)
{
    for (int i = 0; i < accounts_count; i++)
    {
        if (strcmp(accounts[i].IBAN, iban) == 0)
        {
            accounts[i].balance += sum;
            printf("You successfully added %.2f lv to the account with IBAN: %s \n", sum, iban);
            break;
        }
        if ((strcmp(accounts[i].IBAN, iban) != 0) && (i == accounts_count - 1))
        {
            printf("There is no account with IBAN: %s", iban);
        }
    }
}

float ClientBank::TotalBalance()
{
    float total_sum = 0;

    for (int i = 0; i < accounts_count; i++)
    {
        total_sum += accounts[i].balance;
    }
    return total_sum;
}

void ClientBank::PrintAll()
{


    for (int i = 0; i < accounts_count; i++)
    {
        printf("Client: %s %s\n", first_name, last_name);
        printf("\nAccount[%d]\nIBAN: %s\nAccount type: %s\nBalance: %.2f\n\n\n", i + 1, accounts[i].IBAN, accounts[i].account_type, accounts[i].balance);

    }
}

ClientBank& ClientBank::operator = (ClientBank& obj)
{
    strcpy_s(first_name, obj.first_name);
    strcpy_s(last_name, obj.last_name);
    client_number = obj.client_number;
    accounts_count = obj.accounts_count;

    for (int i = 0; i < 10; i++)
    {
        accounts[i] = obj.accounts[i];

    }
    return *this;
}

int ClientBank::GetClientNum()
{
    return client_number;
}

void ClientBank::PrintPersonalData()
{
    printf("\n%s\n", first_name);
    printf("%s\n", last_name);
    printf("%d\n", client_number);
}
