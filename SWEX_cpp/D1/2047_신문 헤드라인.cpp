#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
		printf("%c", str[i]);
	}
}
