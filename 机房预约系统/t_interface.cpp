#include"t_interface.h"

T_Interface::T_Interface()
{
	bool pass = enter();
	while (pass)
	{
		system("pause");
		system("cls");
		switch (face())
		{
		case 1:
			t_check();
			break;
		case 2:
			check();
			break;
		case 0:
			pass = 0;
			cout << "���ѵǳ�" << endl;
			break;
		}
	}
	system("pause");
}

bool T_Interface::enter()
{
	string password;
	cout << "����������ְ�����" << endl;
	cin >> this->number;
	cout << "��������������" << endl;
	cin >> this->name;
	cout << "��������������" << endl;
	cin >> password;
	bool yn = File_Control().verify(this->number, this->name, password, File_Name().get_t());
	if (yn)
	{
		cout << "��¼�ɹ�" << endl;
	}
	else
	{
		cout << "��¼ʧ��" << endl;
	}
	return yn;
}

int T_Interface::face()
{
	int choice = 0;
	while (1)
	{
		cout << this->name << "��ӭ��\n��ѡ�������\n1.  �鿴����ԤԼ\n2.  �� ��  Ԥ Լ\n0.    ��    ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 0:
			return 0;
		default:
			cout << "����ȷ����" << endl;
			break;
		}
	}
}
void T_Interface::t_check()
{
	File_Control().show_aps();
}

void T_Interface::check()
{
	File_Control().change_aps("t");
}