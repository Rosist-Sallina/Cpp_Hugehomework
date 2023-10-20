#pragma once	
#include <iostream>
#include"design.h"
#include<fstream>
#include<vector>

int* Choose_level(int* output)
{
	std::vector<std::string> passmessage;   //����һ��passmessage�б����ڴ洢�Ƿ��Ѿ�ͨ���ùؿ�
	std::ifstream fin;
	std::vector<std::string> choose = { "A:level1","B:level2","C:level3","D:level4" };
	int x = 0;
	passmessage.resize(4);

	for (int i = 0; i <= 3; ++i)
	{
		fin.open("./message/passmessage.txt");
		if (!fin)
		{
			std::cerr << "Open this file ERROR����";
		}

		fin >> passmessage[i]; //��ȡ�ĵ���Ϣ����ʶ��
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

	std::cout << "Please enter you choice:" << std::endl;  //��ʼѡ��֧

	char middle;
	std::cin >> middle;
	
	int i = 0;

	
	if ( middle == 'A')
	{
		std::cout << "You have chosen level1." << std::endl;
		fin.open("./message/file1.txt");
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
		fin.open("./message/file2.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		} 
		while (!fin.eof())
		{
			fin >> output[i];
			i++;
		}
	}
	if (middle == 'C')
	{
		std::cout << "You have chosen level3." << std::endl;
		fin.open("./message/file3.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		}   
		while (!fin.eof())
		{
			fin >> output[i];
			i++;
		}
	}
	if (middle == 'D')
	{
		std::cout << "You have chosen level4." << std::endl;
		fin.open("./message/file4.txt");
		if (!fin)
		{
			std::cerr << "But open this file ERROR";
		}    
		while (!fin.eof())
		{
			fin >> output[i];
			i++;
		}
	}
                            //��if���ѡ����沢��ȡ��Ӧ�Ĺؿ���Ϣ

	return output;
}
	
