/*
 * LinkedList.cpp
 *
 *  Created on: Sep 6, 2021
 *      Author: Kizsu
 */

#include "headers/LinkedList.h"

LinkedList::LinkedList()
{
	this->_tail = NULL;
	this->_head = NULL;
	this->_size = 0;
}

LinkedList::~LinkedList()
{
	Node* temp = this->_head;
	while (this->_head != NULL)
	{
		temp = this->pop_front();
		delete temp;
	}
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

/*
 * Insert a new node at the specified *index* in the list with value *key*
 *
 * int index: Index where to insert the new node
 * string key: The value to use in the new node
 */
void LinkedList::insert(int index, std::string key)
{
	// Don't waste time and memory on a non-existent index
	if (index > this->_size)
	{
		throw std::out_of_range ("Index out of range on insert call.");
	}

	// Declare and initialize *temp* here, since it will be used regardless
	Node* temp = new Node(key);
	// Don't try to loop if trying to change the head
	if (index == 0) {
		if (this->_head == NULL)
		{
			this->_head = temp;
			this->_tail = temp;
			return;
		}
		else
		{
			temp->next = this->_head;
			this->_head = temp;
			return;
		}
	}

	Node* current = this->_head;
	Node* previous = NULL;
	int count = 0;

	while (current != NULL)
	{
		count++;
		if (count-1 == index)
		{
			// Change the previous node's link to the new node
			previous->next = temp;
			// Change the new node's link to the node at the index
			temp->next = current;
			return;
		}
		previous = current;
		current = current->next;
	}

	// Change the tail if nothing was changed in the loop
	previous->next = temp;
	this->_tail = temp;
}

/*
 * Append *key* to the current list
 *
 * string key: Key to use in the new node
 */
void LinkedList::append(std::string key)
{
	Node *temp = new Node(key);

	// Make sure the list has items, if not make the *key* the first
	if (this->_head == NULL)
	{
		this->_head = temp;
		this->_tail = temp;
	}
	// Otherwise give the old tail a link to the new tail, and set the tail to the new tail
	else
	{
		this->_tail->next = temp;
		this->_tail = temp;
	}
	this->_size++;
}

LinkedList::Node* LinkedList::pop_front()
{
	if (this->_head == NULL)
	{
		return NULL;
	}
	Node* head = this->_head;
	this->_head = head->next;
	return head;
}

LinkedList::Node* LinkedList::pop_back()
{
	if (this->_head == NULL)
	{
		return NULL;
	}

	Node* current = this->_head;
	int count = 0;

	while (current != NULL)
	{
		count++;
		if (count == this->_size)
		{
			this->_tail = current;
			break;
		}
		current = current->next;
	}
	current = current->next;
	current->next = NULL;
	return current;
}

/*
 * Remove the node at the specified *index*
 *
 * int index: The index to find the node
 */
void LinkedList::remove(int index)
{
	// Don't waste time on a non-existent index
	if (index >= this->_size)
	{
		throw std::out_of_range ("Index out of range on remove call");
	}

	Node* current = this->_head;
	Node* last = this->_head;

	int count = 0;

	// Loop until the current is valid
	while (current != NULL)
	{
		count++;
		if (count-1 == index)
		{
			// Set the node before the indexed node's link to the node after the indexed node
			last->next = current->next;
			// Delete the current pointer to prevent memory leaks
			delete current;
			break;
		}
		last = current;
		current = last->next;
	}
}

/*
 * Generates a string with the keys of the list in order
 *
 * Return: string | Ordered keys of list
 */
std::string LinkedList::output()
{
	std::string o  = "";

	// Don't waste time and memory attempting to iterate over a non-existent list
	if (_head == NULL)
	{
		o = "*NULL*";
		return o;
	}

	// Set the *current* node to the lists head and loop until the node is non-existent
	Node *current = this->_head;
	while (current != NULL)
	{
		o.append(current->key + '\n');
		current = current->next;
	}

	return o;
}



