#include"file_control.h"


bool File_Control::verify(string number, string name, string password, string filename)
{
	if (!exist(filename))
	{
		cout << "�޸�ѧ����Ϣ.empty" << endl;
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
			cout << "�޸�ѧ����Ϣ.empty" << endl;
			return false;
		}
		ifs.seekg(0, ios::beg);
		string str = "";
		int times = 0;
		int yn = 0;//�Եĸ���
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
		cout << "�޸�ѧ����Ϣ.nofind" << endl;
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
			cout << "ԤԼΪ��" << endl;
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
						cout << "ԤԼѧ�ţ�" << str;
				}
				else if (times % 6 == 1)
				{
					if (showtimes-- > 0)
						cout << "  ������" << str;
				}
				else if (times % 6 == 2)
				{
					if (showtimes-- > 0)
						cout << "  ������" << str;
				}
				else if (times % 6 == 3)
				{
					if (showtimes-- > 0)
						cout << "  ������" << str;
				}
				else if (times % 6 == 4)
				{
					if (showtimes-- > 0)
						cout << "  ʱ�Σ�" << str;
				}
				else
				{
					if (showtimes-- > 0)
						cout << "  ��������" << str << endl;
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
			cout << "ԤԼΪ��" << endl;
		}
	}
	else
	{
		cout << "ԤԼΪ��" << endl;
	}*/
	vector<Appointment> v1 = get_aps();
	bool showyn = 0;
	int num = 1;
	for (vector<Appointment>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		if ((*it).number == number || number == "")
		{
			cout << num << '.';
			cout << "ԤԼѧ�ţ�" << (*it).number;
			cout << "  ������" << (*it).name;
			cout << "  ������" << (*it).room;
			cout << "  ������" << (*it).date;
			cout << "  ʱ�Σ�" << (*it).time;
			cout << "  ԤԼ�����" << (*it).condition << endl;
			showyn = 1;
			num++;
		}
	}
	if (!showyn)
	{
		cout << "ԤԼΪ��" << endl;
	}
}

void File_Control::change_aps(string s,string number)
{
	int choice;
	vector<Appointment> v1 = get_aps();
	if(s == "t")
	{
		show_aps();
		cout << "��ѡ����˵ı��" << endl;
		cin >> choice;
		while (choice > v1.size())
		{
			cout << "��������ȷ�ı��" << endl;
			cin >> choice;
		}
		string& str = v1[choice - 1].condition;
		if (str == "δ���")
		{
			cout << "��ѡ��\n1.ͨ��\n2.��ͨ��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				str = "���ͨ��";
			}
			else if (choice == 2)
			{
				str = "���δͨ��";
			}
			re_aps(v1);
		}
		else
		{
			cout << "�˽�����޷�����" << endl;
		}
	}
	else if (s == "s")
	{
		show_aps(number);
		cout << "��ѡ����Ҫȡ����ԤԼ" << endl;
		cin >> choice;
		int num = 1;
		for (vector<Appointment>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			if ((*it).number == number)
			{
				if (choice == num)
				{
					if((*it).condition == "ԤԼȡ��")
					{
						cout << "��ԤԼ����ȡ��" << endl;
						break;
					}
					(*it).condition = "ԤԼȡ��";
					cout << "ȡ���ɹ�";
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
		str = "ѧ��";
	}
	else if (num == 2)
	{
		str = "ְ�����";
	}
	cout << "������" << str << endl;
	cin >> number;
	while (check(filename, number))
	{
		cout << "��" << str << "�Ѵ���\n���������룺" << endl;
		cin >> number;
	}
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> password;
	ofs << number << ',' << name << ',' << password << ',' << endl;
	ofs.close();
	cout << "��������" << endl;
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
			t_str = "ѧ��";
		}
		else if(num == 2)
		{
			t_str = "ְ�����";
		}
		std::ifstream ifs;
		ifs.open(filename, ios::in);
		char ch = 0;
		ifs >> ch;
		if (ch == EOF)
		{
			cout << "��ϢΪ��" << endl;
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
					cout << t_str << "Ϊ��" << str<<"  ";
				}
				else if(times % 3 == 1)
				{
					cout << "����Ϊ��" << str << "  ";
				}
				else
				{
					cout << "����Ϊ��" << str << endl;
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
		cout << "��ϢΪ��" << endl;
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
			cout << "ԤԼΪ��" << endl;
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
		cout << "ԤԼΪ��" << endl;
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