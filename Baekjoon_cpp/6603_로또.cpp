#include <bits/stdc++.h>
using namespace std;
int t;

void combination(vector<int> S, vector<int> ansArr, int r, int index, int target) {
	if (r == 0) { // 6�� ���� �������� ��� ���
		for (int i = 0; i < 6; i++) cout << S[ansArr[i]] << " ";
		cout << "\n";
		return;
	}
	else if (t - target < r) return; // �������� �� �����ص� 6���� �ȵ� ��� ����
	ansArr[index] = target;
	combination(S, ansArr, r - 1, index + 1, target + 1); // ���� �Ǿ��� ���
	combination(S, ansArr, r, index, target + 1); // ���� �ȵǾ��� ���
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		int r = 6;
		cin >> t;
		if (t == 0) break;
		vector<int> S(t);
		vector<int> ansArr(t);
		for (int i = 0; i < t; i++) cin >> S[i];
		combination(S, ansArr, r, 0, 0);
		cout << "\n";
	}
}