#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size() - 1; i++) {
		int check = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[i] > prices[j] || j == prices.size() - 1) { // ������ �������� ���
				check++;
				break;
			}
			else check++;
		}
		answer.emplace_back(check);
	}
	return answer;
}

// ��� �׽�Ʈ�� ���� �ڵ�
int main(void) {
	vector<int> answer = solution({498,501,470,489});
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
}
