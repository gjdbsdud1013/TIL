#include <bits/stdc++.h>
using namespace std;

struct SHARK {
	int y, x, time;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int sea[20][20];
SHARK shark;
int N, shark_eat, shark_size;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> sea[y][x];
			if (sea[y][x] == 9) {
				shark.y = y, shark.x = x, shark.time = 0;
				shark_size = 2, shark_eat = 0;
				sea[y][x] = 0;
			}
		}
	}
	bool is_update = true;
	while (is_update) {
		is_update = false;
		queue<SHARK> q;
		int visit[20][20] = { false, };
		visit[shark.y][shark.x] = true;
		q.push(shark);
		
		SHARK candi;
		candi.y = 20, candi.time = -1;
		while (!q.empty()) {
			SHARK cur = q.front(); q.pop();
			if (candi.time != -1 && candi.time < cur.time) { // ������ �ư�, ���� ����� ����⸦ ����� ��� (+1�ʰ� �Ǵ� �������� üũ)
				break;
			}
			if (sea[cur.y][cur.x] < shark_size && sea[cur.y][cur.x] != 0) { // ����⸦ ���� �� ����
				is_update = true;
				if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)) { // �Ÿ��� ���� ������� ��� y, x üũ
					candi = cur;
				}
			}
			for (int i = 0; i < 4; i++) {
				SHARK next;
				next.y = cur.y + dy[i];
				next.x = cur.x + dx[i];
				next.time = cur.time + 1;
				if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) continue;
				if (visit[next.y][next.x] || sea[next.y][next.x] > shark_size) continue;
				visit[next.y][next.x] = true;
				q.push(next);
			}
		}
		if (is_update == true) { // �Ʊ� �� ����⸦ �Ծ��� ���
			shark = candi;
			shark_eat += 1;
			if (shark_eat == shark_size) {
				shark_size += 1;
				shark_eat = 0;
			}
			sea[shark.y][shark.x] = 0;
		}
	}
	cout << shark.time;
}