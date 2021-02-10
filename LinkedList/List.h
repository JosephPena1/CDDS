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

}

//destroys ...?
template<typename T>
inline void List<T>::destroy()
{

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
	Iterator<T> iter = Iterator<T>(m_first.next);

	for (iter.getCurrent(); iter != m_last.next; ++iter)
		if (*iter == object)
			return true;

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
//WIP: cannot insert at first/last node, 
template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	if (index > m_nodeCount)
		return false;

	//loop through list until it reaches the index
	int count = 0;
	Iterator<T> iter = Iterator<T>(m_first.next);
	Node<T>* iterNode = new Node<T>(NULL, m_first.next);

	for (iter.getCurrent(); iter != m_last.next; ++iter)
	{
		if (count == index)
		{
			//put where 4 is in list
			//set 4's previous to be new node, set 5's next to be new node
			Node<T>* tempNode = new Node<T>(value, iterNode, iterNode->previous);
			iterNode->previous->next = tempNode;
			iterNode->previous = tempNode;
			m_nodeCount++;
			return true;
		}
		else
		{
			iterNode->previous = iterNode->previous;
			iterNode = iterNode->next;
			count++;
		}
	}

	return false;
}

//Removes a given value from the list
//WIP: doesn't like removing the first node
template<typename T>
inline bool List<T>::remove(const T& value)
{
	Iterator<T> iter = Iterator<T>(m_first.next);
	Node<T>* tempNode = new Node<T>(NULL, m_first.next);

	for (iter.getCurrent(); iter != m_last.next; ++iter)
	{
		if (*iter == value)
		{
			tempNode->previous = tempNode->previous;
			tempNode = tempNode->next;

			//checks if current next is null
			if (tempNode->next == nullptr)
				tempNode->previous->next = nullptr;

			//checks if current previous is null
			else if (tempNode->previous == nullptr)
				tempNode->next->previous = nullptr;

			else
			{
				tempNode->previous->next = tempNode->next;
				tempNode->next->previous = tempNode->previous;
			}
			
			//tempNode->next = tempNode->previous;
			//tempNode->previous->next = tempNode->next;

			//delete data and node
			tempNode->data = NULL;
			tempNode->next = nullptr;
			tempNode->previous = nullptr;
			delete tempNode;
			m_nodeCount--;
			return true;
		}

		else
		{
			//sets tempNode's previous and next if value isn't found
			tempNode->previous = tempNode->previous;
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
	//didn't use begin()/end() because it didn't want to work.
	Iterator<T> iter = Iterator<T>(m_first.next);
	for (iter.getCurrent(); iter != m_last.next; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	std::cout << "Total Nodes: " << m_nodeCount << std::endl;
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

	return false;
}

//returns if the value wasn't found?
template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{

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