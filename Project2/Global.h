#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "user.h"
#include "LinkedList.h"
using namespace std;
class Global
{
	public:
		static void Select(string table, LinkedList<user> users);
};

