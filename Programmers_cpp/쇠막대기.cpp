#include <bits/stdc++.h>
using namespace std;

int solution(string arrangement) {
	int answer = 0, check = 0;
	bool raser = false;
	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(') {
			check++;
		}
		else {
			if (arrangement[i - 1] == '(') {
				check--;
				answer += check;
			}
			else {
				check--;
				answer++;
			}
		}
	}
	return answer;
}

// ��� �׽�Ʈ�� ���� �ڵ�
int main(void) {
	int answer = solution("()(((()())(())()))(())");
	cout << answer;
}