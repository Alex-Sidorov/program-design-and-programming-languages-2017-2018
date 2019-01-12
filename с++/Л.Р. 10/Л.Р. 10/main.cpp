#include "Stack.h"

int main()
{
	Stack<int> obj;
	Stack<float> obj2;
	Stack<char> obj3;


	obj.push_top(1);
	obj.push_top(2);
	obj.push_top(3);

	obj.delete_index((obj.top())+2);

	obj.show();
	MyIterator<int> it = obj.find(2);

	obj.delete_index(it);

	std::cout << std::endl;
	obj.show();
///////////////////////////////
	std::cout << std::endl;
	std::cout << std::endl;

	obj2.push_top(1.1);
	obj2.push_top(2.2);
	obj2.push_top(3.3);

	obj2.show();
	MyIterator<float> it2 = obj2.find(2.2);

	obj2.delete_index(it2);

	std::cout << std::endl;
	obj2.show();
///////////////////////////////////
	std::cout << std::endl;
	std::cout << std::endl;

	obj3.push_top('1');
	obj3.push_top('2');
	obj3.push_top('3');

	obj3.show();
	MyIterator<char> it3 = obj3.find('2');

	obj3.delete_index(it3);

	std::cout << std::endl;
	obj3.show();

	system("pause");
	return 0;
}