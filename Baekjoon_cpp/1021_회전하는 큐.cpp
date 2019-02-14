#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
	deque<int> dq;
	int N, M, answer = 0;
	deque<int>::iterator it;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) dq.push_back(i);
	for (int i = 0; i < M; i++) {
		int tmp, index = 1;
		scanf("%d", &tmp);

		if (tmp == dq.front()) dq.pop_front();
		else {
			for (it = dq.begin(); it < dq.end(); it++) { // ���Ϸ��� ���� �ε��� ���ϱ�
				if (*it == tmp) break;
				index++;
			}
			int front = index - 1; // �������� �����ϴ� Ƚ��
			int back = dq.size() - index + 1; // ���������� �����ϴ� Ƚ��
			if (front < back) { // ���Ϸ��� ���� front�� �� ������ ���� ���
				for (int j = 0; j < front; j++) {
					dq.push_back(dq.front());
					dq.pop_front();
					answer++;
				}
				dq.pop_front();
			}
			else { // ���Ϸ��� ���� back�� �� ������ ���� ���
				for (int j = 0; j < back; j++) {
					dq.push_front(dq.back());
					dq.pop_back();
					answer++;
				}
				dq.pop_front();
			}
		}
	}
	cout << answer;
}
