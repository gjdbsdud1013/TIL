//// ���� 2469 �ټ����
//// ���� 2465 �ټ����
//#include <stdio.h>
//#define MAXN 100010
//int N;
//int people[MAXN], trr[MAXN];
//int cnt[MAXN], ans[MAXN];
//int tree[MAXN * 4];
//
//void mergeSort(int *arr, int s, int e) {
//	if (s >= e) return; // base
//	int m = (s + e) / 2; // divide
//	mergeSort(arr, s, m);
//	mergeSort(arr, m + 1, e);
//	int i = s, j = m + 1, k = s; // merge
//	for (k = s; k <= e; k++) {
//		if (j > e) trr[k] = arr[i++];
//		else if (i > m) trr[k] = arr[j++];
//		else if (arr[i] < arr[j]) trr[k] = arr[i++];
//		else trr[k] = arr[j++];
//	}
//	for (i = s; i <= e; i++) { // copy
//		arr[i] = trr[i];
//	}
//}
//
//// ��� Ű�� ������ ���� Ʈ���� ���� (�ʱⰪ�� ��� 1)
//void build(int now, int s, int e) {
//	if (s == e) {
//		tree[now] = 1;
//		return;
//	}
//	int m = (s + e) / 2;
//	build(now * 2, s, m);
//	build(now * 2 + 1, m + 1, e);
//	tree[now] = tree[now * 2] + tree[now * 2 + 1]; // ������
//}
//
//// �ڽź��� ���� �л� ������ ��ȿ�� Ű�� ���ϰ�
//// Ʈ������ ����
//void update(int now, int s, int e, int c, int idx) {
//	tree[now]--;
//	if (s >= e) { // �ܸ� ���
//		ans[idx] = people[s];
//		return;
//	}
//	int lch = now * 2, rch = now * 2 + 1, m = (s + e) / 2;
//	if (tree[lch] >= c) update(lch, s, m, c, idx);
//	else update(rch, m + 1, e, c - tree[lch], idx);
//}
//
//// �� ��ġ�� ����� �ڽ��� �ڿ� �ִ� ������� Ű�� �����ϰ�
//// ������ �߿��� ���� S�� �ش� ��ġ + 1��° Ű�̴�.
//int main() {
//	int i;
//	scanf("%d", &N);
//	for (i = 1; i <= N; i++) scanf("%d", &people[i]);
//	for (i = 1; i <= N; i++) scanf("%d", &cnt[i]);
//	mergeSort(people, 1, N);
//	build(1, 1, N);
//	for (i = N; i > 0; i--) {
//		update(1, 1, N, cnt[i] + 1, i);
//	}
//	for (i = 1; i <= N; i++) printf("%d\n", ans[i]);
//	return 0;
//}