/*
 * Node.h
 *
 *  Created on: 8 Sep 2016
 *      Author: Gian Miguel
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>

class Node
{
private:
	int grid[9][9];

public:
	Node(int grid[]);
	void printGrid();
};

#endif /* NODE_H_ */
