#include "Worker.h"

int main()
{
	system("chcp 1251");
	system("cls");

	Worker obj;
	obj.show();

	Worker obj2("Alex", 5, 22, "��������", "��������", "������� 12", "John", 10, "������� 21", 42, "���. ������ ������", "����� ������");
	obj2.show();

	obj2.set_name("Kurt");
	cout << "���:" << obj2.get_name() << endl;

	obj2.set_age(-27);
	obj2.set_age(27);
	cout << "�������:" << obj2.get_age() << endl;

	obj2.set_experience(-7);
	obj2.set_experience(7);
	cout << "���� ������:" << obj2.get_experience() << endl;

	obj2.set_location_worker("������� 1");
	if (obj2.value_presence_place_worker() == true)
		cout << "������� ����� ����:"<<obj2.get_location_worker() << endl;
	else
		cout << "�������� ����� ���" << endl;

	obj2.set_location_worker("�����������");
	if (obj2.value_presence_place_worker() == true)
		cout << "������� ����� ����:" << obj2.get_location_worker() << endl;
	else
		cout << "�������� ����� ���" << endl;

	obj2.set_post("����������");
	cout << "���������:" << obj2.get_post() << endl;

	obj2.set_name_speciality("�������");
	cout << "�������������:" << obj2.get_name_speciality() << endl << endl;

	cout << "���������" << endl;

	obj2.set_chief_name("Don");
	cout << "���:" << obj2.get_chief_name() << endl;

	obj2.set_chief_age(-47);
	obj2.set_chief_age(47);
	cout << "�������:" << obj2.get_chief_age() << endl;

	obj2.set_chief_post("���. ������ ��������");
	cout << "���������:" << obj2.get_chief_post() << endl;

	obj2.set_chief_count_people(-5);
	obj2.set_chief_count_people(5);
	cout << "���������� �����������:" << obj2.get_chief_count_people() << endl;


	obj2.set_chief_location_place("������� 17");
	if (obj2.get_chief_presence_place() == true)
		cout << "������� ����� ����:" << obj2.get_chief_location_place() << endl;
	else
		cout << "�������� ����� ����" << endl;

	obj2.set_chief_location_place("���");
	if (obj2.get_chief_presence_place() == true)
		cout << "������� ����� ����:" << obj2.get_chief_location_place() << endl;
	else
		cout << "�������� ����� ����" << endl;

	obj2.set_name_departament_worker("����� ������");
	cout << "�������� ������:" << obj2.get_name_departament_worker() << endl;

	obj2.set_worker_departament_count_workers(-7);
	obj2.set_worker_departament_count_workers(7);
	cout << "���������� ����������� � ������:" << obj2.get_worker_departament_count_workers() << endl;


	system("pause");
	return 0;
}