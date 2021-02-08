#include "List.h"

int main()
{
	List<int> testList;
	testList.pushFront(3);
	testList.pushBack(2);
	testList.pushFront(1);
	testList.print();
	return 0;
}