#include"file_control.h"


bool File_Control::verify(string number, string name, string password, string filename)
{
	if (!exist(filename))
	{
		cout << "无该学生信息.empty" << endl;
		return false;
	}
	else
	{
		std::ifstream ifs;
		ifs.open(filename, ios::in);
		char ch = 0;
		ifs >> ch;
		if (ch == EOF)
		{
			cout << "无该学生信息.empty" << endl;
			return false;
		}
		ifs.seekg(0, ios::beg);
		string str = "";
		int times = 0;
		int yn = 0;//对的个数
		while (ifs >> ch)
		{
			if (ch == ',')
			{
				if (times % 3 == 0)
				{
					if (str == number)
					{
						yn += 1;
					}
				}
				else if (times % 3 == 1)
				{
					if (str == name)
					{
						yn += 1;
					}
				}
				else
				{
					if (str == password)
					{
						yn += 1;
					}
					if (yn == 3)
					{
						return true;
					}
					else
					{
						yn = 0;
					}
				}
				times++;
				str = "";
			}
			else
			{
				str += ch;
			}
		}
		cout << "无该学生信息.nofind" << endl;
		return false;
	}
}

void File_Control::add_aps(Appointment Ap)
{
	string fn = File_Name().get_a();
	exist(fn);
	std::ofstream ofs;
	ofs.open(fn, ios::out | ios::app);
	ofs << Ap.number << ',' << Ap.name << ',' << Ap.room << ',' << Ap.date << ',' << Ap.time << ',' << Ap.condition << ',' << endl;
	ofs.close();
}

void File_Control::show_aps(string number)
{
	/*if (exist(File_Name().get_a()))
	{
		std::ifstream ifs;
		ifs.open(File_Name().get_a(), ios::in);
		char ch = 0;
		ifs >> ch;
		if (ch == EOF)
		{
			cout << "预约为空" << endl;
			return;
		}
		ifs.seekg(0, ios::beg);
		string str = "";
		int times = 0;
		int showtimes = 0;
		bool showyn = 0;
		while (ifs >> ch)
		{
			if (ch == ',')
			{
				if (times % 6 == 0)
				{
					if (number == str || number == "")
					{
						showtimes = 6;
						showyn = 1;
					}
					if(showtimes-->0)
						cout << "预约学号：" << str;
				}
				else if (times % 6 == 1)
				{
					if (showtimes-- > 0)
						cout << "  姓名：" << str;
				}
				else if (times % 6 == 2)
				{
					if (showtimes-- > 0)
						cout << "  机房：" << str;
				}
				else if (times % 6 == 3)
				{
					if (showtimes-- > 0)
						cout << "  周数：" << str;
				}
				else if (times % 6 == 4)
				{
					if (showtimes-- > 0)
						cout << "  时段：" << str;
				}
				else
				{
					if (showtimes-- > 0)
						cout << "  审核情况：" << str << endl;
				}
				times++;
				str = "";
			}
			else
			{
				str += ch;
			}
		}
		if (showyn == 0)
		{
			cout << "预约为空" << endl;
		}
	}
	else
	{
		cout << "预约为空" << endl;
	}*/
	vector<Appointment> v1 = get_aps();
	bool showyn = 0;
	int num = 1;
	for (vector<Appointment>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		if ((*it).number == number || number == "")
		{
			cout << num << '.';
			cout << "预约学号：" << (*it).number;
			cout << "  姓名：" << (*it).name;
			cout << "  机房：" << (*it).room;
			cout << "  周数：" << (*it).date;
			cout << "  时段：" << (*it).time;
			cout << "  预约情况：" << (*it).condition << endl;
			showyn = 1;
			num++;
		}
	}
	if (!showyn)
	{
		cout << "预约为空" << endl;
	}
}

void File_Control::change_aps(string s,string number)
{
	int choice;
	vector<Appointment> v1 = get_aps();
	if(s == "t")
	{
		show_aps();
		cout << "请选择审核的编号" << endl;
		cin >> choice;
		while (choice > v1.size())
		{
			cout << "请输入正确的编号" << endl;
			cin >> choice;
		}
		string& str = v1[choice - 1].condition;
		if (str == "未审核")
		{
			cout << "请选择\n1.通过\n2.不通过" << endl;
			cin >> choice;
			if (choice == 1)
			{
				str = "审核通过";
			}
			else if (choice == 2)
			{
				str = "审核未通过";
			}
			re_aps(v1);
		}
		else
		{
			cout << "此结果您无法更改" << endl;
		}
	}
	else if (s == "s")
	{
		show_aps(number);
		cout << "请选择你要取消的预约" << endl;
		cin >> choice;
		int num = 1;
		for (vector<Appointment>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			if ((*it).number == number)
			{
				if (choice == num)
				{
					if((*it).condition == "预约取消")
					{
						cout << "此预约您已取消" << endl;
						break;
					}
					(*it).condition = "预约取消";
					cout << "取消成功";
					break;
				}
				else
				{
					num++;
				}
			}
		}
		re_aps(v1);
	}
}


