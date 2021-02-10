#include "List.h"

int main()
{
	List<int> testList;
	testList.pushFront(4);
	testList.pushFront(3);
	testList.pushFront(2);
	testList.pushFront(1);
	testList.pushBack(5);

	testList.print();
	system("pause");
	system("cls");

	int testInt = 9;
	testList.insert(testInt, 3);
	if (testList.contains(testInt))
		std::cout << "There's a " << testInt << std::endl;
	testList.print();
	system("pause");
	system("cls");

	testList.remove(4);
	testList.print();
	system("pause");
	return 0;
}