#include <iostream>
#include "user.h";
using namespace std;

user::user(int id, string name, string email, bool is_seller, string phone, string password)
{
	this->id = id;
	this->name = name;
	this->email = email;
	this->is_seller = is_seller;
	this->phone = phone;
	this->password = password;
}