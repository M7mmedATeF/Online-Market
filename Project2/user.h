#pragma once
#include <iostream>
#include "LinkedList.h"
#include "product.h"

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
	LinkedList<product> carte;
};