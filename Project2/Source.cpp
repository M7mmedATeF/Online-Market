#include <iostream>
#include <string>
#include <list>

// Classes
#include "user.h"
#include "LinkedList.h"
using namespace std;

int main() {
	LinkedList<int> L;
	L.Append(9);
	L.Append(10);
	L.Append(11);
	L.InsertAt(1, 100);
	L.DeleteAt(3);

	for (int i = 0; i < L.Length(); i++)
		cout << L.At(i) << endl;
	return 0;
}
