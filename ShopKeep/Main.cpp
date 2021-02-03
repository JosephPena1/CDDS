#include <iostream>
#include "DynamicArray.h"

int main()
{
	DynamicArray<int> testArray = DynamicArray<int>();
	testArray.addItem(4);
	testArray.addItem(2);
	testArray.addItem(3);
	testArray.addItem(5);
	testArray.addItem(1);
	testArray.print();
	testArray.sortItems();
	std::cout << std::endl;
	testArray.print();

	return 0;
}