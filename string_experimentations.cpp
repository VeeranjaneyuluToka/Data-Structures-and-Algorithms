#include <bits/stdc++.h>

using namespace std;

void string_operations(){
	string str1("first string");

	string str2(str1);

	string str3(5, '#');

	string str4(str1, 6, 6);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
}

int main(){
	string_operations();
}
