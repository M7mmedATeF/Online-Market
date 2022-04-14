#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

class user
{
public:
	int id;
	string name;
	string email;
	bool is_seller;
	string phone;
	string password;

	user();
	user(int id, string name, string email, bool is_seller, string phone, string password);
	
};

