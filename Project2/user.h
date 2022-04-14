#pragma once
#include "product.h"
#include "LinkedList.h"
#include <list>

class user
{
public:
	int id;
	string name;
	string email;
	bool is_seller;
	string phone;
	string password;

	static user sparateUserData(char sign, string row);
	static void select(string table, list<user> users);
};

