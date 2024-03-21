#include "ClassFibonacci.h"

Fibonacci::Fibonacci()
{
	f1 = 1;
	f2 = 1;
}

int Fibonacci::Get()
{
	int help; 
	help = f1 + f2;
	f1 = f2;
	f2 = help;

	return f2;
}

int Fibonacci::Set(int number)
{
	int help;
	if (number > f1 || number > f2)
	{
		for (help = Get(); number > help; help = Get());
		if (number == help)
		help = Get();
			help = Get();

	}
	return help;
}