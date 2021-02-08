#pragma once
#include "Node.h"

template <typename T>

class Iterator
{

public:
	Iterator<T>();
	Iterator<T>(Node<T>* node);
	Iterator<T> operator++();
	Iterator<T> operator--();
	const bool operator==(const Iterator<T>& iter);
	const bool operator!=(const Iterator<T>& iter);
	T operator*();
	Iterator<T> getCurrent();

private:
	Node<T>* current;
};

template<typename T>
inline Iterator<T>::Iterator()
{
	current = nullptr;
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	current = node;
}

//sets the iterators current to be the next
template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	return current = current->next;
	//return Iterator<T>();
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	return current = current->previous;
	//return Iterator<T>();
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	if (iter.current->data == current->data)
		return true;

	return false;
}

//returns wether the current iterator != current node
template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	if (iter.current != current)
		return true;

	return false;
}

//overloaded to dereference an iterator.
template<typename T>
inline T Iterator<T>::operator*()
{
	//return *current;
	return T();
}

template<typename T>
inline Iterator<T> Iterator<T>::getCurrent()
{
	return current;
}