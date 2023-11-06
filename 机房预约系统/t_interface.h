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
	void t_check();//看预约情况
	void check();//审核
};