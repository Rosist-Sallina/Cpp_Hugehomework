#include"orderlist.h"
#include<cmath>

int* inbox(int* input , int N)
{
	for (int i = 0; i < N; ++i)
	{
		input[i] = input[i + 1];
		return input;
	}
}

int* outbox(int* output , int N)
{
	for (int i = 0; i < N; ++i)
	{
		output[i + 1] = output[i];
		return output;
	}
	
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
	return input;
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