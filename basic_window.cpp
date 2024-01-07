#include<iostream>
#include<cmath>
#include"design.h"
#include"orderlist.h"
#include<vector>
#include<stdlib.h>
#include<string>
#include<windows.h>
#include<fstream>

void gameover() {
	getchar();
	system("cls");
	std::cout << "Congratulations , You are game over) , thanks for you play. \n\n";
	cout << "Press Enter to exit.";
	getchar();
	exit(0);
}


int* basicwindow(int* input)               //�ó�������ͼ�ν���
{
	std::cout << std::endl << std::endl << "---------------------START---------------------" << std::endl << std::endl << std::endl;
	bool hand_up = 0;

	std::cout << "Level information:   " << std::endl;      //����ؿ���Ϣ
	std::cout << "level: " << input[0] << std::endl;            //����
	std::cout << "Inbox block: " << input[1] << std::endl;     //��ľ��Ŀ
	std::cout << "block information: ";

	int* in = new int[20];
	fill(in, in + 20, 114514);
	int maxi = 0;

	for (int i = 2; i <= 21; ++i)
	{
		if (input[i] == 0)
		{
			break;
		}
		std::cout << input[i] << "   ";           //��ľ��Ϣ
		in[i - 2] = input[i];
	}
	std::cout << "\n";

	std::cout << "Enable place: " << input[22] << std::endl;   //���ÿյ���

	std::cout << "Enable order: ";
	if (input[23])
		std::cout << "inbox ";
	if (input[24])
		std::cout << "outbox ";
	if (input[25])
		std::cout << "copyfrom ";
	if (input[26])
		std::cout << "copyto ";
	if (input[27])
		std::cout << "add ";
	if (input[28])
		std::cout << "sub ";
	if (input[29])
		std::cout << "jump ";
	if (input[30])
		std::cout << "jumpifzero ";                     //����ָ������ļ��е�1,0�������ָ���Ƿ����

	std::cout << std::endl << "Output order: ";
	vector<int> target;
	int num_tar = input[31];
	for (int i = 32; i <= 32 + num_tar - 1; ++i)
	{
		std::cout << input[i] << "   ";               //������Ľ��
		target.push_back(input[i]);
	}

	std::cout << "\n\n\n\n";            //ͼ�ν�����ʽ��ʼ



	//==============================================================================================//
	int N;

	cout << "Do You need Help?	(Y/N)";
	char help;
	cin >> help;

	if (help == 'Y' || help == 'y') {
		label:cout << "Which Language do you need?    [Chinese (C) / English (E) / Japanese (J)]";
		char language;
		cin >> language;
		cout << "\n";
		switch (language){
		case 'C': {
			cout << "��Ϸ�淨tips��\n" << "��ͨ��һϵ�е�ָ��ʹ���봫�ʹ������ֱ��������ʹ������֣�ָ������Լ��������£�\n";
			cout << "������һ�����ִ���ָ��ĸ��������������ָ�����ָ������֮�����ÿո����\n";
			cout << "inbox �����봫�ʹ��ϵĻ���������Ļ���\n";
			cout << "outbox �����ϵĻ���ŵ����ʹ���\n";
			cout << "copyto x �����ϵĻ��︴�Ƶ�x�ſյ���\n";
			cout << "copyfrom x ��x�ſյ��ϵĻ��︴�Ƶ�����\n";
			cout << "add x �����ϵĻ������x�ſյ��ϵĻ���\n";
			cout << "sub x �����ϵĻ������x�ſյ��ϵĻ���\n";
			cout << "jump x ����ǰִ�е�ָ��ת��Ϊ��x��ָ�����ָ���Ŵ�1��ʼ\n";
			cout << "jumpifzero x �����ϵĻ���Ϊ0ʱ������ǰִ�е�ָ��ת��Ϊ��x��ָ�����ָ���Ŵ�1��ʼ\n\n";
			break;
		}
		case 'E': {
			cout << "Gameplay tips:\n" << "To transform the numbers on the input conveyor belt into the numbers on the output conveyor belt, follow a series of commands. Command explanations and examples are as follows:\n";
			cout << "Start by entering a number representing the number of commands, then enter the commands separated by spaces.\n";
			cout << "inbox - Take the item on the input conveyor belt and make it the item in hand.\n";
			cout << "outbox - Place the item in hand onto the conveyor belt.\n";
			cout << "copyto x - Copy the item in hand to slot x.\n";
			cout << "copyfrom x - Copy the item in slot x to the hand.\n";
			cout << "add x - Add the item in hand to the item in slot x.\n";
			cout << "sub x - Subtract the item in slot x from the item in hand.\n";
			cout << "jump x - Change the currently executing command to the command number x, where command numbers start from 1.\n";
			cout << "jumpifzero x - If the item in hand is 0, change the currently executing command to the command number x, where command numbers start from 1.\n\n";
			break;
		}
		case 'J': {
			cout << "���`��Υץ쥤�����Υҥ�ȣ�\n" << "һ�B�Υ��ޥ�ɤ�ʹ�ä��ơ���������٥��٥�Ȥ����֤��������٥��٥�Ȥ����֤ˉ�Q���ޤ��� ���ޥ�ɤ��h�������ϴΤΤȤ���Ǥ���\n";
			cout << "�ޤ������ޥ�ɤ���������֤����������Τ˥��ک`�������Фäƥ��ޥ�ɤ��������ޤ���\n";
			cout << "inbox - ��������٥��٥�ȤΥ����ƥ���֤�ȡ��ޤ���\n";
			cout << "outbox - �֤˳֤äƤ��륢���ƥ�򥳥�٥��٥�Ȥ��ä��ޤ���\n";
			cout << "copyto x - �֤˳֤äƤ��륢���ƥ��x��Ŀ�Υ���åȤ˥��ԩ`���ޤ���\n";
			cout << "copyfrom x - x��Ŀ�Υ���åȤΥ����ƥ���֤˥��ԩ`���ޤ���\n";
			cout << "add x - �֤˳֤äƤ��륢���ƥ��x��Ŀ�Υ���åȤΥ����ƥ����㤷�ޤ���\n";
			cout << "sub x - �֤˳֤äƤ��륢���ƥफ��x��Ŀ�Υ���åȤΥ����ƥ��p�㤷�ޤ���\n";
			cout << "jump x - �F�ڌg���ФΥ��ޥ�ɤ򥳥ޥ�ɷ���x�ˉ�����ޤ��� ���ޥ�ɷ��Ť�1����ʼ�ޤ�ޤ���\n";
			cout << "jumpifzero x - �֤˳֤äƤ��륢���ƥब0�Έ��ϡ��F�ڌg���ФΥ��ޥ�ɤ򥳥ޥ�ɷ���x�ˉ�����ޤ��� ���ޥ�ɷ��Ť�1����ʼ�ޤ�ޤ���\n\n";
			break;
		}
		}
		cout << "Do you need Restart help?  Press r to restart.Press any other key to continue.";
		char restart; cin >> restart;
		if (restart == 'r')
		{
			goto label;
			cout << "\n";
		}
	}

	fliter:cout << "Do you need File_input or Console_input?	(F/C)\n";
	char choice;
	cin >> choice;
	vector<vector<string>> orderlist(N, vector<string>(2, "114514"));

	if (choice == 'C') {

	std::cout << "���������ָ��" << std::endl;
		std::cin >> N;              //ָ�����Ŀ

		std::string judge;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> judge;
			if (isdigit(judge[0]))
			{
				orderlist[i - 1][1] = judge;
				i -= 1;
			}
			else
			{
				orderlist[i][0] = judge;                    //��ָ�����뵽��ά����judge�У����ҵ�һ��Ԫ��Ϊָ����ܴ��ڵĶ�ά��Ϊ��������
			}
		}
		if (orderlist[N - 1][0] != "outbox") {
			cin >> orderlist[N - 1][1];
		}
	}
	else if (choice == 'F') {
		ifstream fin;
		fin.open("./message/order.txt");
		int N;
		fin >> N;
		for (int i = 0; i < N; i++) {
			fin >> orderlist[i][0];
			if (orderlist[i][0] != "inbox" && orderlist[i][0] != "outbox" && orderlist[i][0] != "jump" && orderlist[i][0] != "jumpifzero" && orderlist[i][0] != "add" && orderlist[i][0] != "sub" && orderlist[i][0] != "copyto" && orderlist[i][0] != "copyfrom") {
				cout << "Error on instruction " << i + 1 << endl;
				cout << "please Enter again.\n";
				goto fliter;
			}
			if (orderlist[i][0] == "inbox" || orderlist[i][0] == "outbox" || orderlist[i][0] == "jump" || orderlist[i][0] == "jumpifzero") {
				continue;
			}
			else {
				fin >> orderlist[i][1];
			}
		}
		fin.close();
	}
	else {
		cout << "Error on input.\n";
		goto fliter;
	}
	for (int i = 0; i < N; i++) {
		if (orderlist[i][0] != "inbox" && orderlist[i][0] != "outbox" && orderlist[i][0] != "jump" && orderlist[i][0] != "jumpifzero" && orderlist[i][0] != "add" && orderlist[i][0] != "sub" && orderlist[i][0] != "copyto" && orderlist[i][0] != "copyfrom") {
			cout << "Error on instruction " << i + 1 << endl;
			cout << "please Enter again.\n";
			goto fliter;
		}
		if ((stoi(orderlist[i][1]) >= input[22] || stoi(orderlist[i][1]) < 0) && stoi(orderlist[i][1]) != 114514) {
			cout << "Error on instruction " << i + 1 << endl;
			cout << "please Enter again.\n";
			goto fliter;
		}
	}
	//Ҫ�����������Ҫ��ָ��������λ�ÿ��ܵ�������Ӧ���ܣ�

	//==============================================================================================//
	system("cls");
	int inhand = 114514;       //���ϵķ���
	vector<int> onempty(input[22], 114514);      //�ڿյ���ķ���
	int out[20];           //����ķ���
	fill(out, out + 20, 114514);

	int x = 0;
	int position = 0;
	bool flag1 = 1;
	bool flag2 = 0;

	getchar();

	for (int x = 0; x < N; ++x)
	{
		maxi += 1;
		if (maxi >= 100) {
			flag1 = 0;
			break;
		}

		if (orderlist[x][0] == "inbox")
		{	
			if (in[0] == 114514) {
				break;
			}

			inhand = in[0];
			position = 0;
			for (int i = 0; i < input[1] - 1; ++i)
			{
				in[i] = in[i + 1];
				in[i + 1] = 114514;
			}
			hand_up = 1;
		}                                            //inbox��ָ��

		if (orderlist[x][0] == "outbox")
		{
			if (inhand == 114514) {
				std::cerr << "Error on instruction " << x + 1;
				gameover();
			}
			else {
				for(int j = 18; j >= 0; j--) {
					out[j + 1] = out[j];
				}
				out[0] = inhand;
				position = input[22] - 1;
				inhand = 114514;
				hand_up = 1;
			}
		}                                               //outbox��ָ��

		if (orderlist[x][0] == "copyto")
		{
			if (atoi(orderlist[x][1].c_str()) > input[22]|| inhand == 114514)
			{
				std::cerr << "Error on instruction " << x + 1;
				gameover();
			}
			else
				onempty[atoi(orderlist[x][1].c_str())] = inhand;
				position = stoi(orderlist[x][1]);
		}                                                //copyto��ָ��

		if (orderlist[x][0] == "copyfrom") {
			if (atoi(orderlist[x][1].c_str()) > input[22]) {
				std::cerr << "Error on instrction " << x + 1;
				gameover();
			}
			else
				inhand = copyfrom(x, onempty[atoi(orderlist[x][1].c_str())]);
			position = stoi(orderlist[x][1]);
		}                                                   //copyfrom��ָ��

		if (orderlist[x][0] == "add") {
			if (stoi(orderlist[x][1]) > input[22] || inhand == 114514 || onempty[stoi(orderlist[x][1])] == 114514)
			{
				std::cerr << "Error on instruction " << x + 1;
				gameover();
			}

			else {
				inhand += onempty[atoi(orderlist[x][1].c_str())];
				position = stoi(orderlist[x][1]);
				hand_up = 1;
			}
		}                                                   //add��ָ��

		if (orderlist[x][0] == "sub") {
			if (stoi(orderlist[x][1]) > input[22] || inhand == 114514 || onempty[stoi(orderlist[x][1])] == 114514)
			{
				std::cerr << "Error on instruction " << x + 1;
				gameover();
			}

			else {
				inhand -= onempty[atoi(orderlist[x][1].c_str())];
				position = stoi(orderlist[x][1]);
			}                                                       //sub��ָ��
		}
		if (orderlist[x][0] == "jump") {
			if (x >= N || x == 0) {
				std::cerr << "Error on instruction " << x + 1;
				gameover();
			}
			flag2 = 1;
			UI(orderlist, position, inhand, in, out, onempty, input[22], N, x, hand_up ,input);
		}                                                      //jump��ָ��

		if (orderlist[x][0] == "jumpifzero") {
			if (x >= N || x == 0) {
				std::cerr << "Error on instruction " << x + 1;
				gameover();
			}
			if (inhand == 0) {
				flag2 = 1;
				UI(orderlist, position, inhand, in, out, onempty, input[22], N, x, hand_up , input);
			}
		}                                                         //jumpifzero��ָ��

		if (!flag2) {
			UI(orderlist, position, inhand, in, out, onempty, input[22], N, x, hand_up , input);
		}
		else {
			x = std::stoi(orderlist[x][1]) - 1;
			x -= 1;
			flag2 = 0;
		}

		hand_up = 0;
	}
	std::cout << "\n" << "Congradulations ! You successfully complete this Game, Now it's time to test your answer." << "\n" << "LOADING............." << "\n";
	getchar();

	bool flag = 1;
	for (int i = 0; i < target.size(); i++) {
		if (target[target.size() - i - 1] == out[i]) {
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	
	if (!flag) {
		cout << "HaHa , You Lose.\n";
		getchar();
		system("cls");
		cout << "ZZZZZZZZZZZZZZZZZZZ               AAA               KKKKKKKKK    KKKKKKK      OOOOOOOOO\n";
		cout << "Z:::::::::::::::::Z              A:::A              K:::::::K    K:::::K    OO:::::::::OO\n";
		cout << "Z:::::::::::::::::Z             A:::::A             K:::::::K    K:::::K  OO:::::::::::::OO\n";
		cout << "Z:::ZZZZZZZZ:::::Z             A:::::::A            K:::::::K   K::::::K O:::::::OOO:::::::O\n";
		cout << "ZZZZZ     Z:::::Z             A:::::::::A           KK::::::K  K:::::KKK O::::::O   O::::::O\n";
		cout << "        Z:::::Z              A:::::A:::::A            K:::::K K:::::K    O:::::O     O:::::O\n";
		cout << "       Z:::::Z              A:::::A A:::::A           K::::::K:::::K     O:::::O     O:::::O\n";
		cout << "      Z:::::Z              A:::::A   A:::::A          K:::::::::::K      O:::::O     O:::::O\n";
		cout << "     Z:::::Z              A:::::A     A:::::A         K:::::::::::K      O:::::O     O:::::O\n";
		cout << "    Z:::::Z              A:::::AAAAAAAAA:::::A        K::::::K:::::K     O:::::O     O:::::O\n";
		cout << "   Z:::::Z              A:::::::::::::::::::::A       K:::::K K:::::K    O:::::O     O:::::O\n";
		cout << "ZZZ:::::Z     ZZZZZ    A:::::AAAAAAAAAAAAA:::::A    KK::::::K  K:::::KKK O::::::O   O::::::O\n";
		cout << "Z::::::ZZZZZZZZ:::Z   A:::::A             A:::::A   K:::::::K   K::::::K O:::::::OOO:::::::O\n";
		cout << "Z:::::::::::::::::Z  A:::::A               A:::::A  K:::::::K    K:::::K  OO:::::::::::::OO \n";
		cout << "Z:::::::::::::::::Z A:::::A                 A:::::A K:::::::K    K:::::K    OO:::::::::OO   \n";
		cout << "ZZZZZZZZZZZZZZZZZZZAAAAAAA                   AAAAAAAKKKKKKKKK    KKKKKKK      OOOOOOOOO     \n";
		getchar();

		gameover();
	}

	if (flag == 1) {
		cout << "Conguadulations again ! \nYou complete the Game successfully . Thanks for YOUR PLAYING . \nWe will remember your story forever.\n";
		ifstream fin;
		ofstream fout;
		fin.open("./message/passmessage.txt");
		vector<string> passmessages;
		string temp;
		for (int i = 0; i < 4; i++) {
			fin >> temp;
			passmessages.push_back(temp);
		}
		passmessages[input[0] - 1] = "passed";
		fin.close();
		fout.open("./message/passmessage.txt");
		for (int i = 0; i < 4; i++) {
			fout << passmessages[i];
			fout << " ";
		}
		
		cout << "You can play the next level now.";
		exit(0);
	}

	return 0;
}
	


	
	

	

	