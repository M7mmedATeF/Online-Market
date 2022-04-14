#include <iostream>
#include <string>
#include <list>

// Classes
#include "user.h"
#include "LinkedList.cpp"
using namespace std;

int main() {
	LinkedList<user> users;

	user user1;
	user1.id = 5;
	
	users.Append(user1);

	for (int i = 0; i < users.Length(); i++)
		cout << users.At(i).id << endl;
	return 0;
}
