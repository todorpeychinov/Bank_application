#pragma once
#include "ClassClientBank.h"
#include "ClassFibonacci.h"

class Bank
{
	int TableEnd;
	int size;
	ClientBank* Table;
	Fibonacci FNumber;

public:

	Bank();
	Bank(int array_size);
	~Bank();
	void Append(ClientBank obj);
	int Delete(int client_num);
	void Print();
};