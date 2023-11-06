#pragma once
#include<iostream>
using std::string;

class File_Name
{
public:
	string get_s();
	string get_t();
	string get_a();
private:
	string s_file = "student.csv";
	string t_file = "teacher.csv";
	string aps_file = "appointment.csv";
};