#pragma once

template<typename Type>
class MyIterator
{
public:
	MyIterator();
	MyIterator(Type *value);
	void set_ptr(Type *ptr);

	bool operator >(MyIterator<Type> it);

	bool operator >=(MyIterator<Type> it);	

	bool operator <=(MyIterator<Type> it);

	bool operator <(MyIterator<Type> it);

	bool operator ==(MyIterator<Type> it);


	MyIterator& operator++();
	MyIterator operator++(int);

	MyIterator& operator+(int value);

private:
	Type *_ptr;
};

template<typename Type>
MyIterator<Type>& MyIterator<Type>::operator++()
{
	_ptr++;
	return *this;
}

template<typename Type>
MyIterator<Type>& MyIterator<Type>::operator+(int value)
{
	_ptr += value;
	return *this;
}

template<typename Type>
MyIterator<Type> MyIterator<Type>::operator++(int flag)
{
	MyIterator<Type> temp = _ptr;
	_ptr++;

	return temp;
}

template<typename Type>
MyIterator<Type>::MyIterator()
{
	_ptr = nullptr; 
}

template<typename Type>
MyIterator<Type>::MyIterator(Type *value)
{ 
	_ptr = value; 
}

template<typename Type>
void MyIterator<Type>::set_ptr(Type *ptr)
{ 
	_ptr = ptr;
}

template<typename Type>
bool MyIterator<Type>::operator >(MyIterator<Type> it)
{
	if (_ptr > it._ptr) 
		return true;
	else 
		return false;
}

template<typename Type>
bool MyIterator<Type>::operator >=(MyIterator<Type> it)
{
	if (_ptr >= it._ptr)
		return true;
	else 
		return false;
}

template<typename Type>
bool MyIterator<Type>::operator <=(MyIterator<Type> it)
{
	if (_ptr <= it._ptr)
		return true;
	else 
		return false;
}

template<typename Type>
bool MyIterator<Type>::operator <(MyIterator<Type> it)
{
	if (_ptr < it._ptr)
		return true;
	else
		return false;
}

template<typename Type>
bool MyIterator<Type>::operator ==(MyIterator<Type> it)
{
	if (_ptr == it._ptr) return true;
	else return false;
}