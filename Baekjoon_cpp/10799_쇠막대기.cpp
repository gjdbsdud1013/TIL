#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string input;
	cin >> input;
	int answer = 0, check = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			check++; // ���� ����ִ� �踷��� �� üũ
		}
		else {
			if (input[i - 1] == '(') { // () �������� ���
				check--;
				answer += check; // �߸� �踷��� ����ŭ ������
			}
			else { // �ϳ��� �踷��Ⱑ ���� ���
				check--;
				answer++;
			}
		}
	}
	cout << answer;
}