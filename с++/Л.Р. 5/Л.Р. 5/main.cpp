#include "Worker.h"

int main()
{
	system("chcp 1251");
	system("cls");

	Worker obj;
	obj.show();

	Worker obj2("Alex", 5, 22, "продовец", "менеджер", "кабинет 12", "John", 10, "кабинет 21", 42, "зав. отдела продаж", "отдел продаж");
	obj2.show();

	obj2.set_name("Kurt");
	cout << "Имя:" << obj2.get_name() << endl;

	obj2.set_age(-27);
	obj2.set_age(27);
	cout << "Возраст:" << obj2.get_age() << endl;

	obj2.set_experience(-7);
	obj2.set_experience(7);
	cout << "Опыт работы:" << obj2.get_experience() << endl;

	obj2.set_location_worker("кабинет 1");
	if (obj2.value_presence_place_worker() == true)
		cout << "рабочее место есть:"<<obj2.get_location_worker() << endl;
	else
		cout << "рабочего места нет" << endl;

	obj2.set_location_worker("Отсутствует");
	if (obj2.value_presence_place_worker() == true)
		cout << "рабочее место есть:" << obj2.get_location_worker() << endl;
	else
		cout << "рабочего места нет" << endl;

	obj2.set_post("Копирайтер");
	cout << "Должность:" << obj2.get_post() << endl;

	obj2.set_name_speciality("Филолог");
	cout << "специальность:" << obj2.get_name_speciality() << endl << endl;

	cout << "Начальник" << endl;

	obj2.set_chief_name("Don");
	cout << "Имя:" << obj2.get_chief_name() << endl;

	obj2.set_chief_age(-47);
	obj2.set_chief_age(47);
	cout << "Возраст:" << obj2.get_chief_age() << endl;

	obj2.set_chief_post("Зав. отдела креатива");
	cout << "Должность:" << obj2.get_chief_post() << endl;

	obj2.set_chief_count_people(-5);
	obj2.set_chief_count_people(5);
	cout << "Количество подчиненных:" << obj2.get_chief_count_people() << endl;


	obj2.set_chief_location_place("кабинет 17");
	if (obj2.get_chief_presence_place() == true)
		cout << "рабочее место есть:" << obj2.get_chief_location_place() << endl;
	else
		cout << "рабочего места есть" << endl;

	obj2.set_chief_location_place("нет");
	if (obj2.get_chief_presence_place() == true)
		cout << "рабочее место есть:" << obj2.get_chief_location_place() << endl;
	else
		cout << "рабочего места есть" << endl;

	obj2.set_name_departament_worker("Отдел продаж");
	cout << "Название отдела:" << obj2.get_name_departament_worker() << endl;

	obj2.set_worker_departament_count_workers(-7);
	obj2.set_worker_departament_count_workers(7);
	cout << "Количество сотрудников в отделе:" << obj2.get_worker_departament_count_workers() << endl;


	system("pause");
	return 0;
}