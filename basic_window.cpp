#include <iostream>
#include<cmath>
#include"design.h"
#include"orderlist.h"
#include<vector>

int* basicwindow(int* input)               //该程序主管图形界面
{
	std::cout << std::endl<<std::endl<< "---------------------START---------------------" << std::endl<<std::endl<<std::endl;

	std::cout << "Level infprmation:   "<<std::endl;      //输出关卡信息
	std::cout << "level: " << input[0] <<std::endl;            //级别
	std::cout << "Inbox block: " << input[1] << std::endl;     //积木数目
	std::cout << "block information: ";           
	for (int i = 2; i <= 21; ++i)
	{
		if (input[i] == 0)
		{
			break;
		}
		std::cout << input[i] << " , ";           //积木信息
	}

	std::cout << "Enable place: " << input[22]<<std::endl;   //可用空地数

	std::cout << "Enable order: ";
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

	std::cout <<std::endl<< "Output order: ";
	for (int i = 31; i <= 41; ++i)
	{
		if (input[i] == 0)
		{
			break;
		}
		std::cout << input[i] << " , ";               //需输出的结果
	}

	std::cout << "\n\n\n\n";            //图形界面正式开始



	//==============================================================================================//
	int N;
	std::string** orderlist = new std::string*[N];
	for (int i = 0;i<N;++i)
		orderlist[i] = new std::string[2];


	std::cout << "请输入你的指令"<<std::endl;
	std::cin >> N;              //指令的数目
	
	std::string judge;
	for (int i = 0; i<N; ++i)
	{
		std::cin >> judge;
		if (isdigit(judge[0]) != 0)
		{
			orderlist[i - 1][2] = judge;
			i -= 1;
		}
		else
		{
			orderlist[i][1] = judge;                    //将指令输入到二维数组judge中，并且第一个元素为指令，可能存在的二维项为其伴随参数
		}
	}

		 


	//要求玩家输入需要的指令（该区块的位置可能调整以适应功能）

	//==============================================================================================//



	int* in = new int[input[1]];
	int* out = new int[input[1]];    //读取文件并将其添加到数组中作为调用基础


	int type = 7;                   //用于定义该模块中可能出现的数组，int整型等

	/* std::cout << "     +---+";
	
	
	//for (int type = 7; type < 30; type += 7)
	//{
		for (int i = 0; i < type; ++i)
			std::cout << " ";
		std::cout << "+---+";
		for (int i = 0; i < 30 - type; ++i)
			std::cout << " ";
	//}
	for (int i = 0; i < 10; ++i)
		std::cout << " ";
	std::cout << "+---+" << "\n";          //第一行的程序（未加循环使其能移动）

	std::cout << "IN   ";
	std::cout << "| " << input[2] << " |";
	for (int i = 0; i < type; ++i)
		std::cout << " ";                  //第二行传送带现有的东西

	std::cout << "| " << inhand << " |";
	for (int i = 0; i < 30 - type; ++i)
		std::cout << " ";

	for (int i = 0; i < 10; ++i)
		std::cout << " ";

	std::cout << "| " << out[1] << "| ";
	std::cout << "   OUT";


	return 0;
}       */                     //试图改掉原来的代码

	int* in = new int[input[1]];
	int inhand;
	int* onempty = new int[input[22]];
	int* out = new int[input[1]];

	inhand = in[0];
	in = inbox(in, input[1]);

	if()

	