//��������  �����Ŀ���� ��� ȡ��ԤԼ ����Աɾ����Ա(û��Ҫ��) û��
//giao ���Ǹ����� ����Ա��ɾ��û��
//Ҫ����Ļ�Ӧ��Ҫ������������ �����Ļ��ܶ����Ҫ�Ż�����Ȼ���Ż�Ҳ��
// ���������˾͵�����ѧ����
//2023.11.5

#include"interface.h"
#include"s_interface.h"
#include"administrator.h"
#include"t_interface.h"


int main()
{
	while(1)
	{
		switch (Interface().show())
		{
		case 1:
			S_Interface();
			break;
		case 2:
			T_Interface();
			break;
		case 3:
			Administrator();
			break;
		case 0:
			cout << "��л����ʹ��" << endl;
			system("pause");
			exit(0);
		}
		system("cls");
	}

	return 0;
}