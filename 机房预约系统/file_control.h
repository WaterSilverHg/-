#pragma once
#include<fstream>
#include<vector>
#include<iostream>

#include"appointment.h"
#include"file_name.h"

using std::vector;
using std::ios;
using std::cout;
using std::cin;
using std::endl;

class File_Control
{
public:
	bool verify(string, string, string,string filename);//����¼�Ƿ�ɹ�
	void add_aps(Appointment);//���ԤԼ
	void show_aps(string str = "");//չʾԤԼ���  string Ĭ��Ϊ��
	void change_aps(string,string = "");//�ı�����

	void add(string, int);//�����Ա1ѧ��2��ʦ
	void show(string, int);//չʾ��Ա��Ϣ1ѧ��2��ʦ
	bool check(string,string);//�Ƿ�����ͬ���
	bool exist(string);//�ļ��Ƿ���������  ���������򴴽�������0

	vector<Appointment> get_aps();//��ȡһ��ԤԼ��Ϣ������
	void re_aps(vector<Appointment>);//�����д��
};