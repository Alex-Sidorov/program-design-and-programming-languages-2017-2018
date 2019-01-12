#pragma once

#include <iostream>
#include "MyIterator.h"


template<typename Type>
class Stack 
{
public:
	MyIterator<Type> top()const;
	MyIterator<Type> back()const;

	void pop_top();

	void push_top(Type value);

	void show()const;

	void delete_index(MyIterator<Type> index);

	MyIterator<Type>find(Type value)const;

	int size()const;

	Stack ();
	Stack(int size);
	~Stack ();

private:
	Type *array;
	int _size;

	void error_alloc()const;
	void error_index()const;
};

template<typename Type>
void Stack<Type>::delete_index(MyIterator<Type> index)
{
	if (_size == 0 || index> MyIterator<Type>(&array[_size - 1])|| index<MyIterator<Type>(&array[0]))
		return;

	int step_one = 0;
	int step_two = 0;

	try
	{
		Type *ptr = new Type[_size - 1];

		while (step_two < _size)
		{
			if (MyIterator<Type>(&array[step_two]) == index)
				step_two++;
			else
			{
				ptr[step_one] = array[step_two];
				step_one++;
				step_two++;
			}

		}
		delete[] array;
		array = ptr;
		_size--;
	}
	catch (std::bad_alloc)
	{
		error_alloc();
	}
}

template<typename Type>
int Stack<Type>::size()const
{
	return _size;
}

template<typename Type>
void Stack<Type>::show()const
{
	for (int i = 0; i < _size; i++)
	{
		std::cout << array[i]<<" ";
	}
}

template<typename Type>
MyIterator<Type> Stack<Type>::find(Type value)const
{
	MyIterator<Type> temp;
	for (int i = 0; i < _size;i++)
	{
		if (value == array[i])
		{
			temp.set_ptr(&array[i]);
			break;
		}
	}
	return temp;
}

template<typename Type>
MyIterator<Type> Stack<Type>::top()const
{
	if (_size == 0)
	{
		error_index();
		return MyIterator<Type>();
	}

	return MyIterator<Type>(&array[0]);
}

template<typename Type>
MyIterator<Type> Stack<Type>::back()const
{
	if (_size == 0)
	{
		error_index();
		return MyIterator<Type>();
	}

	return MyIterator<Type>(&array[_size-1]);
}

template<typename Type>
void Stack<Type>::error_index()const
{
	std::cout << "Неверный индекс.";
}

template<typename Type>
void Stack<Type>::error_alloc()const
{
	std::cout << "Добавить элемент невозможно.";
}

template<typename Type>
void Stack<Type>::pop_top()
{
	if (_size == 0)
		return;

	try
	{
		Type *ptr = new Type[_size - 1];
		for (int i = 0; i < _size - 1; i++)
			ptr[i] = array[i + 1];

		delete[] array;
		array = ptr;
		_size--;
	}
	catch (std::bad_alloc)
	{
		error_alloc();
	}
	
}

template<typename Type>
void Stack<Type>::push_top(Type value)
{
	try
	{
		Type *ptr = new Type[_size + 1];
		ptr[0] = value;
		for (int i = 0; i < _size; i++)
			ptr[i + 1] = array[i];

		delete[]array;

		array = ptr;
		_size++;
	}
	catch (std::bad_alloc)
	{
		error_alloc();
	}
	
}

template<typename Type>
Stack<Type>::Stack()
{
	_size = 0;
	array = nullptr;
}

template<typename Type>
Stack<Type>::Stack(int size)
{
	try
	{
		array = new Type[size];
		_size = size;
	}
	catch (std::bad_alloc)
	{
		error_alloc();
	}
}

template<typename Type>
Stack<Type>::~Stack()
{
	delete[] array;
}