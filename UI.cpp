#include "design.h"
#include <iostream>
#include<string>
#include<vector>

using namespace std;

void UI(vector<vector<string>> orderlist, int position, int inhand, int* in, int* out, int* onempty, int num_of_empty, int num_of_order ,int x) {
	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "+---+";
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "      +---+          | ===== CODE =====" << "\n";                       //第一行

	cout << "IN   | ";
	if (in[0] == 114514) { cout << "X" << " |     "; }
	else { cout << in[0] << " |     "; }
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "| "; 
	if (inhand == 114514) { cout << "X |"; }
	else { cout << inhand << " |"; }
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "      " << "| ";
	if (out[0] == 114514) { cout << "X" << " |"; }
	else { cout << out[0] << " | "; }
	cout << "  OUT     " << "| ";
	if (x == 0) cout << "> ";
	else cout << "  ";
	cout << "1 inbox\n";                      //第二行

	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "+---+";
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "      +---+          | ";
	if (x == 1) cout << "> ";
	else cout << "  ";
	cout << "2 " << orderlist[1][0] << " ";
	if (stoi(orderlist[1][1]) != 114514) { cout << orderlist[1][1] << "\n"; }
	else cout << "\n";                                  //第三行

	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "@   @";
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "      +---+          | ";
	if (x == 2) cout << "> ";
	else cout << "  ";
	cout << "3 " << orderlist[2][0] << " ";
	if (stoi(orderlist[2][1]) != 114514) { cout << orderlist[2][1] << "\n"; }
	else cout << "\n";                                  //第四行

	cout << "     | ";
	if (in[1] == 114514) { cout << "X" << " |     "; }
	else { cout << in[1] << " |     "; }
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "-----";
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "      " << "| ";
	if (out[1] == 114514) { cout << "X" << " |"; }
	else { cout << out[1] << " | "; }
	cout << "         | ";
	if (num_of_order >= 4) {
		if (x == 3) { cout << "> "; }
		else cout << "  ";
		cout << "4 " << orderlist[3][0] << " ";
		if (stoi(orderlist[3][1]) != 114514) { cout << orderlist[4][1] << "\n"; }
		else cout << "\n";
	}
	else cout << "\n";//第五行

	cout << "     +---+     ";
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "|@ @|";
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "          | ";
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
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "       +---+          | ";
	if (num_of_order >= 6) {
		if (x ==5) { cout << "> "; }
		else cout << "  ";
		cout << "6 " << orderlist[5][0] << " ";
		if (stoi(orderlist[5][1]) != 114514) { cout << orderlist[5][1] << "\n"; }
		else cout << "\n";
	}
	else cout << "\n";                                  //第七行

	cout << "     | ";
	if (in[2] == 114514) { cout << "X" << " |     "; }
	else { cout << in[2] << " |     "; }
	for (int i = 0; i < position * 5; i++) { cout << " "; }
	cout << "/   \\";
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "      " << "| ";
	if (out[2] == 114514) { cout << "X" << " |"; }
	else { cout << out[2] << " | "; }
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
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "       +---+          | ";
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
	for (int i = 0; i < num_of_empty - position - 1; i++) { cout << " "; }
	cout << "       +---+          | ";
	if (num_of_order >= 9) {
		if (x == 8) { cout << "> "; }
		else cout << "  ";
		cout << "9 " << orderlist[8][0] << " ";
		if (stoi(orderlist[8][1]) != 114514) { cout << orderlist[8][1] << "\n"; }
		else cout << "\n";
	}
	else cout << "\n";                                  //第十行

	cout << "     | ";
	if (in[3] == 114514) { cout << "X" << " |"; }
	else { cout << in[3] << " |     "; }
	for (int i = 0; i < num_of_empty; i++)
		cout << "+---+";
	cout << "          | ";
	if (out[3] == 114514) { cout << "X" << " |          | \n"; }
	else { cout << out[3] << " |          | \n"; }            //第十一行

	cout << "     +---+     ";
	for (int i = 0; i < num_of_empty; i++) {
		cout << "| ";
		if (onempty[i] == 114514) { cout << "X";}
		else { cout << onempty[i]; }
		cout << " |";
	}
	cout << "       +---+     |\n";                                //第十二行

	cout << "               ";
	for (int i = 0; i < num_of_empty; i++) {
		cout << "+---+\n";
	}                                                              //第十三行

	cout << "               ";
	for (int i = 0; i < num_of_empty; i++) {
		cout << "  " << i << "  \n";
	}
}