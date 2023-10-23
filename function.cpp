#include"orderlist.h"
#include<cmath>

int inbox(int input)
{
	return input;
}

int outbox(int output)
{
	return output;
}

int copyfrom(int input, int empty)
{
	return empty;
}

int copyto(int input, int empty)
{
	return input;
}

int add(int input, int empty)
{
	input = input + empty;
	return input;
}

int sub(int input, int empty)
{
	input -= empty;
}

int jump(int input)
{
	return input;
}


int jumpifzero(int input, int inhand)
{
	if (inhand == 0)
		return input;
}