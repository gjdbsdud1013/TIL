#include <bits/stdc++.h>
using namespace std;
int student[100001];
vector<int> check;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		check.clear();
		check.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
			if (i == student[i]) {
				check[i] = -1;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			if (check[i] != 0) continue;
			check[i] = i; // ���� ��� üũ
			int cur = i; // Ž�� ���
			while (true) {
				cur = student[cur];
				if (check[cur] == -1) break;
				if (check[cur] == i) { // ���� ���� cycle��
					check[cur] = -1;
					int tmp = student[cur];
					while (tmp != cur) { // �ش� cycle ��� -1�� üũ
						check[tmp] = -1;
						tmp = student[tmp];
					}
					break;
				}
				if (check[cur] == 0) { // ���۳�� �Է�
					check[cur] = i;
					continue;
				}
				else break;
			}
		}

		int answer = n;
		for (int i = 1; i <= n; i++) {
			if (check[i] == -1) answer -= 1;
		}
		cout << answer << "\n";
	}
}