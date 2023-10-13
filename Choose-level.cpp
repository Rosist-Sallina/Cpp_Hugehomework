#pragma once	
#include <iostream>
#include"design.h"
#include<fstream>
#include<vector>

int Choose_level()
{
	std::vector<std::string> passmessage;   //定义一个passmessage列表用于存储是否已经通过该关卡
	std::ifstream fin;
	std::vector<std::string> choose = { "level1","level2","level3","level4" };
	int x = 0;
	passmessage.resize(4);

	for (int i = 0; i <= 3; ++i)
	{
		fin.open("./message/passmessage.txt");
		if (!fin)
		{
			std::cerr << "Open this file ERROR——";
		}

		fin >> passmessage[i]; //读取文档信息用于识别
		fin.close();

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

	std::cout << "Please enter you choice:" << std::endl;  //开始选择支

	char middle;
	std::cin >> middle;

	switch (middle)
	{
	case 'A':
	{
		std::cout << "You have chosen level1." << std::endl;
		fin.open("./message/file1.txt");
		if (!fin)
		{
			std::cerr << "Open this file ERROR";
		}	break;
	}
	case 'B':
	{
		std::cout << "You have chosen level2." << std::endl;
		fin.open("./message/file2.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		} break;
		
	}
	case 'C':
	{
		std::cout << "You have chosen level3." << std::endl;
		fin.open("./message/file3.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		}    break;
	}
	case 'D':
	{
		std::cout << "You have chosen level4." << std::endl;
		fin.open("./message/file4.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		}    break;
	}
	}                            //用switch语句选择界面并读取对应的关卡信息

	return 0;
}
	
