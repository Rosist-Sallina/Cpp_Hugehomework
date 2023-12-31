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


int* basicwindow(int* input)               //该程序主管图形界面
{
	std::cout << std::endl << std::endl << "---------------------START---------------------" << std::endl << std::endl << std::endl;
	bool hand_up = 0;

	std::cout << "Level information:   " << std::endl;      //输出关卡信息
	std::cout << "level: " << input[0] << std::endl;            //级别
	std::cout << "Inbox block: " << input[1] << std::endl;     //积木数目
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
		std::cout << input[i] << "   ";           //积木信息
		in[i - 2] = input[i];
	}
	std::cout << "\n";

	std::cout << "Enable place: " << input[22] << std::endl;   //可用空地数

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
		std::cout << "jumpifzero ";                     //可用指令集，用文件中的1,0来代表该指令是否可用

	std::cout << std::endl << "Output order: ";
	vector<int> target;
	int num_tar = input[31];
	for (int i = 32; i <= 32 + num_tar - 1; ++i)
	{
		std::cout << input[i] << "   ";               //需输出的结果
		target.push_back(input[i]);
	}

	std::cout << "\n\n\n\n";            //图形界面正式开始



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
			cout << "游戏玩法tips；\n" << "请通过一系列的指令使输入传送带的数字变成输出传送带的数字，指令解释以及样例如下：\n";
			cout << "先输入一个数字代表指令的个数，随后再输入指令，其中指令数字之间请用空格隔开\n";
			cout << "inbox 将输入传送带上的货物变成输出的货物\n";
			cout << "outbox 将手上的货物放到传送带上\n";
			cout << "copyto x 将手上的货物复制到x号空地上\n";
			cout << "copyfrom x 将x号空地上的货物复制到手上\n";
			cout << "add x 将手上的货物加上x号空地上的货物\n";
			cout << "sub x 将手上的货物减掉x号空地上的货物\n";
			cout << "jump x 将当前执行的指令转换为第x号指令，其中指令编号从1开始\n";
			cout << "jumpifzero x 当手上的货物为0时，将当前执行的指令转换为第x号指令，其中指令编号从1开始\n\n";
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
			cout << "ゲームのプレイ方法のヒント：\n" << "一連のコマンドを使用して、入力コンベアベルトの数字を出力コンベアベルトの数字に変換します。 コマンドの説明と例は次のとおりです：\n";
			cout << "まず、コマンドの数を表す数字を入力し、次にスペースで区切ってコマンドを入力します。\n";
			cout << "inbox - 入力コンベアベルトのアイテムを手に取ります。\n";
			cout << "outbox - 手に持っているアイテムをコンベアベルトに置きます。\n";
			cout << "copyto x - 手に持っているアイテムをx番目のスロットにコピーします。\n";
			cout << "copyfrom x - x番目のスロットのアイテムを手にコピーします。\n";
			cout << "add x - 手に持っているアイテムにx番目のスロットのアイテムを加算します。\n";
			cout << "sub x - 手に持っているアイテムからx番目のスロットのアイテムを減算します。\n";
			cout << "jump x - 現在実行中のコマンドをコマンド番号xに変更します。 コマンド番号は1から始まります。\n";
			cout << "jumpifzero x - 手に持っているアイテムが0の場合、現在実行中のコマンドをコマンド番号xに変更します。 コマンド番号は1から始まります。\n\n";
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

	std::cout << "请输入你的指令" << std::endl;
		std::cin >> N;              //指令的数目

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
				orderlist[i][0] = judge;                    //将指令输入到二维数组judge中，并且第一个元素为指令，可能存在的二维项为其伴随参数
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
	//要求玩家输入需要的指令（该区块的位置可能调整以适应功能）

	//==============================================================================================//
	system("cls");
	int inhand = 114514;       //手上的方块
	vector<int> onempty(input[22], 114514);      //在空地里的方块
	int out[20];           //输出的方块
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
		}                                            //inbox的指令

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
		}                                               //outbox的指令

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
		}                                                //copyto的指令

		if (orderlist[x][0] == "copyfrom") {
			if (atoi(orderlist[x][1].c_str()) > input[22]) {
				std::cerr << "Error on instrction " << x + 1;
				gameover();
			}
			else
				inhand = copyfrom(x, onempty[atoi(orderlist[x][1].c_str())]);
			position = stoi(orderlist[x][1]);
		}                                                   //copyfrom的指令

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
		}                                                   //add的指令

		if (orderlist[x][0] == "sub") {
			if (stoi(orderlist[x][1]) > input[22] || inhand == 114514 || onempty[stoi(orderlist[x][1])] == 114514)
			{
				std::cerr << "Error on instruction " << x + 1;
				gameover();
			}

			else {
				inhand -= onempty[atoi(orderlist[x][1].c_str())];
				position = stoi(orderlist[x][1]);
			}                                                       //sub的指令
		}
		if (orderlist[x][0] == "jump") {
			if (x >= N || x == 0) {
				std::cerr << "Error on instruction " << x + 1;
				gameover();
			}
			flag2 = 1;
			UI(orderlist, position, inhand, in, out, onempty, input[22], N, x, hand_up ,input);
		}                                                      //jump的指令

		if (orderlist[x][0] == "jumpifzero") {
			if (x >= N || x == 0) {
				std::cerr << "Error on instruction " << x + 1;
				gameover();
			}
			if (inhand == 0) {
				flag2 = 1;
				UI(orderlist, position, inhand, in, out, onempty, input[22], N, x, hand_up , input);
			}
		}                                                         //jumpifzero的指令

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
	


	
	

	

	