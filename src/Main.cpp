/*
 * Main.cpp
 *
 *  Created on: Sep 6, 2021
 *      Author: Kizsu
 */

#include "headers/LinkedList.h"
#include <iostream>

int main()
{
	LinkedList ll;

	ll.append("Test");
	ll.append("Test2");
	ll.append("Test3");
	ll.insert(3, "SEIRT");
	ll.pop_front();
	std::cout << ll.output() << std::endl;

	return 0;
}
