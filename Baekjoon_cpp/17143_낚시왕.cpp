#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int map[102][102];
int tmpMap[102][102];
int R, C, M;
int ny[5] = { 0, -1, +1, 0, 0 };
int nx[5] = { 0, 0, 0, +1, -1 };
struct SHARK {
	int y, x, spd, dir, size;
};
int main(void) {
	cin >> R >> C >> M;
	SHARK sh;
	vector<SHARK> shark;
	for (int i = 0; i < M; i++) {
		cin >> sh.y >> sh.x >> sh.spd >> sh.dir >> sh.size;
		map[sh.y][sh.x] = i + 1;
		shark.push_back(sh);
	}
	int fishMan = 0;
	int answer = 0;
	while (++fishMan <= C) {
		memset(tmpMap, 0, sizeof(tmpMap));
		//cout << "�׽�Ʈ ��� // �ʱ� map \n";
		//for (int i = 1; i <= R; i++) {
		//	for (int j = 1; j <= C; j++) {
		//		cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		// ���ÿ� ����
		for (int i = 1; i <= R; i++) {
			if (map[i][fishMan] == 0) continue;
			map[i][fishMan] = 0;
			break;
		}

		//cout << "�׽�Ʈ ��� // ���� �� \n";
		//for (int k = 1; k <= R; k++) {
		//	for (int j = 1; j <= C; j++) {
		//		cout << map[k][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		for (int i = 0; i < M; i++) {
			if (shark[i].size == 0) continue; // ������ ���� ��� Ž�� ����
			if (map[shark[i].y][shark[i].x] == 0) { // �̹��� ���� ��� ����
				answer += shark[i].size;
				shark[i].size = 0;
				continue;
			}

			int tmpSpd = shark[i].spd;
			while (tmpSpd > 0) {
				if (shark[i].dir == 1) { // ��
					shark[i].y -= tmpSpd;
					if (shark[i].y < 1) {
						tmpSpd = abs(shark[i].y - 1);
						shark[i].y = 1;
						shark[i].dir = 2;
					}
					else tmpSpd = 0;
				}
				else if (shark[i].dir == 2) { // �Ʒ�
					shark[i].y += tmpSpd;
					if (shark[i].y > R) {
						tmpSpd = abs(shark[i].y - R);
						shark[i].y = R;
						shark[i].dir = 1;
					}
					else tmpSpd = 0;
				}
				else if (shark[i].dir == 3) { // ������
					shark[i].x += tmpSpd;
					if (shark[i].x > C) {
						tmpSpd = abs(shark[i].x - C);
						shark[i].x = C;
						shark[i].dir = 4;
					}
					else tmpSpd = 0;
				}
				else if (shark[i].dir == 4) { // ����
					shark[i].x -= tmpSpd;
					if (shark[i].x < 1) {
						tmpSpd = abs(shark[i].x - 1);
						shark[i].x = 1;
						shark[i].dir = 3;
					}
					else tmpSpd = 0;
				}
			}
			if (tmpMap[shark[i].y][shark[i].x] == 0) {
				tmpMap[shark[i].y][shark[i].x] = i + 1;
			}
			else { // �̹� �� ���� ���
				if (shark[tmpMap[shark[i].y][shark[i].x] - 1].size < shark[i].size) { // ���� ���� ��� �Ա�
					shark[tmpMap[shark[i].y][shark[i].x] - 1].size = 0;
					tmpMap[shark[i].y][shark[i].x] = i + 1;
				}
				else { // ū ����� ��� ��Ƹ���
					shark[i].size = 0;
				}
			}
		}
		for (int k = 0; k <= R; k++) {
			for (int j = 0; j <= C; j++) {
				map[k][j] = tmpMap[k][j];
			}
		}

		//cout << "�׽�Ʈ ��� // �̵� �� \n";
		//for (int i = 1; i <= R; i++) {
		//	for (int j = 1; j <= C; j++) {
		//		cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}

	cout << answer;
}