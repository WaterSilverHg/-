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
	bool verify(string, string, string,string filename);//检测登录是否成功
	void add_aps(Appointment);//添加预约
	void show_aps(string str = "");//展示预约情况  string 默认为空
	void change_aps(string,string = "");//改变内容

	void add(string, int);//添加人员1学生2教师
	void show(string, int);//展示人员信息1学生2老师
	bool check(string,string);//是否有相同编号
	bool exist(string);//文件是否曾经存在  若不存在则创建并返回0

	vector<Appointment> get_aps();//获取一个预约信息的容器
	void re_aps(vector<Appointment>);//将结果写入
};