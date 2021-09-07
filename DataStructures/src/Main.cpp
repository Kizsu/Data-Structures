/*
 * Main.cpp
 *
 *  Created on: Sep 6, 2021
 *      Author: Kizsu
 */

#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList ll;

	ll.append("Test");
	ll.append("Test2");
	std::cout << ll.output() << std::endl;

	ll.remove(1);
	std::cout << ll.output() << std::endl;

	return 0;
}
