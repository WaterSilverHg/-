#include"interface.h"

int Interface::show()
{
	int choice = 0;
	while (1)
	{
		cout << "��ѡ�������ݵ�¼��\n1.  ѧ  ��\n2.  ��  ʦ\n3.  ����Ա\n0.  ��  ��" << endl;
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
			cout << "����ȷ����" << endl;
			break;
		}
	}
}