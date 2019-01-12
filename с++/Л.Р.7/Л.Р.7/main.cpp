#include "Human.h"
#include "Programmer.h"
#include "Scenarist.h"
#include "Writer.h"

int main()
{
	system("chcp 1251");
	system("cls");

	Human **massiv = new Human*[3];
	if (massiv == nullptr)
		return 1;	

	Writer writer(4, 5, "Tom");
	Programmer programmer(10, 4, "John");
	Scenarist scenarist(5, 3, "Ray");
	
	massiv[0] = &writer;
	massiv[1] = &scenarist;
	massiv[2] = &programmer;

	for (int i = 0; i < 3; i++)
	{
		massiv[i]->show();
		cout << "Количество проектов в год:" << massiv[i]->count_project_in_year() << endl << endl;
	}

	system("pause");
	delete[] massiv;
	return 0;
}