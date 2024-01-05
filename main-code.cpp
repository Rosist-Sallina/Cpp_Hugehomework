//4 inbox outbox inbox outbox
//11 inbox copyto 0 inbox copyto 1 copyfrom 0 sub 1 outbox copyfrom 1 sub 0 outbox jump 1
//9 inbox copyto 0 inbox sub 0 jumpifzero 7 jump 1 copyfrom 0 outbox jump 1
//13 inbox copyto 0 add 0 copyto 0 add 0 copyto 1 add 1 add 0 copyto 2 sub 2 sub 2 outbox jump 1

#include <iostream>
#include"design.h"
#include <fstream>
#include <chrono>
#include<thread>
using namespace std;

int main()
{
	cout << " __       __            __                                             \n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "|  \\  _  |  \\          |  \\                                            \n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "| $$ / \\ | $$  ______  | $$  _______   ______   ______ ____    ______  \n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "| $$/  $\\| $$ /      \\ | $$ /       \\ /      \\ |      \\    \\  /      \\ \n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "| $$  $$$\\ $$|  $$$$$$\\| $$|  $$$$$$$|  $$$$$$\\| $$$$$$\\$$$$\\|  $$$$$$\\\n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "| $$ $$\\$$\\$$| $$    $$| $$| $$      | $$  | $$| $$ | $$ | $$| $$    $$\n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "| $$$$  \\$$$$| $$$$$$$$| $$| $$_____ | $$__/ $$| $$ | $$ | $$| $$$$$$$$\n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "| $$$    \\$$$ \\$$     \\| $$ \\$$     \\ \\$$    $$| $$ | $$ | $$ \\$$     \\\n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << " \\$$      \\$$  \\$$$$$$$ \\$$  \\$$$$$$$  \\$$$$$$  \\$$  \\$$  \\$$  \\$$$$$$$\n\n\n";
	this_thread::sleep_for(chrono::milliseconds(1000));


	std::cout << "Welcome to the game.\n";
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "You will be a robot working in a Black Factory just as Tsinghua Univ.\n";
	this_thread::sleep_for(chrono::milliseconds(2500));
	cout << "Here you need to complete a series of tasks to get the final GPA(Great Price Award).\n";
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "So , Fight!\n\n";
	this_thread::sleep_for(chrono::milliseconds(3000));
	std::cout << "Please choose your level.\n";
	
	int middle[10];
	int *input = Choose_level(middle);
	basicwindow(input);

	return 0;



}

