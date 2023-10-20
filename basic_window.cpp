#include <iostream>
#include<cmath>
#include"design.h"

int* basicwindow(int* input)               //该程序主管图形界面
{
	std::cout << std::endl<<std::endl<< "---------------------START---------------------" << std::endl<<std::endl<<std::endl;

	std::cout << "Level infprmation:   ";      //输出关卡信息
	std::cout << "level: " << input[0];            //级别
	std::cout << " Inbox block: " << input[1];     //积木数目
	std::cout << " block information: ";           
	for (int i = 2; i <= 21; ++i)
	{
		if (input[i] == 0)
		{
			break;
		}
		std::cout << input[i] << " , ";           //积木信息
	}

	std::cout << "Enable place: " << input[22];   //可用空地数

	std::cout << " Enable order: ";
	if (input[23])
		std::cout << "inbox , ";
	if (input[24])
		std::cout << "outbox , ";
	if (input[25])
		std::cout << "copyfrom , ";
	if (input[26])
		std::cout << "copyto , ";
	if (input[27])
		std::cout << "add , ";
	if (input[28])
		std::cout << "sub , ";
	if (input[29])
		std::cout << "jump , ";
	if (input[30])
		std::cout << "jumpifzero , ";                     //可用指令集，用文件中的1,0来代表该指令是否可用

	std::cout << "Output order: ";
	for (int i = 31; i <= 41; ++i)
	{
		if (input[i] == 0)
		{
			break;
		}
		std::cout << input[i] << " , ";               //需输出的结果
	}

	std::cout << "\n\n\n\n";                          //图形界面正式开始

	std::cout << "     +---+";
	





}