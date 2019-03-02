#include <bits/stdc++.h>
using namespace std;

int strike(int num, int check) { // ��Ʈ����ũ ���� üũ
	int cnt = 0;
	string strNum = to_string(num);
	string strChk = to_string(check);
	for (int i = 0; i < 3; i++) {
		if (strNum[i] == strChk[i]) cnt++;
	}
	return cnt;
}

int ball(int num, int check) { // �� ���� üũ
	int cnt = 0;
	string strNum = to_string(num);
	string strChk = to_string(check);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j && strNum[i] == strChk[j]) cnt++;
		}
	}
	return cnt;
}

int solution(vector<vector<int>> baseball) {
	vector<bool> check(988, 0);
	for (int i = 123; i < check.size(); i++) { // ���� �ٸ� 1~9�� �̷���� ���ڸ� ���� ����
		int a, b, c;
		tie(a, b, c) = make_tuple(i / 100, i % 100 / 10, i % 100 % 10);
		if (a != b && a != c && b != c && a != 0 && b != 0 && c != 0) check[i] = 1;
	}

	for (int i = 0; i < baseball.size(); i++) {
		for (int j = 123; j < check.size(); j++) {
			if (check[j] == 1 && (baseball[i][1] != strike(j, baseball[i][0]) || baseball[i][2] != ball(j, baseball[i][0]))) {
				// ��Ʈ����ũ, �� ���� �������� üũ ��, �ٸ��� ���信�� ����
				check[j] = 0;
			}
		}
	}

	int answer = 0;
	for (int i = 123; i < check.size(); i++) {
		if (check[i] == 1) answer++;
	}
	return answer;
}

int main(void) {
	cout << solution({ {123, 1, 1},{356, 1, 0},{327, 2, 0},{489, 0, 1} });
}