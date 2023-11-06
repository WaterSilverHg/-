#include"administrator.h"

Administrator::Administrator()
{
	this->c_account = "admin";
	this->c_password = "123456";

	bool pass = enter();
	while (pass)
	{
		int choice = 0;
		system("pause");
		system("cls");
		switch (face())
		{
		case 1:
			a_add();
			break;
		case 2:
			a_check();
			break;
		case 3:
			a_delete();
			break;
		case 4:
			check_room();
			break;
		case 5:
			clear_aps();
			break;
		case 0:
			pass = 0;
			break;
		}
	}
	cout << "���ѵǳ�" << endl;
	system("pause");
}

bool Administrator::enter()
{
	std::string account,password;
	cout << "�����������˺�" << endl;
	cin >> account;
	cout << "��������������" << endl;
	cin >> password;
	if (account == c_account && password == c_password)
	{
		cout << "��¼�ɹ�" << endl;
		return true;
	}
	else
	{
		cout << "�˺Ż��������" << endl;
		return false;
	}
}

int Administrator::face()
{
	int choice = 0;
	while(1)
	{
		cout << c_account << "��ӭ��\n��ѡ�������\n1.  ����˺�\n2.  �鿴�˺�\n3.  ɾ���˺�\n4.  �鿴����\n5.  ���ԤԼ\n0.  ��  ��" << endl;
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
		case 5:
			return 5;
		case 0:
			return 0;
		default:
			cout << "����ȷ����" << endl;
			break;
		}
	}

}

void Administrator::a_add()
{
	cout << "��Ҫ��ӵ��˺�����ѡ��\n1.  ѧ  ��\n2.  ��  ʦ" << endl;
	int choice = 0;
	cin >> choice;
	string file;
	if (choice == 1)
	{
		file = File_Name().get_s();
	}
	else if (choice == 2)
	{
		file = File_Name().get_t();
	}
	File_Control().add(file,choice);
}

void Administrator::a_delete()
{
	cout << "��Ǹ�ù���δ����" << endl;
}


void Administrator::a_check()
{
	int choice = 0;
	cout << "��Ҫ���ҵ���Ϣ��\n1.  ѧ  ��\n2.  ��  ʦ" << endl;
	cin >> choice;
	string file;
	if (choice == 1)
	{
		file = File_Name().get_s();
	}
	else if (choice == 2)
	{
		file = File_Name().get_t();
	}
	File_Control().show(file, choice);
}


void Administrator::check_room()
{
	cout << "һ�Ż���������" << Room().r1 << "\n���Ż���������" << Room().r2 << "\n���Ż���������" << Room().r3 << endl;
}

void Administrator::clear_aps()
{
	int choice = 0;
	while(1)
	{
		cout << "��ȷ����\n1.ȷ��\n2.ȡ��";
		cin >> choice;
		if (choice == 1)
		{
			break;
		}
		else if (choice == 2)
		{
			return;
		}
	}
	std::ofstream ofs;
	ofs.open(File_Name().get_a(), ios::out);
	cout << "��¼�����" << endl;
	ofs.close();
}