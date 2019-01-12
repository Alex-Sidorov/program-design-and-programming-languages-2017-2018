#pragma once

template<typename Type>
void booble_sort_up(Type *mas, int size)
{
	Type temp = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > 0; j--)
		{
			if (mas[j] < mas[j - 1])
			{
				temp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = temp;
			}
		}
	}
}

template<>
void booble_sort_up<char>(char *mas, int size)
{
	char temp = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > 0; j--)
		{
			if (mas[j] < mas[j - 1])
			{
				temp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = temp;
			}
		}
	}
}

template<typename Type>
void booble_sort_down(Type *mas, int size)
{
	Type temp = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > 0; j--)
		{
			if (mas[j] > mas[j - 1])
			{
				temp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = temp;
			}
		}
	}
}

template<>
void booble_sort_down<char>(char *mas, int size)
{
	char temp = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > 0; j--)
		{
			if (mas[j] > mas[j - 1])
			{
				temp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = temp;
			}
		}
	}
}

template<typename Type>
void insert_sort_up(Type *mas, int size)
{
	Type temp = 0;
	int	index = 0; //индекс предыдущего элемента массива

	for (int i = 1; i < size; i++)
	{
		temp = mas[i];
		index = i - 1;

		while (index >= 0 && mas[index] > temp)
		{
			mas[index + 1] = mas[index];
			mas[index] = temp;
			index--;
		}
	}
}

template<typename Type>
void insert_sort_down(Type *mas, int size)
{
	Type temp = 0;
	int index = 0; //индекс предыдущего элемента массива

	for (int i = 1; i < size;i++)
	{
		temp = mas[i];
		index = i - 1;

		while (index >= 0 && mas[index] < temp)
		{
			mas[index + 1] = mas[index];
			mas[index] = temp;
			index--;
		}
	}
}

