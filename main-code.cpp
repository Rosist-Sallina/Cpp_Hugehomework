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
	cout << "| $$ $$\\$$\$$| $$    $$| $$| $$      | $$  | $$| $$ | $$ | $$| $$    $$\n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "| $$$$  \\$$$$| $$$$$$$$| $$| $$_____ | $$__/ $$| $$ | $$ | $$| $$$$$$$$\n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "| $$$    \\$$$ \\$$     \\| $$ \\$$     \\ \\$$    $$| $$ | $$ | $$ \$$     \\\n";
	this_thread::sleep_for(chrono::milliseconds(700));
	cout << "   \\$$      \\$$  \\$$$$$$$ \\$$  \\$$$$$$$  \\$$$$$$  \\$$  \\$$  \\$$  \\$$$$$$$\n\n\n";
	this_thread::sleep_for(chrono::milliseconds(700));

	std::cout << "Welcome to the game.\n";
	std::cout << "Please choose your level.\n";
	
	int middle[10];
	int *input = Choose_level(middle);
	basicwindow(input);

	return 0;



}

