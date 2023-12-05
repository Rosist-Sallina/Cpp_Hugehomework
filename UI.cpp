#include "design.h"
#include <iostream>

void UI(std::string** orderlist,int* in, int* out, int* number_empty, int inhand, int x , int number_in) {
	for (int i = 0; i < 23; i++) {
		if (i == 0) {
			std::cout << "    " << "+---+" << "      ";
			if (((x - x % 3) / 3) % 2 == 0) {
				for (int a = 0; a < 6 * (x % 3); a++) {
					std::cout << " ";
				}
				std::cout << "+---+";
				for (int a = 0; a < 6 * (2 - (x % 3)); a++) {
					std::cout << " ";
				}
			}
			else {
				for (int a = 0; a < 6 * (3 - (x % 3)); a++) {
					std::cout << " ";
				}
				std::cout << "+----+";
				for (int a = 0; a < 6 * (x % 3) - 1; a++) {
					std::cout << " ";
				}
			}
			std::cout << "          | ===== CODE =====" << std::endl;
		}
		if (i == 1) {
			std::cout << "IN   | " << in[0] << " |       ";
			if (((x - x % 3) / 3) % 2 == 0) {
				for (int a = 0; a < 6 * (x % 3); a++) {
					std::cout << " ";
				}
				std::cout << "| " << inhand << " |";
				for (int a = 0; a < 6 * (2 - (x % 3)); a++) {
					std::cout << " ";
				}
			}
			else {
				for (int a = 0; a < 6 * (3 - (x % 3)); a++) {
					std::cout << " ";
				}
				std::cout << "| " << inhand << " |";
				for (int a = 0; a < 6 * (x % 3) - 1; a++) {
					std::cout << " ";
				}
			}
			std::cout << "|  ";
			if (x == 1)
				std::cout << "> ";
			else
				std::cout << "  ";
			std::cout << "1 " << orderlist[0][0];
		}
		if (x == 2) {
			std::cout << "    " << "+---+" << "      ";
			if (((x - x % 3) / 3) % 2 == 0) {
				for (int a = 0; a < 6 * (x % 3); a++) {
					std::cout << " ";
				}
				std::cout << "+---+";
				for (int a = 0; a < 6 * (2 - (x % 3)); a++) {
					std::cout << " ";
				}
			}
			else {
				for (int a = 0; a < 6 * (3 - (x % 3)); a++) {
					std::cout << " ";
				}
				std::cout << "+----+";
				for (int a = 0; a < 6 * (x % 3) - 1; a++) {
					std::cout << " ";
				}
			}
			std::cout << "          | ";
			if(x == 2){
				std::cout << "> ";
			}
			else {
				std::cout << "  ";
			}
			std::cout << "2 " << orderlist[1][0] <<" ";
			if (&orderlist[1][1] != NULL) {
				std::cout << orderlist[1][1] << "   ";
			}
		}
		if (i == 3) {
			std::cout << "    " << "+---+" << "      ";
			if (((x - x % 3) / 3) % 2 == 0) {
				for (int a = 0; a < 6 * (x % 3); a++) {
					std::cout << " ";
				}
				std::cout << "@   @";
				for (int a = 0; a < 6 * (2 - (x % 3)); a++) {
					std::cout << " ";
				}
			}
			else {
				for (int a = 0; a < 6 * (3 - (x % 3)); a++) {
					std::cout << " ";
				}
				std::cout << "@   @";
				for (int a = 0; a < 6 * (x % 3) - 1; a++) {
					std::cout << " ";
				}
			}
			std::cout << "          | ";
			if (x == 2) {
				std::cout << "> ";
			}
			else {
				std::cout << "  ";
			}
			std::cout << "3 " << orderlist[2][0] << " ";
			if (&orderlist[2][1] != NULL) {
				std::cout << orderlist[2][1] << "   ";
			}
		}
		if (i == 4) {
			std::cout << "     | " << in[0] << " |       ";
			if (((x - x % 3) / 3) % 2 == 0) {
				for (int a = 0; a < 6 * (x % 3); a++) {
					std::cout << " ";
				}
				std::cout << "| " << inhand << " |";
				for (int a = 0; a < 6 * (2 - (x % 3)); a++) {
					std::cout << " ";
				}
			}
			else {
				for (int a = 0; a < 6 * (3 - (x % 3)); a++) {
					std::cout << " ";
				}
				std::cout << "| " << inhand << " |";
				for (int a = 0; a < 6 * (x % 3) - 1; a++) {
					std::cout << " ";
				}
			}
			std::cout << "|  ";
			if (x == 4)
				std::cout << "> ";
			else
				std::cout << "  ";
			std::cout << "1 " << orderlist[0][0];                     //没写完，写到第5行，而且没改，记得改
		}
	}
}