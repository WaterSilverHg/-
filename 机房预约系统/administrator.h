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
	bool enter();//����
	int face();//����
	void a_add();//��ӳ�Ա
	void a_check();//�鿴��Ա��Ϣ
	void a_delete ();//
	void check_room();//�鿴������Ϣ
	void clear_aps();//���ԤԼ
};