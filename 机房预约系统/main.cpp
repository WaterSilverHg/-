//不想做了  这个项目还差 审核 取消预约 管理员删除成员(没有要求) 没做
//giao 还是搞完了 管理员的删除没搞
//要处理的话应该要来容器和类了 这样的话很多代码要优化（虽然不优化也行
// 不想听课了就当黑马学完了
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
			cout << "感谢您的使用" << endl;
			system("pause");
			exit(0);
		}
		system("cls");
	}

	return 0;
}