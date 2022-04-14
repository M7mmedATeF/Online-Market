#include "user.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;


user user::sparateUserData(char sign, string row) {
	string variable = "";
	user temp;
	short int userVariableFlag = 0;
	for (int i = 0; i < row.length(); i++) {
		if (row[i] == sign) {
			switch (userVariableFlag)
			{
			case 0:
				temp.id = stoi(variable);
				break;
			case 1:
				temp.name = variable;
				break;
			case 2:
				temp.email = variable;
				break;
			case 3:
				temp.is_seller = stoi(variable);
				break;
			case 4:
				temp.phone = variable;
				break;
			case 5:
				temp.password = variable;
				break;
			default:
				// Add to Carte Function
				break;
			}
		}
		else {
			variable += row[i];
		}
	}
	return temp;
}

void user::select(string table, list<user> users) {
	string row = "";
	ifstream usersFile;
	usersFile.open(table);
	while (!usersFile.eof())
	{
		getline(usersFile, row);
	}
	usersFile.close();
}
