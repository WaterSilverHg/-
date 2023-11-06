#pragma once
#include<iostream>

#include"file_name.h"
#include"file_control.h"
#include"room.h"

using std::cout;
using std::cin;
using std::endl;



class Administrator
{
public:
	string c_account;
	string c_password;

	Administrator();
	bool enter();//登入
	int face();//界面
	void a_add();//添加成员
	void a_check();//查看成员信息
	void a_delete ();//
	void check_room();//查看机房信息
	void clear_aps();//清空预约
};