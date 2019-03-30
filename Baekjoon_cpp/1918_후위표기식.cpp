#include <bits/stdc++.h>
using namespace std;
int main(void) {
	string num;
	cin >> num;
	queue<char> answer;
	stack<char> stk;
	for (int i = 0; i < num.size(); i++) {
		// ���ĺ��� ��� : que�� �־���
		if (num[i] >= 'A' && num[i] <= 'Z') answer.push(num[i]);
		// (�� ��� : ������ stack�� ����
		else if (num[i] == '(') stk.push(num[i]);
		// )�� ��� : (���� �ִ� ��� ������ pop�ؼ� quq�� �־���
		else if (num[i] == ')') {
			while (stk.top() != '(') {
				answer.push(stk.top());
				stk.pop();
			}
			stk.pop();
		}
		// �������� ��� : stack�� top�� �� �켱������ ���ٸ� �׳� push, �ƴϸ� top�� que�� �Ű���
		else if (num[i] == '+' || num[i] == '-') {
			while (stk.empty() == 0) {
				if (stk.top() == '(') break;
				answer.push(stk.top());
				stk.pop();
			}
			stk.push(num[i]);
		}
		else if (num[i] == '*' || num[i] == '/') {
			while (stk.empty() == 0) {
				if (!(stk.top() == '*' || stk.top() == '/')) break;
				answer.push(stk.top());
				stk.pop();
			}
			stk.push(num[i]);
		}
	}
	while (!stk.empty()) { // ���ÿ� ���� ������ ó��
		answer.push(stk.top());
		stk.pop();
	}
	while (!answer.empty()) {
		cout << answer.front();
		answer.pop();
	}
}