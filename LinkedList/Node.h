#pragma once

template <typename T>

class Node
{

public:
	Node<T>();
	Node<T>(T value);
	Node<T>* next;
	Node<T>* previous;
	T data;
};

template<typename T>
inline Node<T>::Node()
{
	data = NULL;
}

template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
}