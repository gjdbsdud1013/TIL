#include <bits/stdc++.h>
using namespace std;

struct POSI {
	int y, x;
};

int N, M, input, answer;
vector<POSI> shop, home, pick;

void dfs(int pos) {
	if (pick.size() == M) { // ���� ���� �Ϸ� ���� ���
		int tmp = 0;
		for (int i = 0; i < home.size(); ++i) { // ���� �� ��
			int minDis = 1000000;
			for (int j = 0; j < pick.size(); ++j) { // ���� ġŲ���̶� ���ؼ� ���� ª�� ġŲ������ �Ÿ� ã��
				minDis = min(minDis, abs(home[i].y - pick[j].y) + abs(home[i].x - pick[j].x));
			}
			tmp += minDis;
		}
		if (answer > tmp) {
			answer = tmp;
		}
		return;
	}
	for (int i = pos; i < shop.size(); ++i) { // �ϳ��� �÷����鼭 ����, ���� �Ϸ� �Ŀ��� ���������鼭 pop
		pick.push_back(shop[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	POSI target;
	cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> input;
			if (input == 1) {
				target.y = y, target.x = x;
				home.push_back(target);
			}
			else if (input == 2) {
				target.y = y, target.x = x;
				shop.push_back(target);
			}
		}
	}
	answer = 0x7fffffff;
	dfs(0);
	cout << answer;
	return 0;
}