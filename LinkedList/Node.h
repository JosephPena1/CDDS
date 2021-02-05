#pragma once

template <typename T>

class Node
{

public:
	Node<T>();
	Node<T>(T value, Node* n = nullptr, Node* p = nullptr);
	Node<T>* next;
	Node<T>* previous;
	T data;
};

template<typename T>
inline Node<T>::Node()
{

}

template<typename T>
inline Node<T>::Node(T value, Node* n, Node* p)
{
	data = value;
	next = n;
	previous = p;
}