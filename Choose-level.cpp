#pragma once	
#include <iostream>
#include"design.h"
#include<fstream>
#include<vector>

int* Choose_level(int* output)
{
	std::vector<std::string> passmessage;   //定义一个passmessage列表用于存储是否已经通过该关卡
	std::ifstream fin;
	std::vector<std::string> choose = { "A:level1","B:level2","C:level3","D:level4","E:Level5"};
	int x = 0;
	passmessage.resize(5);
	fin.open("./message/passmessage.txt");
	if (!fin)
	{
		std::cerr << "Open this file ERROR——";
	}

	for (int i = 0; i <= 4; ++i)
	{
		fin >> passmessage[i]; //读取文档信息用于识别
		std::cout << choose[i];
		if (passmessage[i] == "passed")
			std::cout << "       (passed)      ";
		else
			std::cout << "                     ";

		++x;
		if (x >= 1) {
			std::cout << std::endl;
			x = 0;
		}
	}
	fin.close();

	std::cout << "Please enter you choice:" << std::endl;  //开始选择支

	char middle;
	fliter:std::cin >> middle;
	
	int i = 0;

	
	if ( middle == 'A')
	{
		std::cout << "You have chosen level1." << std::endl;
		fin.open("./message/config1.txt");
		if (!fin)
		{
			std::cerr << "Open this file ERROR";
		}	
		while (!fin.eof() && i <100)
		{
			fin >> output[i];
			++i;
		}
	}
	if (middle == 'B')
	{
		std::cout << "You have chosen level2." << std::endl;
		fin.open("./message/config2.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		} 
		while (!fin.eof())
		{
			fin >> output[i];
			i++;
		}
		if (passmessage[0] != "passed")
		{
			std::cout << "You can't play this level." << std::endl;
			cout << "please choose again." << endl;
			goto fliter;
		}
	}
	if (middle == 'C')
	{
		std::cout << "You have chosen level3." << std::endl;
		fin.open("./message/config3.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		}   
		while (!fin.eof())
		{
			fin >> output[i];
			i++;
		}
		if (passmessage[1] != "passed")
		{
			std::cout << "You can't play this level." << std::endl;
			cout << "please choose again." << endl;
			goto fliter;
		}
	}
	if (middle == 'D')
	{
		std::cout << "You have chosen level4." << std::endl;
		fin.open("./message/config4.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		}    
		while (!fin.eof())
		{
			fin >> output[i];
			i++;
		}
		if (passmessage[2] != "passed")
		{
			std::cout << "You can't play this level." << std::endl;
			cout << "please choose again." << endl;
			goto fliter;
		}
	}
	if (middle == 'E')
	{
		std::cout << "You have chosen level5." << std::endl;
		fin.open("./message/config5.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		}
		while (!fin.eof())
		{
			fin >> output[i];
			i++;
		}
		if (passmessage[3] != "passed")
		{
			std::cout << "You can't play this level." << std::endl;
			cout << "please choose again." << endl;
			goto fliter;
		}
	}
                            //用if语句选择界面并读取对应的关卡信息

	return output;
}
	
