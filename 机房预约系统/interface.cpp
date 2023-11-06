#include"interface.h"

int Interface::show()
{
	int choice = 0;
	while (1)
	{
		cout << "请选择你的身份登录：\n1.  学  生\n2.  教  师\n3.  管理员\n0.  退  出" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 0:
			return 0;
		default:
			cout << "请正确输入" << endl;
			break;
		}
	}
}