template<typename Type>
void selection_sort_up(Type *mas, int size)
{
	Type temp = 0;
	int min = 0;// индекс минимального элемента массива

	for (int i = 0; i < size - 1; i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (mas[min] > mas[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = mas[min];
			mas[min] = mas[i];
			mas[i] = temp;
		}
	}
}

template<typename Type>
void selection_sort_down(Type *mas, int size)
{
	Type temp = 0;
	int max = 0;// индекс максимального элемента массива

	for (int i = 0; i < size - 1; i++)
	{
		max = i;

		for (int j = i + 1; j < size; j++)
		{
			if (mas[max] < mas[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			temp = mas[max];
			mas[max] = mas[i];
			mas[i] = temp;
		}
	}
}

template<typename Type>
void Shell_sort_up(Type *mas, int size)
{
	Type temp = 0;
	int step_one = 0;
	int step_two = 0;
	int flag = 0;

	for (step_one = size / 2; step_one > 0; step_one /= 2)
	{
		do
		{
			flag = 0;
			step_two = step_one;

			for (int i = 0; step_two < size; i++, step_two++)
			{
				if (mas[i] > mas[step_two])
				{
					temp = mas[i];
					mas[i] = mas[step_two];
					mas[step_two] = temp;
					flag = 1;
				}
			}

		} while (flag == 1);
	}
}

template<typename Type>
void Shell_sort_down(Type *mas, int size)
{
	Type temp = 0;
	int step_one = 0;
	int step_two = 0;
	int flag = 0;

	for (step_one = size / 2; step_one > 0; step_one /= 2)
	{
		do
		{
			flag = 0;
			step_two = step_one;

			for (int i = 0; step_two < size; i++, step_two++)
			{
				if (mas[i] < mas[step_two])
				{
					temp = mas[i];
					mas[i] = mas[step_two];
					mas[step_two] = temp;
					flag = 1;
				}
			}

		} while (flag == 1);
	}
}

template<typename Type>
void qsort_up(Type *mas, int left, int right)
{
	int i = left;
	int j = right;
	Type centr = mas[(left + right) / 2];
	Type temp = 0;

	do
	{
		while (mas[i] < centr) i++;
		while (mas[j] > centr) j--;

		if (i <= j)
		{
			temp = mas[i];
			mas[i] = mas[j];
			mas[j] = temp;

			i++;
			j--;
		}

	} while (i <= j);

	if (i < right)
	{
		qsort_up(mas, i, right);
	}

	if (j > left)
	{
		qsort_up(mas, left, j);
	}
}

template<typename Type>
void qsort_down(Type *mas, int left, int right)
{
	int i = left;
	int j = right;
	int centr = mas[(left + right) / 2];
	Type temp = 0;

	do
	{
		while (mas[i] > centr) i++;
		while (mas[j] < centr) j--;

		if (i <= j)
		{
			temp = mas[i];
			mas[i] = mas[j];
			mas[j] = temp;

			i++;
			j--;
		}

	} while (i <= j);

	if (i < right)
	{
		qsort_down(mas, i, right);
	}

	if (j > left)
	{
		qsort_down(mas, left, j);
	}
}

template<typename Type>
void Bender_sort_up(Type *mas, int size)
{
	Type temp = 0;
	int index_min = 0;// индекс мин элемента
	int index_max = 0;// индекс макс элемента
	int origin = 0; // начало массива

	do
	{
		index_min = origin;
		index_max = origin;

		for (int i = origin + 1; i < size; i++)
		{
			if (*(mas + index_max)<*(mas + i))
				index_max = i;

			if (*(mas + index_min)>*(mas + i))
				index_min = i;	
		}

		if (index_max != size - 1)
		{
			temp = *(mas + index_max);
			*(mas + index_max) = *(mas + size - 1);
			*(mas + size - 1) = temp;
		}

		if (index_min == size - 1)
			index_min = index_max;

		if (index_min != origin)
		{
			temp = *(mas + index_min);
			*(mas + index_min) = *(mas + origin);
			*(mas + origin) = temp;
		}

		size--;
		origin++;

	} while (origin<size);
}

template<typename Type>
void Bender_sort_down(Type *mas, int size)
{
	Type temp = 0;
	int index_min = 0;// индекс мин элемента
	int index_max = 0;// индекс макс элемента
	int origin = 0; // начало массива

	do
	{
		index_min = origin;
		index_max = origin;

		for (int i = origin + 1; i < size; i++)
		{
			if (*(mas + index_max) > *(mas + i))
				index_max = i;

			if (*(mas + index_min) < *(mas + i))
				index_min = i;
		}

		if (index_max != size - 1)
		{
			temp = *(mas + index_max);
			*(mas + index_max) = *(mas + size - 1);
			*(mas + size - 1) = temp;
		}

		if (index_min == size - 1)
			index_min = index_max;

		if (index_min != origin)
		{
			temp = *(mas + index_min);
			*(mas + index_min) = *(mas + origin);
			*(mas + origin) = temp;
		}

		size--;
		origin++;

	} while (origin < size);
}

template<>
void Bender_sort_down<char>(char *mas, int size)
{
	char temp = 0;
	int index_min = 0;// индекс мин элемента
	int index_max = 0;// индекс макс элемента
	int origin = 0; // начало массива
	
	do
	{
		index_min = origin;
		index_max = origin;

		for (int i = origin + 1; i < size; i++)
		{
			if (*(mas + index_max)>*(mas + i))
				index_max = i;

			if (*(mas + index_min)<*(mas + i))
				index_min = i;
		}

		if (index_max != size - 1)
		{
			temp = *(mas + index_max);
			*(mas + index_max) = *(mas + size - 1);
			*(mas + size - 1) = temp;
		}

		if (index_min == size - 1)
			index_min = index_max;

		if (index_min != origin)
		{
			temp = *(mas + index_min);
			*(mas + index_min) = *(mas + origin);
			*(mas + origin) = temp;
		}

		size--;
		origin++;

	} while (origin<size);
}

template <class T>
class a
{
public:
	a() { a = 0; }
	~a() {}
	a(const T b) { a = b; };
	T get() { return a; }
private:
	T a1;
};

class l :public a<T>
{

};
template <class T>
class  c : public a<T>
{
public:
	c() {};
	T get() { return  c; }
	T  cc;
};