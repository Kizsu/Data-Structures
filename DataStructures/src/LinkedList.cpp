/*
 * LinkedList.cpp
 *
 *  Created on: Sep 6, 2021
 *      Author: Kizsu
 */

#include "LinkedList.h"

LinkedList::LinkedList()
{
	this->_tail = NULL;
	this->_head = NULL;
	this->_size = 0;
}

struct LinkedList::Node
{
	Node *next = NULL;
	std::string key;

	bool hasNext()
	{
		return this->next != NULL;
	}

	Node(std::string key)
	{
		this->key = key;
	}
};

void LinkedList::append(std::string key)
{
	Node *temp = new Node(key);

	if (this->_head == NULL)
	{
		this->_head = temp;
		this->_tail = temp;
	}
	else
	{
		this->_tail->next = temp;
		this->_tail = temp;
	}
	this->_size++;
}



void LinkedList::remove(int index)
{
	if (index >= this->_size)
	{
		throw std::out_of_range ("Index out of range");
	}

	Node* current = this->_head;
	Node* last = this->_head;

	int count = 0;

	while (current != NULL)
	{
		count++;
		if (count-1 == index)
		{
			last->next = current->next;
			delete current;
			break;
		}
		last = current;
		current = last->next;
	}
}

std::string LinkedList::output()
{
	std::string o  = "";

	if (_head == NULL)
	{
		o = "*NULL*";
		return o;
	}

	Node *current = this->_head;
	while (current != NULL)
	{
		o.append(current->key + '\n');
		current = current->next;
	}

	return o;
}



