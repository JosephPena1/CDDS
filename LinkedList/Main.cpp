#include "List.h"

int main()
{
	List<int> testList;
	testList.pushBack(5);
	testList.pushBack(4);
	testList.pushBack(3);
	testList.pushBack(2);
	testList.pushBack(1);
	testList.print();
	testList.remove(3);
	system("cls");
	testList.print();
	//testList.sort();
	//testList.print();
	return 0;
}