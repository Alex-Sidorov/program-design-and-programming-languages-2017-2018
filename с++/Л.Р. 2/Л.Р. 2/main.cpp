#include "class.h"

int main()
{
    system("chcp 1251");
	system("cls");

	detail detail_obj1;
	show(detail_obj1);
	//system("pause");

    detail detail_obj2(1001, "������ 1", 100);
	show(detail_obj2);
	//system("pause");

	detail_obj1.input_id_and_name();//���� id � name
	show(detail_obj1);
	system("pause");

	control control_obj1;
	system("pause");

	control_obj1.change_mass(detail_obj1, 150);//��������� �����
	show(detail_obj1);
	system("pause");
  
	control_obj1.change_mass(detail_obj2, 50);
	show(detail_obj2);
	system("pause");

	control_obj1.input_mass(detail_obj2);//���� �����
	show(detail_obj2);
	system("pause");

    detail detail_obj3(45, "������ 3", 11);
	show(detail_obj3);
	system("pause");

    detail mas_detail_obj1[3];//�������� ������� �������� ������������� ��-���������
    for (int i = 0; i < 3;i++)
        show(mas_detail_obj1[i]);

	system("pause");

    control_obj1.change_mass(mas_detail_obj1[0], 0);
    show(mas_detail_obj1[0]);
	system("pause");

    control_obj1.change_mass(mas_detail_obj1[1], 1);
    show(mas_detail_obj1[1]);
	system("pause");

    control_obj1.change_mass(mas_detail_obj1[2], 2);
    show(mas_detail_obj1[2]);
	system("pause");

    detail mas_detail_obj2[2] = { detail(122,"������ 1 �� �������",33), detail(122,"������ 2 �� �������",73) };//�������� ������� ��������
    for (int i = 0; i < 2;i++)                                                                                 //������������� �������������
		show(mas_detail_obj2[i]);

	system("pause");
    
	control_obj1.change_mass(mas_detail_obj2[0], 10);
	show(mas_detail_obj2[0]);
	system("pause");

	control_obj1.change_mass(mas_detail_obj2[1], 101);
	show(mas_detail_obj2[1]);
	system("pause");

	return 0;
}
