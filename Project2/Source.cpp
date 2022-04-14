#include <iostream>
#include <string>
#include <list>

// Classes
#include "user.cpp"
#include "LinkedList.cpp"
using namespace std;

int main() {
	LinkedList<user> users;

	user u1;
	u1.id = 1;
	u1.name = "name";
	u1.email = "mail";

	users.Append(u1);
	

	for (int i = 0; i < users.Length(); i++)
		cout << users.At(i).id << endl;
	return 0;
}
