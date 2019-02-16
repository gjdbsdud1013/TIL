#include <bits/stdc++.h>
using namespace std;

bool compare(tuple<string, int, int>& a, tuple<string, int, int>& b) {
	// �뷡 ���� ���� ���ٸ�
	if (get<1>(a) == get<1>(b))
		return get<2>(a) < get<2>(b); // �뷡 ������ȣ�� ��������
	return get<1>(a) > get<1>(b); // �뷡 ���ļ��� ��������
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	cin.tie(0);

	map <string, int> genCheck;
	map <int, string, greater<int>> reGenCheck;

	// �帣�� �뷡 ��� �� üũ
	for (int i = 0; i < genres.size(); i++) {
		if (genCheck.find(genres[i]) != genCheck.end()) { // genCheck�� �帣�� ������ ���
			genCheck[genres[i]] += plays[i];
		}
		else { genCheck[genres[i]] = plays[i]; };
	}
	for (auto it = genCheck.begin(); it != genCheck.end(); it++) {
		reGenCheck[it->second] = it->first;
	}

	vector<tuple<string, int, int>> songs;
	for (int i = 0; i < genres.size(); i++) {
		songs.emplace_back(make_tuple(genres[i], plays[i], i));
	}

	// ��� Ƚ��, ���� ��ȣ ������ ����
	sort(songs.begin(), songs.end(), compare);

	// ���� ����� �帣 ������ ����
	for (auto it = reGenCheck.begin(); it != reGenCheck.end(); it++) { // �帣�� ����ŭ �ݺ�
		int temp = 0;
		for (int j = 0; j < songs.size(); j++) {
			if (get<0>(songs[j]) == it->second) {
				answer.emplace_back(get<2>(songs[j]));
				temp++;
			}
			if (temp == 2) break;
		}
	}
	
	return answer;
}

// ��� �׽�Ʈ�� ���� �ڵ�
int main(void) {
	vector<int> answer = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
}