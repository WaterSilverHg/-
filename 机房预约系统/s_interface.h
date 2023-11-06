#pragma once
#include<iostream>

#include"appointment.h"
#include"file_control.h"
#include"file_name.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class S_Interface
{
public:
	string number;
	string name;

	S_Interface();
	bool enter();
	int face();
	void my_check();
	void s_check();
	void invite();
	void cancel();
};