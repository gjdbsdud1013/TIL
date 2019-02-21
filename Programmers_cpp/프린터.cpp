#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
	queue<pair<int, int>> print;
	priority_queue<int> que;
	for (int i = 0; i < priorities.size(); i++) { // ������ ť, �켱���� ť�� �Է¹ޱ�
		print.push(make_pair(i, priorities[i]));
		que.push(priorities[i]);
	}
	for (int i = 1; i <= priorities.size(); i++) {
		if (print.front().second == que.top()) { // �ش� ������ �켱���� �ֻ����� ��� ���
			if (print.front().first == location) return i; // ���� �μ� ��û�� ������ ��� ����
			que.pop();
			print.pop();
		}
		else { // �ش� ������ �켱���� �ֻ����� �ƴ� ��� ť�� �� �ڷ� ����
			print.push(print.front());
			print.pop();
			i--;
		}
	}
}

// ��� �׽�Ʈ�� ���� �ڵ�
int main(void) {
	int answer = solution({ 2,1,3,2 }, 2);
	cout << answer;
}
