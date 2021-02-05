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
	Iterator<T> begin();
	Iterator<T> end();

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

template<typename T>
inline void List<T>::destroy()
{

}

template<typename T>
inline Iterator<T> List<T>::begin()
{
	return Iterator<T>();
}

//return the last node's pointer
template<typename T>
inline Iterator<T> List<T>::end()
{
	return Iterator<T>();
}

template<typename T>
inline bool List<T>::contains(const T& object) const
{
	return false;
}

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
}

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
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	return false;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	return false;
}

//prints the contents of a linked list. (*_*)//WIP\\(*_*)
template<typename T>
inline void List<T>::print() const
{
	/*Iterator<T> iter = Iterator<T>(m_first);
	for (iter.current; iter.operator!=(m_last); iter.operator++)
		std::cout << *iter << std::endl;*/

}

template<typename T>
inline void List<T>::initialize()
{

}

template<typename T>
inline bool List<T>::isEmpty() const
{
	if (m_first.next == nullptr)
		return true;
	return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{

	return false;
}

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

template<typename T>
inline void List<T>::sort()
{
	/*Iterator<T> iter;
	for (iter.current = m_first; iter != m_last; iter++)
		for (int j = length - 1; j > i; j--)
			if()
			{

			}*/
}