#include <iostream>
#include"design.h"
#include <fstream>

int main()
{
	std::cout << "Welcome to the game.\n";
	std::cout << "Please choose your level.\n";
	
	int middle[10];
	int *input = Choose_level(middle);
	int* output = basicwindow(input);

	//for (int i = 0; i < 9; ++i)
	//{
	//	std::cout << input[i] << " ";
	//}          //检验指针是否导出成功

	return 0;



}

