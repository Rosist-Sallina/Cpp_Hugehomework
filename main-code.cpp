#include <iostream>
#include"design.h"
#include <fstream>

int main()
{
	std::cout << "Welcome to the game.\n";
	std::cout << "Please choose your level.\n";
	
	int middle[10];
	int *input = Choose_level(middle);
	basicwindow(input);

	return 0;



}

