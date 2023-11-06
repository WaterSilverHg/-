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
	cout << "您已登出" << endl;
	system("pause");
}

bool Administrator::enter()
{
	std::string account,password;
	cout << "请输入您的账号" << endl;
	cin >> account;
	cout << "请输入您的密码" << endl;
	cin >> password;
	if (account == c_account && password == c_password)
	{
		cout << "登录成功" << endl;
		return true;
	}
	else
	{
		cout << "账号或密码错误" << endl;
		return false;
	}
}

int Administrator::face()
{
	int choice = 0;
	while(1)
	{
		cout << c_account << "欢迎您\n请选择操作：\n1.  添加账号\n2.  查看账号\n3.  删除账号\n4.  查看机房\n5.  清空预约\n0.  退  出" << endl;
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
			cout << "请正确输入" << endl;
			break;
		}
	}

}

void Administrator::a_add()
{
	cout << "请要添加的账号类型选择：\n1.  学  生\n2.  教  师" << endl;
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
	cout << "抱歉该功能未启用" << endl;
}


void Administrator::a_check()
{
	int choice = 0;
	cout << "请要查找的信息：\n1.  学  生\n2.  教  师" << endl;
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
	cout << "一号机房容量：" << Room().r1 << "\n二号机房容量：" << Room().r2 << "\n三号机房容量：" << Room().r3 << endl;
}

void Administrator::clear_aps()
{
	int choice = 0;
	while(1)
	{
		cout << "您确定吗？\n1.确定\n2.取消";
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
	cout << "记录已清空" << endl;
	ofs.close();
}