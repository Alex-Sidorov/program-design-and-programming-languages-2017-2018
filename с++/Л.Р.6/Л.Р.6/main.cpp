#include "Indi_developer.h"

int main()
{
	system("chcp 1251");
	system("cls");

	Indi_developer obj_one;
	obj_one.show();

	cout << endl;

	Indi_developer obj_two(10, 12, false, 2, true, "John", 27);
	obj_two.show();

	cout << endl;
	cout << endl;

	obj_two.set_count_game_project(-1);
	obj_two.set_count_game_project(4);
	cout << "Количество сделанных игровых проектов:" << obj_two.get_count_game_project() << endl;

	obj_two.set_experience(-9);
	obj_two.set_experience(9);
	cout << "Опыт разработки:" << obj_two.get_experience() << endl;

	obj_two.set_count_screenplays(-6);
	obj_two.set_count_screenplays(6);
	cout << "Количество написанных сценариев:" << obj_two.get_count_screenplays() << endl;

	obj_two.change_has_certificate_or_diploma_programmer(false);
	if (obj_two.has_certificate_or_diploma_programmer() == true)
		cout << "Есть сертификат или диплом программиста." << endl;
	else
		cout << "Нет сертификата или диплома программиста." << endl;

	obj_two.change_has_certificate_or_diploma_writer(true);
	if (obj_two.has_certificate_or_diploma_writer() == true)
		cout << "Есть сертификат или диплом писателя." << endl;
	else
		cout << "Нет сертификата или диплома писателя." << endl;

	obj_two.set_name("Kurt");
	
	obj_two.set_age(-25);
	obj_two.set_age(25);

	Human *p = &obj_two;
	obj_two.show();
	Human &pointer = (Human)obj_two;
	pointer.show();

	system("pause");
 }