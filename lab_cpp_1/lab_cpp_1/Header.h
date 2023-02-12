#pragma once  // <<<===
#include <iostream>  // <<<===

namespace write1
{
	void output();
	void output(char symbol);
	void output(char symbol, int amount);
}

namespace write2
{
	void threeBefore(char symbol = '$', int amount = 5);
}

namespace arrays3
{
	int oddSum(int[], int);
	double oddSum(double[], int);
	template <typename Type>
	Type oddSum(Type massiv[], int SIZE)
	{
		Type sum = 0;
		for (int i = 0; i < SIZE; i += 2)
		{
			sum += massiv[i];
		}
		return sum;
	}
}

namespace unknown4
{
	template <typename Type>
	Type maximEven(Type start, ...)
	{
		Type *pstart = &start;
		Type maxim = start;
		while (*pstart)
		{
			if (*pstart > maxim)
			{
				maxim = *pstart;
			}
			pstart+=2;  // int = 4 байта, *int = 8 байт, *int+=1 прибавляет 4 байта, а не 8, потому +=2
		}
		return maxim;
	}
}