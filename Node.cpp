/*
 * Node.cpp
 *
 *  Created on: 8 Sep 2016
 *      Author: Gian Miguel
 */

#include "Node.h"
using namespace std;

Node::Node(int grid[])
{
	for(int i = 0; i < 81; i++)
	{
		Node::grid[i % 9][(i / 10) % 9] = grid[i];
	}
}

void Node::printGrid()
{
	for(int i = 0; i < 81; i++)
	{
		cout << Node::grid[i % 9][(i / 10) % 9];
		if(i % 9 == 8)
		{
			cout << endl;
		}
	}
}
