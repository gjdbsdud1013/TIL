#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string A, B;
	cin >> A >> B;
	int answer = 50;
	for (int i = 0; i <= B.size() - A.size(); i++) { // �������� Ʋ�� ���ڿ��� üũ
		int Aj = 0;
		int tmp = 0;
		for (int j = i; j < i + A.size(); j++) {
			if (A[Aj] != B[j]) tmp += 1;
			Aj += 1;
		}
		if (tmp < answer) answer = tmp;
	}
	cout << answer;
}