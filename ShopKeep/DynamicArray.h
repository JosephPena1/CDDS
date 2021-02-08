#pragma once

template <typename T>

class DynamicArray
{
public:
	DynamicArray<T>();

	~DynamicArray<T>();

	void print();

	void addItem(T item);

	bool removeItem(T item);

	void sortItems();

	bool getItem(int index, T* item);

	int getLength() { return m_length; }

private:
	T* m_items;
	int m_length = 0;
};

template <typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_items = nullptr;
	m_length = 0;
}

template <typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] m_items;
}

template <typename T>
inline void DynamicArray<T>::print()
{
	for (int i = 0; i < getLength(); i++)
		std::cout << m_items[i];
}

template <typename T>
inline void DynamicArray<T>::addItem(T item)
{
	//Create a new temporary array that one size larger than the original
	T* tempArray = new T[getLength() + 1];

	//Copy values from old array into new array
	for (int i = 0; i < getLength(); i++)
	{
		tempArray[i] = m_items[i];
	}

	//Sets the item at the new index to be the item passed in
	tempArray[getLength()] = item;

	//Set the old array to the tmeporary array
	m_items = tempArray;
	m_length++;
}

template <typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	bool itemRemoved = false;

	//Create a new temporary array that is one less than our original array
	T* tempArray = new T[getLength() - 1];

	//Copy all items except the given item into the new array
	int j = 0;
	for (int i = 0; i < getLength(); i++)
	{
		if (tempArray[i] != item)
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else
			itemRemoved = true;
	}

	m_items = tempArray;
	m_length--;
	return itemRemoved;
}

template <typename T>
inline void DynamicArray<T>::sortItems()
{
	for (int i = 0; i < getLength(); i++)
	{
		for (int j = getLength() - 1; j > i; j--)
		{
			if (m_items[j] < m_items[j - 1])
			{
				T temp = m_items[j];
				m_items[j] = m_items[j - 1];
				m_items[j - 1] = temp;
			}
		}
	}	
}

template <typename T>
inline bool DynamicArray<T>::getItem(int index, T* item)
{
	if (index < 0 || index >= getLength())
		return false;

	item = &m_items[index];

	return true;
}