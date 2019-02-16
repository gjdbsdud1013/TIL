#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	map<string, int> check;
	int answer = 1;

	for (int i = 0; i < clothes.size(); i++) {
		if (check.find(clothes[i][1]) != check.end()) { // �ش� ���� ������ �̹� ������ ���
			check[clothes[i][1]]++;
		}
		else {
			check[clothes[i][1]] = 1;
		}
	}
	for (auto it = check.begin(); it != check.end(); it++) {
		answer *= it->second + 1;
	}
	return answer - 1;
}

// ��� �׽�Ʈ�� ���� �ڵ�
int main(void) {
	int answer = solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"}});
	cout << answer;
}