void  File_Control::add(string filename,int num)
{
	std::ofstream ofs;
	string number;
	string name;
	string password;
	string str;
	exist(filename);
	ofs.open(filename, ios::out | ios::app);
	if (num == 1)
	{
		str = "学号";
	}
	else if (num == 2)
	{
		str = "职工编号";
	}
	cout << "请输入" << str << endl;
	cin >> number;
	while (check(filename, number))
	{
		cout << "该" << str << "已存在\n请重新输入：" << endl;
		cin >> number;
	}
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> password;
	ofs << number << ',' << name << ',' << password << ',' << endl;
	ofs.close();
	cout << "已添加完成" << endl;
}


bool File_Control::exist(string filename)
{
	bool yn = 0;
	std::ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		std::ofstream ofs;
		ofs.open(filename, ios::out);
		ofs.close();
	}
	else
	{
		yn = 1;
	}
	ifs.close();
	return yn;
}

bool File_Control::check(string filename,string num)
{
	std::ifstream ifs;
	ifs.open(filename, ios::in);
	int times = 0;
	char ch = 0;
	string str = "";
	while (ifs >> ch)
	{
		if (ch == ',')
		{
			if (times % 3 == 0)
			{
				if (str == num)
				{
					return true;
				}
				times++;
			}
			str = "";
		}
		str += ch;
	}
	return false;
}

void File_Control::show(string filename, int num)
{
	if (exist(filename))
	{
		string t_str;
		if (num == 1)
		{
			t_str = "学号";
		}
		else if(num == 2)
		{
			t_str = "职工编号";
		}
		std::ifstream ifs;
		ifs.open(filename, ios::in);
		char ch = 0;
		ifs >> ch;
		if (ch == EOF)
		{
			cout << "信息为空" << endl;
			return;
		}
		ifs.seekg(0,ios::beg);
		string str = "";
		int times = 0;
		while (ifs >> ch)
		{
			if (ch == ',')
			{
				if (times % 3 == 0)
				{
					cout << t_str << "为：" << str<<"  ";
				}
				else if(times % 3 == 1)
				{
					cout << "姓名为：" << str << "  ";
				}
				else
				{
					cout << "密码为：" << str << endl;
				}
				times++;
				str = "";
			}
			else
			{
				str += ch;
			}
		}
	}
	else
	{
		cout << "信息为空" << endl;
		return;
	}
}

vector<Appointment> File_Control::get_aps()
{
	vector<Appointment> v1;
	if (exist(File_Name().get_a()))
	{
		std::ifstream ifs;
		ifs.open(File_Name().get_a(), ios::in);
		char ch = 0;
		ifs >> ch;
		if (ch == EOF)
		{
			cout << "预约为空" << endl;
			return v1;
		}
		ifs.seekg(0, ios::beg);
		string str = "";
		int times = 0;
		Appointment temp;
		while (ifs >> ch)
		{
			if (ch == ',')
			{
				if (times % 6 == 0)
				{
					temp.number = str;
				}
				else if (times % 6 == 1)
				{
					temp.name = str;
				}
				else if (times % 6 == 2)
				{
					temp.room = str;
				}
				else if (times % 6 == 3)
				{
					temp.date = str;
				}
				else if (times % 6 == 4)
				{
					temp.time = str;
				}
				else
				{
					temp.condition = str;
					v1.push_back(temp);
				}
				times++;
				str = "";
			}
			else
			{
				str += ch;
			}
		}
	}
	else
	{
		cout << "预约为空" << endl;
	}
	return v1;
}


void File_Control::re_aps(vector<Appointment> v1)
{
	std::ofstream ofs;
	ofs.open(File_Name().get_a(), ios::out);
	for (vector<Appointment>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		ofs << (*it).number << ',' << (*it).name << ',' << (*it).room << ',' << (*it).date << ',' << (*it).time << ',' << (*it).condition << ',' << endl;
	}
	ofs.close();
}