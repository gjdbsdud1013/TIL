#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void DFS(vector<int>numbers, int index, int sum, int target) {
	if (index == numbers.size()) {
		if (target == sum) answer++;
		return;
	}
		DFS(numbers, index + 1, sum - numbers[index], target);
		DFS(numbers, index + 1, sum + numbers[index], target);
}

int solution(vector<int> numbers, int target) {
	DFS(numbers, 0, 0, target);
	return answer;
}

// ��� �׽�Ʈ�� ���� �ڵ�
int main(void) {
	cout << solution({ 1, 1, 1, 1, 1}, 3);

	//vector<int> answer = solution( 8, 1 );
	//for (int i = 0; i < answer.size(); i++) {
	//	cout << answer[i];
	//}
}