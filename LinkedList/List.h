#pragma once
#include "Iterator.h"

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
	//if list doesn't exist, set first to new Node
	//else add new Node to the list
	if (m_first || m_last = NULL)
	{
		m_first = new Node<T>;
		m_first->setData(info);
		m_last = m_first;
	}
	else
	{
		Node<T>* temp = new Node<T>;
		temp->setData(info);
		temp->setNextNull();
		m_last->setNext(temp);
		m_last = m_last->getNext();
	}
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//if list doesn't exist, set first to the new Node
	//else add new Node to the list
	if (m_first || m_last = NULL)
	{
		m_first = new Node<T>;
		m_first->setData(info);
		m_last = m_first;
	}
	else
	{
		Node<T>* temp = new Node<T>;
		temp->setData(info);
		temp->setNextNull();
		m_last->setNext(temp);
		m_last = m_last->getNext();
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

//prints the contents of a linked list
template<typename T>
inline void List<T>::print() const
{
	return void();
}

template<typename T>
inline void List<T>::initialize()
{
}

template<typename T>
inline bool List<T>::isEmpty() const
{

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
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::sort()
{
	for (int i = 0; i < length; i++)
		for (int j = length - 1; j > i; j--)
			if()
			{

			}
}