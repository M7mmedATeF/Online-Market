#include <iostream>
#include <fstream>
#include <string>
#include <regex>

// Classes
#include "user.cpp"
#include "LinkedList.cpp"
#include "product.cpp"
using namespace std;


// Functions
void selectUser(string table, LinkedList<user>& users);
void saveUsersData(string table, LinkedList<user>& users);
user SelectUserWithID(string table, int id);
bool isName(string name);
bool isPhone(string phone);
bool isPassword(string password);
bool isEmail(string email);
void separate(string list, LinkedList<int>& IDs);
void carteData(string IDstring, LinkedList<product>& products);
product selectProduct(int id);

int main() {

	
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

void separate(string list, LinkedList<int>& IDs) {
	string productID = "";
	for (int i = 0; i < list.length(); i++) {
		if (list[i] == ',') {
			IDs.Append(stoi(productID));
			productID = "";
		}
		else {
			productID += list[i];
		}
	}
}
// Ids => 1,2,3,
void carteData(string IDstring , LinkedList<product>& products) {
	LinkedList<int> IDs;
	separate(IDstring,IDs);
	for (int i = 0; i < IDs.Length(); i++)
	{
		products.Append(selectProduct(IDs.At(i)));
	}

}
product selectProduct(int id) {
	ifstream file;
	file.open("products.txt");
	product temp;
	string data = "";
	while (!file.eof()) {
		// ID
		getline(file, data);
		temp.id = stoi(data);
		
		//company
		getline(file, temp.company);
		
		//name
		getline(file, temp.name);
		
		//quantity
		getline(file, data);
		temp.quantity = stoi(data);
		
		//price
		getline(file, data);
		temp.price = stod(data);
		
		//seller-ID
		getline(file, data);
		temp.seller_id = stoi(data);
		
		//category
		getline(file, temp.category);
		
		//rate
		getline(file, data);
		temp.rate = stof(data);
		if (temp.id == id) {
			file.close();
			break;
		}

	}
	file.close();
	return temp;
}

// Nariman
// Validation email
bool isEmail(string email) {
	//[[:w:]] word character: digit, number or under score
	const regex pattern("[[:w:]]+@[[:w:]]+\.com");

	return regex_match(email, pattern);
}

// Mayar
// validation name
bool isName(string name) {
	if (name.length() < 3)
		return false;
	else
		return true;
}
// validation phone
bool isPhone(string phone)
{
	bool m = true;
	bool n = false;

	for (int i = 0; i < phone.length(); i++) {
		if (isdigit(phone[i]) == 0) {
			m = false;
			break;
		}
	}

	if (phone.length() >= 11 && phone.length() <= 13)
		n = true;

	return (n && m);

}// validation password
bool isPassword(string password) {
	if (password.length() < 5)
		return false;
	else
		return true;
}