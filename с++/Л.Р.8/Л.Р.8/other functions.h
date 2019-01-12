#pragma once

#include <iostream>
#include <ctime>

using namespace std;

template<typename Type>
void review_mas(Type *mas, int size);

template<typename Type>
void rand_mas(Type mas, int size);

template<>
void rand_mas<char*>(char *mas, int size);

template<typename Type>
void review_mas(Type *mas, int size)
{
	for (int i = 0; i < size; i++)
		cout << mas[i] << " ";
}

template<typename Type>
void rand_mas(Type mas, int size)
{
	for (int i = 0; i < size; i++)
		mas[i] = rand() % 100;
}

template<>
void rand_mas<char*>(char *mas, int size)
{
	for (int i = 0; i < size; i++)
		mas[i] = 65 + rand() % 25;
}