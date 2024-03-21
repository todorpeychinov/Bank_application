#include "ClassBank.h"

Bank::Bank()
{
	TableEnd = 0;
	size = 0;
	Table = NULL;
}

Bank::Bank(int array_size)
{
	TableEnd = 0;
	size = FNumber.Set(array_size);
	Table = new ClientBank[array_size];

}

Bank::~Bank()
{
	delete[] Table;
}

void Bank::Append(ClientBank obj)
{
	int help_size;
	if (TableEnd == size)
	{
		help_size = FNumber.Get();
		ClientBank* p = new ClientBank[help_size];
		for (int i = 0; i <= TableEnd; i++)
		{
			p[i] = Table[i];
		}
		
		size = help_size;
		delete[] Table;
		Table = p;

	}

	Table[TableEnd] = obj;
	TableEnd++;

}

int Bank::Delete(int client_num)
{
	for (int i = 0; i < TableEnd; i++)
	{
		if (Table[i].GetClientNum() == client_num)
		{
			for (int j = i; j < TableEnd - 1; j++)
			{
				Table[j] = Table[j+1];

			}
			TableEnd--;
			return 1;
		}
		
	}
	return -1;
}

void Bank::Print()
{
	for (int i = 0; i < TableEnd; i++)
	{
		Table[i].PrintPersonalData();
	}
}