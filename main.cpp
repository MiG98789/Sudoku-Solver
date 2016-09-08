/*
 * main.cpp
 *
 *  Created on: 7 Sep 2016
 *      Author: Gian Miguel
 */

#include "Node.h"
using namespace std;

int main(int argc, char** argv)
{
	int data[81];
	for(int i = 0; i < 81; i++)
	{
		data[i] = 0;
	}

	Node n(data);
	n.printGrid();

	return 0;
}
