#include <iostream>
#include<cmath>
#include"design.h"

int* basicwindow(int* input)               //�ó�������ͼ�ν���
{
	std::cout << std::endl<<std::endl<< "---------------------START---------------------" << std::endl<<std::endl<<std::endl;

	std::cout << "Level infprmation:   ";      //����ؿ���Ϣ
	std::cout << "level: " << input[0];            //����
	std::cout << " Inbox block: " << input[1];     //��ľ��Ŀ
	std::cout << " block information: ";           
	for (int i = 2; i <= 21; ++i)
	{
		if (input[i] == 0)
		{
			break;
		}
		std::cout << input[i] << " , ";           //��ľ��Ϣ
	}

	std::cout << "Enable place: " << input[22];   //���ÿյ���

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
		std::cout << "jumpifzero , ";                     //����ָ������ļ��е�1,0�������ָ���Ƿ����

	std::cout << "Output order: ";
	for (int i = 31; i <= 41; ++i)
	{
		if (input[i] == 0)
		{
			break;
		}
		std::cout << input[i] << " , ";               //������Ľ��
	}

	std::cout << "\n\n\n\n";                          //ͼ�ν�����ʽ��ʼ

	std::cout << "     +---+";
	





}