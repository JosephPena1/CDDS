#pragma once
#include "Iterator.h"
#include <iostream>

template <typename T>

class List
{

public:
	List<T>();
	List<T>(List<T>&);
	~List<T>();
	void destroy();
	Iterator<T> begin() const;
	Iterator<T> end() const;

	bool contains(const T& object) const;
	const void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);

	void print()const;
	void initialize();
	bool isEmpty() const;
	bool getData(Iterator<T>& iter, int index);

	int getLength() const { return m_nodeCount; }
	const List<T>& operator=(const List<T>& otherList);
	void sort();

private:
	Node<T> m_first;
	Node<T> m_last;
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
	m_first = NULL;
	m_last = NULL;
	int m_nodeCount = 0;
}

template<typename T>
inline List<T>::List(List<T>&)
{

}

template<typename T>
inline List<T>::~List()
{
	/*Node<T>* temp = m_first;
	while (m_first)
	{
		delete temp->data;
		m_first = temp->next;
		delete temp;
		temp = m_first;
	}*/
}

//destroys ...?
template<typename T>
inline void List<T>::destroy()
{
	/*Node<T>* temp = m_first;
	while (m_first)
	{
		delete temp->data;
		m_first = temp->next;
		delete temp;
		temp = m_first;
	}*/
}

//return the first node
template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}

//return the last node's pointer
template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last.next);
}

//checks if the list contains the given value
template<typename T>
inline bool List<T>::contains(const T& object) const
{

	return false;
}

//pushes the given data to the front of the list
template<typename T>
inline const void List<T>::pushFront(const T& value)
{
	//if list is empty, sets first and last to newNode
	//else add new Node to the list
	if (isEmpty())
	{
		Node<T>* newNode = new Node<T>(value);
		m_first.next = newNode;
		m_last.previous = newNode;
	}
	else
	{
		//makes a new node that is the first's next
		Node<T>* newFirst = m_first.next;
		//makes a new node that has a value
		Node<T>* newNode = new Node<T>(value, newFirst);
		newFirst->previous = newNode;
		m_first.next = newNode;
	}

	m_nodeCount++;
	//std::cout << "node count: " << m_nodeCount << std::endl;
}

//pushes the given data to the back of the list
template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//if list is empty, sets first and last to newNode
	//else add new Node to the list
	if (isEmpty())
	{
		Node<T>* newNode = new Node<T>(value);
		m_first.next = newNode;
		m_last.previous = newNode;
	}
	else
	{
		//makes a new node that is the first's next
		Node<T>* newLast = m_last.previous;
		//makes a new node that has a value
		Node<T>* newNode = new Node<T>(value, nullptr, newLast);
		newLast->next = newNode;
		m_last.previous = newNode;
	}

	m_nodeCount++;
	//std::cout << "node count: " << m_nodeCount << std::endl;
}

//inserts the given value at the index in the list
template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	//loop through list until it reaches the index

	return false;
}

//Removes a given value from the list
template<typename T>
inline bool List<T>::remove(const T& value)
{
	//creates an iterator to go through the list
	Iterator<T> iter = Iterator<T>(m_first.next);

	//creates a new node to check if data matches
	Node<T>* tempNode = new Node<T>(NULL, m_first.next);

	for (iter.getCurrent(); iter != m_last.next; ++iter)
	{
		if (tempNode->next->data == value)
		{
			//Change previous and next pointers to be each other
			tempNode->next->next->previous = tempNode->previous;
			tempNode->next = tempNode->next->next;

			//delete data and node
			tempNode->next->data = NULL;
			tempNode->next = nullptr;
			tempNode->previous = nullptr;
			delete tempNode;
			return true;
		}
		else
		{
			tempNode = tempNode->next;
		}
	}
	delete tempNode;

	return false;

	
}

//Prints the contents of a linked list.
template<typename T>
inline void List<T>::print() const
{
	//not using begin/end because it doesn't wanna work.
	Iterator<T> iter = Iterator<T>(m_first.next);
	for (iter.getCurrent(); iter != m_last.next; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	std::cout << "node count: " << m_nodeCount << std::endl;
}

//Initializes ...?
template<typename T>
inline void List<T>::initialize()
{

}

//checks if the list is empty
template<typename T>
inline bool List<T>::isEmpty() const
{
	if (m_nodeCount == 0)
		return true;
	/*if (m_first.next == nullptr)
		return true;*/
	return false;
}

//returns if the value wasn't found?
template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	//if (index != nodeCount/NULL) loop, index++
	//for (iter.getCurrent(); index <= m_nodeCount; ++iter)
	//{
	//	//if the ___ matches index, return data somehow;
	//	if ()
	//	{
	//		return iter.current->data;
	//	}
	//	index++;
	//		
	//}

	return false;
}

//
template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	if (this == &otherList)
		return *this;

	while (otherList.m_first.next != nullptr)
	{
		Node<T>* current = otherList.m_first.next;
		pushBack(current->data);
		otherList.m_first.next = current->next;
	}

	return *this;
}

//sorts the list from least to greater
template<typename T>
inline void List<T>::sort()
{
	//Iterator<T> iter;

	//for (iter.current = m_first; iter != end(); iter++)
	//{
	//	for (int j = end(); j > iter; j--)
	//	{
	//		if (iter.current < iter.current->next)
	//		{
	//			//swap places
	//		}
	//	}
	//}
}