#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include<windows.h>

// Classes
#include "user.cpp"
#include "LinkedList.cpp"
#include "product.cpp"
using namespace std;


// Functions
void selectUser(string table, LinkedList<user>& users, LinkedList<product>& products);
void saveUsersData(string table, LinkedList<user>& users);
user SelectUserWithID(string table, int id);
bool isName(string name);
bool isPhone(string phone);
bool isPassword(string password);
bool isEmail(string email);
LinkedList<int> separate(string list);
LinkedList<product> carteData(string IDstring, LinkedList<product>& products);
void selectAllProducts(LinkedList<product>& products);
user login(string email, string password, LinkedList<user>& users);

int main() {

	LinkedList<product> products;
	selectAllProducts(products);
	LinkedList<user> users;
	selectUser("users.txt", users , products);
	
	/*user u = login("mo25atef@gmail.com", "37329812", users);
	cout << u.name;*/

	/*for (int i = 0; i < users.Length(); i++) {
		cout << "*****************************\n";
		cout << "Id: " << users.At(i).id << endl;
		cout << "Name: " << users.At(i).name << endl;
		cout << "Email: " << users.At(i).email << endl;
		cout << "Is Seller: " << users.At(i).is_seller << endl;
		cout << "Phone: " << users.At(i).phone << endl;
		cout << "password: " << users.At(i).password << endl;
		cout << "carte: " << endl;
		for (int j = 0; j < users.At(i).carte.Length(); j++) {
			cout << "\t ID: " << users.At(i).carte.At(j).id << endl;
			cout << "\t name: " << users.At(i).carte.At(j).name << endl;
			cout << "\t company: " << users.At(i).carte.At(j).company << endl;
			cout << "\t quantity: " << users.At(i).carte.At(j).quantity << endl;
			cout << "\t price: " << users.At(i).carte.At(j).price << endl;
			cout << "\t seller_id: " << users.At(i).carte.At(j).seller_id << endl;
			cout << "\t category: " << users.At(i).carte.At(j).category << endl;
			cout << "\t rate: " << users.At(i).carte.At(j).rate << endl;
		}
	}*/

	for (int i = 0; i < products.Length(); i++) {
		cout << products.At(i).id << " " << products.At(i).name << endl;
	}
	
	return 0;
}

user login(string email, string password, LinkedList<user>& users) 
{
	for (int i = 0; i < users.Length(); i++) {
		if(email == users.At(i).email && password == users.At(i).password)
		{
			return users.At(i);
		}
	}

	return user();
	
}

void selectUser(string table, LinkedList<user>& users , LinkedList<product>& products) {
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
		cout << data << endl;
		temp.is_seller = stoi(data);

		// phone
		getline(file, temp.phone);

		// password
		getline(file, temp.password);
		
		// Carte
		getline(file, data);
		temp.carte = carteData(data , products);

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
		string carte;
		for (int j = 0; j < users.At(i).carte.Length(); j++) {
			carte += "" + users.At(i).carte.At(j).id + ',';
		}
	}
	file.close();
}

// Mazen
// Ids => 1,2,3,
LinkedList<int> separate(string list) {
	string productID = "";
	LinkedList<int> IDs;
	for (int i = 0; i < list.length(); i++) {
		if (list[i] == ',') {
			IDs.Append(stoi(productID));
			productID = "";
		}
		else {
			productID += list[i];
		}
	}
	return IDs;
}

LinkedList<product> carteData(string IDstring, LinkedList<product>& products) {
	LinkedList<int> IDs = separate(IDstring);
	LinkedList<product> returned;

	for (int i = 0; i < products.Length(); i++)
	{
		for (int j = 0; j < IDs.Length(); i++)
		{
			if (IDs.At(j) == products.At(i).id) {
				returned.Append(products.At(i));
			}
		}
	}

	return returned;
}

void selectAllProducts(LinkedList<product>& products) {
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

		products.Append(temp);
	}
	file.close();
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