#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b) {
	string tmpAB = a + b, tmpBA = b + a;
	return atoi(tmpAB.c_str()) > atoi(tmpBA.c_str());
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> temp;
	for (int i = 0; i < numbers.size(); i++) {
		temp.emplace_back(to_string(numbers[i]));
	}
	sort(temp.begin(), temp.end(), cmp);
	for (int i = 0; i < temp.size(); i++) { // string���� ��ȯ�� ����� ��
		answer += temp[i];
	}
	if (atoi(answer.c_str()) == 0) return "0"; // ���� 0�̸� 0 ����
	return answer;
}

// ��� �׽�Ʈ�� ���� �ڵ�
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string answer = solution({ 0,0,0,0 });
	cout << answer;
}
