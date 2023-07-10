#include <iostream>
#include <cassert>

using namespace std;

#include"Dictionary.h"

int main(){
	Dictionary<int, string> dict;
	dict.add(1, "Apple_1");
	dict.add(2, "Apple_2");
	dict.add(3, "Apple_3");
	dict.add(4, "Apple_4");
	cout << dict[3] << endl;

	dict[3] = "Banana";
	cout << dict[3] << endl;

	dict.remove(2);

	cout << dict.item(4)<< endl;
	cout << dict.capacity() << endl;
	dict.items_();


	/*int* keys = dict.keys();
	cout << "Keys in the dictionary: ";
	for (size_t i = 0; i < dict.count(); i++) {
		cout << keys[i] << "  ";
	}
	cout << endl << endl;
	delete[] keys;

	string* values = dict.values();
	cout << "Values in the dictionary: ";
	for (size_t i = 0; i < dict.count(); i++) {
		cout << values[i] << "  ";
	}
	cout << endl << endl;
	delete[] values;*/

	/*dict.clear();
	cout << dict.containsValue("Apple") << endl;*/

	/*Dictionary<int, string> copied = dict.copy();
	copied.add(5, "Apple_5");
	copied.remove(3);

	copied.items_();
	cout << endl;

	copied.update(2, "Lemon");
	copied.update(1, "Kiwis");
	copied.update(3, "Banana");
	copied.update(6, "Apple_6");

	copied.items_();*/


	return 0;
}
