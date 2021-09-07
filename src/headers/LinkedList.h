/*
 * LinkedList.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Kizsu
 */

#include <string>
#include <iostream>

#ifndef DATE_H
#define DATE_H

class LinkedList
{
private:
	struct Node;

	Node* _tail;
	Node* _head;
	int _size;

public:
	LinkedList();
	~LinkedList();

	void insert(int index, std::string key);
	void append(std::string key);

	Node* pop_front();
	Node* pop_back();
	void remove(int index);

	std::string output();
};

#endif
