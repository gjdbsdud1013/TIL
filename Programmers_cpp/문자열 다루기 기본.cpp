#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
	if (s.length() != 4 && s.length() != 6) {
		return false;
	}
	for (int i = 0; i<s.length(); i++){
		if (!(s[i] >= '0' && s[i] <= '9')) {
			return false;
		}
	}
	return true;
}

int main(void) {
	bool answer = solution("1234");

	cout << answer;
  }
}
