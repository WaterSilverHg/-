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
			cout << "您已登出" << endl;
			break;
		}
	}
	system("pause");
}

bool S_Interface::enter()
{
	string password;
	cout << "请输入您的学号" << endl;
	cin >> this->number;
	cout << "请输入您的姓名" << endl;
	cin >> this->name;
	cout << "请输入您的密码" << endl;
	cin >> password;
	bool yn = File_Control().verify(this->number, this->name, password, File_Name().get_s());
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

int S_Interface::face()
{
	int choice = 0;
	while (1)
	{
		cout << this->name << "欢迎您\n请选择操作：\n1.  预 约  机 房\n2.  查看我的预约\n3.  查看所有预约\n4.  取 消  预 约\n0.    退    出" << endl;
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
			cout << "请正确输入" << endl;
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
	cout << "请选择机房：\n1.机房1\n2.机房2\n3.机房3" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		Ap.room = "机房1";
		break;
	case 2:
		Ap.room = "机房2";
		break;
	case 3:
		Ap.room = "机房3";
		break;
	}
	cout << "请选择你想预约的日期：\n1.周一\n2.周二\n3.周三\n4.周四\n5.周五" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		Ap.date = "周一";
		break;
	case 2:
		Ap.date = "周二";
		break;
	case 3:
		Ap.date = "周三";
		break;
	case 4:
		Ap.date = "周四";
		break;
	case 5:
		Ap.date = "周五";
		break;
	}
	cout << "请选择你想预约的时间段：\n1.上午\n2.下午" << endl;
	cin >> choice;
	if (choice == 1)
	{
		Ap.time = "上午";
	}
	if (choice == 2)
	{
		Ap.time = "下午";
	}
	Ap.condition = "未审核";
	File_Control().add_aps(Ap);
	cout << "预约提交成功" << endl;
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