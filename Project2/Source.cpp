#include <iostream>
#include <fstream>
#include <string>

// Classes
#include "user.cpp"
#include "LinkedList.cpp"
#include "product.cpp"
using namespace std;


// Functions
void selectUser(string table, LinkedList<user>& users);
void saveUsersData(string table, LinkedList<user>& users);
user SelectUserWithID(string table, int id);

int main() {
	LinkedList<user> users;
		
	selectUser("users.txt", users);

	user u1;
	u1.id = 5;
	u1.name = "43243432";
	u1.password = "asdasd";
	u1.email = "asdasd@";
	u1.phone = "12312312";
	u1.is_seller = 0;
	
	users.Append(u1);
	

	saveUsersData("users.txt", users);
	
	return 0;
}

void selectUser(string table, LinkedList<user>& users) {
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

void saveUsersData(string table, LinkedList<user>& users) {
	ofstream file;
	file.open(table);
	for (int i = 0; i < users.Length(); i++) {
		file << users.At(i).id << endl;
		file << users.At(i).name << endl;
		file << users.At(i).email << endl;
		file << users.At(i).is_seller << endl;
		file << users.At(i).phone << endl;
		file << users.At(i).password << endl;
	}
	file.close();
}

// Timing
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

// Select with ID
user SelectUserWithID(string table , int id) {
	/*ifstream file;
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

		if(temp.id ==id)
			users.Append(temp);
		else
			continue;
	}
	file.close();*/
}

// Select with String 
LinkedList<user> SelectUserWithWord(string table, string word) {

	LinkedList<user> users;
	user temp;
	/*if (temp.name == word || temp.email == word || temp.phone == word) {
		users.Append(temp);
	else
		continue;
		*/
}

// 34Mawy
user login(string email,string password) {
	
}

// 
string toLowerCase(string word) {
	for (int i = 0; i < word.length(); i++) {
		// code
	}
	return word;
}

// Validation email
// asdasdasdad@sadasd.com
bool isEmail(string email) {
	for (int i = 0; i < email.length(); i++) {
		if (email[i] == '@') {
			return true;
		}
	}
	return false;
}

// validation phone
bool isPhone(string phone) {
	for (int i = 0; i < phone.length(); i++) {
		// code
	}
	return false;
}

// validation password
bool isPassword(string password) {
	for (int i = 0; i < password.length(); i++) {
		// code
	}
	return false;
}

