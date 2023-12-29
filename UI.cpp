#include "design.h"
#include <iostream>
#include<string>
#include<vector>
#include<windows.h>

using namespace std;
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void UI(vector<vector<string>> orderlist, int position, int inhand, int* in, int out[20], vector<int> onempty, int num_of_empty, int num_of_order, int x , bool hand_up , int* input) {
	gotoxy(0, 0);
	cout << "Level : " << input[0] << "\n\n\n";
	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "+---+";
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      +---+          | ===== CODE =====" << "\n";                       //第一行

	cout << "IN   |";
	if (in[0] == 114514 || in[0] == 0) { cout << " X" << " |     "; }
	else { 
		if(in[0] >= 0 && in[0] < 10)
			cout << " " << in[0] << " |     ";
		else if (in[0] <= -10) {
			cout << in[0] << "|     ";
		}
		else { cout << " " << in[0] << "|     "; }
		}
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "|";
	if (inhand == 114514) { cout << " X |"; }
	else {
		if (inhand >= 10 || (inhand < 0 && inhand > -10)) {
			cout << " " << inhand << "|";
		}
		else if (inhand <= -10) {
			cout << inhand << "|";
		}
		else {cout << " " << inhand << " |"; }
	}
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      " << "|";
	if (out[0] == 114514) { cout << " " << "X" << " |"; }
	else { 
		if (out[0] >= 10 || (out[0] < 0 && out[0] > -10)) {
			cout << " " << out[0] << "|";
		}
		else if (out[0] <= -10) {
			cout << out[0] <<  "|";
		}
		else { cout << " " << out[0] << " |"; }
	}
	cout << "   OUT    " << "| ";
	if (x == 0) cout << "> ";
	else cout << "  ";
	cout << "1 inbox\n";                      //第二行

	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "+---+";
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      +---+          | ";
	if (x == 1) cout << "> ";
	else cout << "  ";
	cout << "2 " << orderlist[1][0] << " ";
	if (stoi(orderlist[1][1]) != 114514) { cout << orderlist[1][1] << "\n"; }
	else cout << "\n";                                  //第三行

	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "@   @";
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      +---+          | ";
	if (num_of_order >= 3) {
		if (x == 2) cout << "> ";
		else cout << "  ";
		cout << "3 " << orderlist[2][0] << " ";
		if (stoi(orderlist[2][1]) != 114514) { cout << orderlist[2][1] << "\n"; }
		else cout << "\n";                                  //第四行
	}
	else {cout << "\n";  }
	
	cout << "     |";
	if (in[1] == 114514) { cout << " X" << " |     "; }
	else {
		if (in[1] >= 0 && in[1] < 10)
			cout << " " << in[1] << " |     ";
		else if (in[1] <= -10) {
			cout << in[1] << "|     ";
		}
		else { cout << " " << in[1] << "|     "; }
	}
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "-----";
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      " << "|";
	if (out[1] == 114514) { cout << " X" << " | "; }
	else {
		if (out[1] >= 10 || (out[1] < 0 && out[1] > -10)) {
			cout << " " << out[1] << "| ";
		}
		else if (out[1] <= -10) {
			cout << out[1] << "| ";
		}
		else { cout << " " << out[1] << " | "; }
	}
	cout << "         | ";
	if (num_of_order >= 4) {
		if (x == 3) { cout << "> "; }
		else cout << "  ";
		cout << "4 " << orderlist[3][0] << " ";
		if (stoi(orderlist[3][1]) != 114514) { cout << orderlist[3][1] << "\n"; }
		else cout << "\n";
	}
	else cout << "\n";//第五行

	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "|@ @|";
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      +---+          | ";
	if (num_of_order >= 5) {
		if (x == 4) { cout << "> "; }
		else cout << "  ";
		cout << "5 " << orderlist[4][0] << " ";
		if (stoi(orderlist[4][1]) != 114514) { cout << orderlist[4][1] << "\n"; }
		else cout << "\n";
	}
	else cout << "\n";                                  //第六行

	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "  +  ";
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      +---+          | ";
	if (num_of_order >= 6) {
		if (x == 5) { cout << "> "; }
		else cout << "  ";
		cout << "6 " << orderlist[5][0] << " ";
		if (stoi(orderlist[5][1]) != 114514) { cout << orderlist[5][1] << "\n"; }
		else cout << "\n";
	}
	else cout << "\n";                                  //第七行

	cout << "     |";
	if (in[2] == 114514 || in[2] == 0) { cout << " X" << " |     "; }
	else {
		if (in[2] >= 0 && in[2] < 10)
			cout << " " << in[2] << " |     ";
		else if (in[2] <= -10) {
			cout << in[2] << "|     ";
		}
		else { cout << " " << in[2] << "|     "; }
	}
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	if (!hand_up) {
		cout << "/   \\";
	}
	else {
		cout << "\\   /";
		hand_up = 0;
	}
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      " << "|";
	if (out[2] == 114514) { cout << " X" << " | "; }
	else {
		if (out[2] >= 10 || (out[2] < 0 && out[2] > -10)) {
			cout << " " << out[2] << "| ";
		}
		else if (out[2] <= -10) {
			cout << out[2] << "| ";
		}
		else { cout << " " << out[2] << " | "; }
	}
	cout << "         | ";
	if (num_of_order >= 7) {
		if (x == 6) { cout << "> "; }
		else cout << "  ";
		cout << "7 " << orderlist[6][0] << " ";
		if (stoi(orderlist[6][1]) != 114514) { cout << orderlist[6][1] << "\n"; }
		else cout << "\n";
	}
	else cout << "\n";                                 //第八行

	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << " | | ";
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      +---+          | ";
	if (num_of_order >= 8) {
		if (x == 7) { cout << "> "; }
		else cout << "  ";
		cout << "8 " << orderlist[7][0] << " ";
		if (stoi(orderlist[7][1]) != 114514) { cout << orderlist[7][1] << "\n"; }
		else cout << "\n";
	}
	else cout << "\n";                                  //第九行

	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "     ";
	for (int i = 0; i < 5 * (num_of_empty - position - 1); i++) { cout << " "; }
	cout << "      +---+          | ";
	if (num_of_order >= 9) {
		if (x == 8) { cout << "> "; }
		else cout << "  ";
		cout << "9 " << orderlist[8][0] << " ";
		if (stoi(orderlist[8][1]) != 114514) { cout << orderlist[8][1] << "\n"; }
		else cout << "\n";
	}
	else cout << "\n";                                  //第十行

	cout << "     |";
	if (in[3] == 114514 || in[3] == 0) { cout << " X" << " |     "; }
	else {
		if (in[3] >= 0 && in[3] < 10)
			cout << " " << in[3] << " |     ";
		else if (in[3] <= -10) {
			cout << in[3] << "|     ";
		}
		else { cout << " " << in[3] << "|     "; }
	}
	for (int i = 0; i < num_of_empty; i++)
	{
		cout << "+---+";
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	cout << "      |";
	if (out[3] == 114514) { 
		cout << " X";
		cout <<  " |          | ";
	}
	else {
		if (out[3] >= 10 || (out[3] < 0 && out[3] > -10)) {
			cout << " " << out[3] << "|          | ";
		}
		else if (out[3] <= -10) {
			cout << out[3] << "|          | ";
		}
		else { cout << " " << out[3] << " |          | "; }
	}                                                                          
	if (num_of_order >= 10) {
		if (x == 9) { cout << "> "; }
		else cout << "  ";
		cout << "10 " << orderlist[9][0] << " ";
		if (stoi(orderlist[9][1]) != 114514) { cout << orderlist[9][1]; }
	}
	                                                   //第十一行
	cout << "\n     +---+     ";
	for (int i = 0; i < num_of_empty; i++) {
		cout << "|";
		if (onempty[i] == 114514 || onempty[i] == 0) { cout << " X" <<" |"; }
		else { 
			if (onempty[i] < 10 && onempty[i] >= 0)
				{ cout << " " << onempty[i] << " |"; }
			else if (onempty[i] <= -10) {
				cout << onempty[i] << "|";
			}
			else{
				cout << " " << onempty[i] << "|";
			}
		}
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}

	cout << "      +---+          | ";                                
	if (num_of_order >= 11) {
		if (x == 10) { cout << "> "; }
		else cout << "  ";
		cout << "11 " << orderlist[10][0] << " ";
		if (stoi(orderlist[10][1]) != 114514) { cout << orderlist[10][1] << ""; }
		else cout << "";
	}
	
	                                                                                    //第十二行
	cout << "\n     +---+     ";
	if (num_of_empty == 0) {
		cout << "     ";
	}
	for (int j = 0; j < num_of_empty; j++) {
		cout << "+---+";
	}                                                              
	cout << "      +---+          |\n";                             //第十三行


	cout << "     |";
	if (in[4] == 114514 || in[4] == 0) { cout << " X" << " |     "; }
	else {
		if (in[4] >= 0 && in[4] < 10)
			cout << " " << in[4] << " |     ";
		else if (in[4] <= -10) {
			cout << in[4] << "|     ";
		}
		else { cout << " " << in[4] << "|     "; }
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	for (int i = 0; i < num_of_empty; i++) {
		cout << "  " << i << "  ";
	}
	cout << "      |";
	if (out[4] == 114514) {
		cout << " X";
		cout << " |          | \n";
	}
	else {
		if (out[4] >= 10 || (out[4] < 0 && out[4] >= -10)) {
			cout << " " << out[4] << "|          |\n";
		}
		else if (out[4] <= -10) {
			cout << out[4] << "|          |\n";
		}
		else { cout << " " << out[4] << " |          |\n"; }
	}			                                                          //第十四行

	cout << "     +---+     ";
	for (int i = 0; i < 5 * num_of_empty; i++) {
		cout << " ";
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}              
	cout << "      +---+          |\n";                                         //第十五行

	cout << "     +---+     ";
	for (int i = 0; i < 5 * num_of_empty; i++) {
		cout << " ";
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	cout << "      +---+          |\n";                                     //第十六行

	cout << "     |";
	if (in[5] == 114514 || in[5] == 0) { cout << " X" << " |     "; }
	else {
		if (in[5] >= 0 && in[5] < 10)
			cout << " " << in[5] << " |     ";
		else if (in[5] <= -10) {
			cout << in[5] << "|     ";
		}
		else { cout << " " << in[5] << "|     "; }
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	for (int i = 0; i < num_of_empty; i++) {
		cout << "     ";
	}
	cout << "      |";
	if (out[5] == 114514) {
		cout << " X";
		cout << " |          |\n";                                           
	}
	else {
		if (out[5] >= 10 || (out[5] < 0 && out[5] >-10)) {
			cout << " " << out[5] << "|          |\n";
		}
		else if (out[5] <= -10) {
			cout << out[5] << "|          |\n";
		}
		else { cout << " " << out[5] << " |          |\n"; }
	}                                                                             //第十八行
	
	cout << "     +---+     ";
	for (int i = 0; i < 5 * num_of_empty; i++) {
		cout << " ";
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	cout << "      +---+          |\n";                                            //第十九行

	cout << "     +---+     ";
	for (int i = 0; i < 5 * num_of_empty; i++) {
		cout << " ";
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	cout << "      +---+          |\n";                                          //第二十行



	cout << "     |";
	if (in[6] == 114514 || in[6] == 0) { cout << " X" << " |     "; }
	else {
		if (in[6] >= 0 && in[6] < 10)
			cout << " " << in[6] << " |     ";
		else if (in[6] <= -10) {
			cout << in[6] << "|     ";
		}
		else { cout << " " << in[6] << "|     "; }
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	for (int i = 0; i < num_of_empty; i++) {
		cout << "     ";
	}
	cout << "      |";
	if (out[6] == 114514) {
		cout << " X";
		cout << " |          | \n";
	}
	else {
		if (out[6] >= 10 || (out[6] < 0 && out[6] > -10)) {
			cout << " " << out[6] << "|          |\n";
		}
		else if (out[6] <= -10) {
			cout << out[6] << "|          |\n";
		}
		else { cout << " " << out[6] << " |          |\n"; }                                  //第二十一行
	}

	cout << "     +---+     ";
	for (int i = 0; i < 5 * num_of_empty; i++) {
		cout << " ";
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	cout << "      +---+          |\n";                                                  //第二十二行



	cout << "     +---+     ";
	for (int i = 0; i < 5 * num_of_empty; i++) {
		cout << " ";
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	cout << "      +---+          |\n";

	cout << "     |";
	if (in[7] == 114514 || in[7] == 0) { cout << " X" << " |     "; }
	else {
		if (in[7] >= 0 && in[7] < 10)
			cout << " " << in[7] << " |     ";
		else if (in[7] <= -10) {
			cout << in[7] << "|     ";
		}
		else { cout << " " << in[7] << "|     "; }
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	for (int i = 0; i < num_of_empty; i++) {
		cout << "     ";
	}
	cout << "      |";
	if (out[7] == 114514) {
		cout << " X";
		cout << " |          | \n";
	}
	else {
		if (out[7] >= 10 || (out[7] < 0 && out[7] > -10)) {
			cout << " " << out[7] << "|          |\n";
		}
		else if (out[7] <= -10) {
			cout << out[7] << "|          |\n";
		}
		else { cout << " " << out[7] << " |          |\n"; }
	}

	cout << "     +---+     ";
	for (int i = 0; i < 5 * num_of_empty; i++) {
		cout << " ";
	}
	if (num_of_empty == 0) {
		cout << "     ";
	}
	cout << "      +---+          |\n";

	getchar();
}


//8 inbox copyto 2 add 2 copyto 3 add 3 sub 2 outbox jump 1
//11 inbox copyto 0 inbox copyto 1 copyfrom 0 sub 1 outbox copyfrom 1 sub 0 outbox jump 1
//9 inbox copyto 0 inbox sub 0 jumpifzero 7 jump 1 copyfrom 0 outbox jump 1