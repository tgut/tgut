#include <iostream>

int main()
{
	const int x = 99;
	int y = const_cast<int>(x);
}