#pragma once

#include"file_control.h"
#include"file_name.h"

class T_Interface
{
public:
	string number;
	string name;

	T_Interface();
	bool enter();
	int face();
	void t_check();//��ԤԼ���
	void check();//���
};