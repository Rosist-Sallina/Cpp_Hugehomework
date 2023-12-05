#include<iostream>
#include<cmath>
#include"design.h"
#include"orderlist.h"
#include<vector>
#include<stdlib.h>
#include<string>

void gameover() {
	std::cout << "Congratulations , You are game over) , thanks for you play.";
	exit (0);
}

int* basicwindow(int* input)               //�ó�������ͼ�ν���
{
	std::cout << std::endl << std::endl << "---------------------START---------------------" << std::endl << std::endl << std::endl;

	std::cout << "Level infprmation:   " << std::endl;      //����ؿ���Ϣ
	std::cout << "level: " << input[0] << std::endl;            //����
	std::cout << "Inbox block: " << input[1] << std::endl;     //��ľ��Ŀ
	std::cout << "block information: ";

	int* in = new int[input[1]];

	for (int i = 2; i <= 21; ++i)
	{
		if (input[i] == 0)
		{
			break;
		}
		std::cout << input[i] << " , ";           //��ľ��Ϣ
		in[i - 2] = input[i];
	}
	std::cout << "\n";

	std::cout << "Enable place: " << input[22] << std::endl;   //���ÿյ���

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
		std::cout << "jumpifzero , ";                     //����ָ������ļ��е�1,0�������ָ���Ƿ����

	std::cout << std::endl << "Output order: ";
	for (int i = 31; i <= 41; ++i)
	{
		if (input[i] == 0)
		{
			break;
		}
		std::cout << input[i] << " , ";               //������Ľ��
	}

	std::cout << "\n\n\n\n";            //ͼ�ν�����ʽ��ʼ



	//==============================================================================================//
	int N;

	std::cout << "���������ָ��" << std::endl;
	std::cin >> N;              //ָ�����Ŀ

	std::string** orderlist = new std::string * [N];
	for (int i = 0; i < N; ++i)
		orderlist[i] = new std::string[2];

	std::string judge;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> judge;
		if (isdigit(judge[0]))
		{
			orderlist[i - 1][2] = judge;
			i -= 1;
		}
		else
		{
			orderlist[i][1] = judge;                    //��ָ�����뵽��ά����judge�У����ҵ�һ��Ԫ��Ϊָ����ܴ��ڵĶ�ά��Ϊ��������
		}
	}

	//Ҫ�����������Ҫ��ָ��������λ�ÿ��ܵ�������Ӧ���ܣ�

	//==============================================================================================//


	int type = 7;                   //���ڶ����ģ���п��ܳ��ֵ����飬int���͵�

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
	std::cout << "+---+" << "\n";          //��һ�еĳ���δ��ѭ��ʹ�����ƶ���

	std::cout << "IN   ";
	std::cout << "| " << input[2] << " |";
	for (int i = 0; i < type; ++i)
		std::cout << " ";                  //�ڶ��д��ʹ����еĶ���

	std::cout << "| " << inhand << " |";
	for (int i = 0; i < 30 - type; ++i)
		std::cout << " ";

	for (int i = 0; i < 10; ++i)
		std::cout << " ";

	std::cout << "| " << out[1] << "| ";
	std::cout << "   OUT";


	return 0;
}       */                     //��ͼ�ĵ�ԭ���Ĵ���

	int inhand;       //���ϵķ���
	int* onempty = new int[input[22]];      //�ڿյ���ķ���
	int* out = new int[input[1]];           //����ķ���


	for (int x = 0; x < N; ++x)
	{
			if (orderlist[x][0] == "inbox")
			{
				inhand = in[0];
				for (int i = 0; i < input[1] - 1; ++i)
				{
					in[i] = in[i + 1];
				}
				continue;
			}                                            //inbox��ָ��

			if (orderlist[x][0] == "outbox")
			{
				if (inhand == 0 || isdigit(inhand) == 0) {
					std::cerr << "Error on instruction " << x + 1;
					gameover();
				}
				else {
					out[0] = inhand;
					if (&out[input[1] - 1] != NULL) {
						for (int i = 0; i < input[1] - 1; i++) {
							out[i + 1] = out[i];
						}
					}
				}
				continue;
			}                                               //outbox��ָ��

			if (orderlist[x][0] == "copyto")
			{
				if (atoi(orderlist[x][1].c_str()) > input[22] || atoi(orderlist[x][1].c_str()) == 0 || &inhand == NULL)
				{
					std::cerr << "Error on instruction " << x + 1;
					gameover();
				}
				else
					onempty[atoi(orderlist[x][1].c_str())] = copyto(x, inhand);
				continue;
			}                                                //copyto��ָ��

			if (orderlist[x][0] == "copyfrom") {
				if (atoi(orderlist[x][1].c_str()) > input[22] || atoi(orderlist[x][1].c_str()) == 0) {
					std::cerr << "Error on instrction " << x + 1;
					gameover();
				}
				else
					inhand = copyfrom(x, onempty[atoi(orderlist[x][1].c_str())]);
				continue;
			}                                                   //copyfrom��ָ��

			if (orderlist[x][0] == "add") {
				if (atoi(orderlist[x][1].c_str()) > input[22] || atoi(orderlist[x][1].c_str()) == 0 || &inhand == NULL || onempty[std::stoi(orderlist[x][0])] == 0)
				{
					std::cerr << "Error on instruction " << x + 1;
					gameover();
				}

				else {
					inhand += onempty[atoi(orderlist[x][1].c_str())];
				}
				continue;
			}                                                   //add��ָ��

			if(orderlist[x][0] == "sub") {
				if (atoi(orderlist[x][1].c_str()) > input[22] || atoi(orderlist[x][1].c_str()) == 0 || &inhand == NULL || &orderlist[x][0] == NULL)
				{
					std::cerr << "Error on instruction " << x + 1;
					gameover();
				}
				
				else {
					inhand -= onempty[atoi(orderlist[x][1].c_str())];
					continue;
			}                                                       //sub��ָ��

			if (orderlist[x][0] == "jump") {
				if (x >= N || x == 0) {
					std::cerr << "Error on instruction " << x + 1;
					gameover();
				}
				x = std::stoi(orderlist[x][1]);
				continue;
			}                                                      //jump��ָ��

			if (orderlist[x][0] == "jumpifzero") {
				if (x >= N || x == 0) {
					std::cerr << "Error on instruction " << x + 1;
					gameover();
				}
				if (inhand == 0) {
					x = std::stoi(orderlist[x][1]);
				}
			}                                                         //jumpifzero��ָ��
		}
	}

	                                               //˼·����UI���浥�����ɺ���
}
	


	
	

	

	