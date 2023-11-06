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
			cout << "您已登出" << endl;
			break;
		}
	}
	system("pause");
}

bool T_Interface::enter()
{
	string password;
	cout << "请输入您的职工编号" << endl;
	cin >> this->number;
	cout << "请输入您的姓名" << endl;
	cin >> this->name;
	cout << "请输入您的密码" << endl;
	cin >> password;
	bool yn = File_Control().verify(this->number, this->name, password, File_Name().get_t());
	if (yn)
	{
		cout << "登录成功" << endl;
	}
	else
	{
		cout << "登录失败" << endl;
	}
	return yn;
}

int T_Interface::face()
{
	int choice = 0;
	while (1)
	{
		cout << this->name << "欢迎您\n请选择操作：\n1.  查看所有预约\n2.  审 核  预 约\n0.    退    出" << endl;
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
			cout << "请正确输入" << endl;
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