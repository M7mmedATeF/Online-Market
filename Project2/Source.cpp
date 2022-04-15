#include <iostream>
#include <fstream>
#include <string>

// Classes
#include "user.cpp"
#include "LinkedList.cpp"
#include "product.cpp"
using namespace std;


// Functions
void Select(string table, LinkedList<user>& users);

int main() {
	LinkedList<user> users;
	
	Select("users.txt",users);
	
	for (int i = 0; i < users.Length(); i++)
		cout << users.At(i).id << " " << users.At(i).name << endl;
	return 0;
}

void Select(string table, LinkedList<user>& users) {
	ifstream file;
	file.open(table);
	user temp;
	string data = "";
	while (!file.eof()) {
		// ID
		getline(file, data);
		temp.id = stoi(data);

		// Name
		getline(file, temp.name);

		// email
		getline(file, temp.email);

		// is_seller
		getline(file, data);
		temp.is_seller = stoi(data);

		// phone
		getline(file, temp.phone);

		// password
		getline(file, temp.password);

		users.Append(temp);
	}
	file.close();
}

LinkedList<string> separate(string list) {
	LinkedList<string> separated;
	string productID = "";
	for (int i = 0; i < list.length(); i++) {
		if(list[i] == ',') {
			separated.Append(productID);
			productID = "";
		}
		else {
			productID += list[i];
		}
	}
	return separated;
}