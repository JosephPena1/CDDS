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
	system("pause");
	system("cls");

	testList.insert(6, 3);
	testList.print();

	//testList.sort();
	//testList.print();
	return 0;
}