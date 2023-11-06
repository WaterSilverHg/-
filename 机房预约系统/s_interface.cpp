#include"s_interface.h"


S_Interface::S_Interface()
{
	bool pass = enter();
	while (pass)
	{
		system("pause");
		system("cls");
		switch (face())
		{
		case 1:
			invite();
			break;
		case 2:
			my_check();
			break;
		case 3:
			s_check();
			break;
		case 4:
			cancel();
			break;
		case 0:
			pass = 0;
			cout << "���ѵǳ�" << endl;
			break;
		}
	}
	system("pause");
}

bool S_Interface::enter()
{
	string password;
	cout << "����������ѧ��" << endl;
	cin >> this->number;
	cout << "��������������" << endl;
	cin >> this->name;
	cout << "��������������" << endl;
	cin >> password;
	bool yn = File_Control().verify(this->number, this->name, password, File_Name().get_s());
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

int S_Interface::face()
{
	int choice = 0;
	while (1)
	{
		cout << this->name << "��ӭ��\n��ѡ�������\n1.  Ԥ Լ  �� ��\n2.  �鿴�ҵ�ԤԼ\n3.  �鿴����ԤԼ\n4.  ȡ ��  Ԥ Լ\n0.    ��    ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		case 0:
			return 0;
		default:
			cout << "����ȷ����" << endl;
			break;
		}
	}
}

void S_Interface::invite()
{
	int choice = 0;
	Appointment Ap;
	Ap.number = this->number;
	Ap.name = this->name;
	cout << "��ѡ�������\n1.����1\n2.����2\n3.����3" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		Ap.room = "����1";
		break;
	case 2:
		Ap.room = "����2";
		break;
	case 3:
		Ap.room = "����3";
		break;
	}
	cout << "��ѡ������ԤԼ�����ڣ�\n1.��һ\n2.�ܶ�\n3.����\n4.����\n5.����" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		Ap.date = "��һ";
		break;
	case 2:
		Ap.date = "�ܶ�";
		break;
	case 3:
		Ap.date = "����";
		break;
	case 4:
		Ap.date = "����";
		break;
	case 5:
		Ap.date = "����";
		break;
	}
	cout << "��ѡ������ԤԼ��ʱ��Σ�\n1.����\n2.����" << endl;
	cin >> choice;
	if (choice == 1)
	{
		Ap.time = "����";
	}
	if (choice == 2)
	{
		Ap.time = "����";
	}
	Ap.condition = "δ���";
	File_Control().add_aps(Ap);
	cout << "ԤԼ�ύ�ɹ�" << endl;
}

void S_Interface::my_check()
{
	File_Control().show_aps(this->number);

}
void S_Interface::s_check()
{
	File_Control().show_aps();
}



void S_Interface::cancel()
{
	File_Control().change_aps("s",this->number);
}