//// ���� 1726 : ������ �ִ밪1
//
//#include <stdio.h>
//#define MAXN 50010
//int N, Q;
//int A[MAXN];
//// ����Ʈ���� ��üũ��� N * 4��
//int tree[MAXN * 4];
//
//inline int Max(int a, int b) { return a > b ? a : b; }
//
//// build (Ʈ����� ��ȣ, ���� ����, ���� ��)
//void build(int now, int s, int e) {
//	if (s == e) {			// s == e�� ��� : base condition
//		tree[now] = A[s];
//		return;
//	}
//	int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
//	build(lch, s, m);		// ���� ���� Ʈ�� �����
//	build(rch, m + 1, e);	// ������ ���� Ʈ�� �����
//	tree[now] = Max(tree[lch], tree[rch]);	// ���� ��� ���� ������Ʈ
//}
//
//void buildTree() {
//	build(1, 1, N);
//}
//
//// update(Ʈ����� ��ȣ, ���� ����, ���� ��, ��ǥ ��ġ, ������Ʈ�� ��)
//void update(int now, int s, int e, int tgIdx, int val) {
//	if (s == e) { // s == e == tgIdx�� ���
//		tree[now] = val;
//		return;
//	}
//	int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
//	if (tgIdx <= m) update(lch, s, m, tgIdx, val);	// ã�� ��ġ�� ����
//	else update(rch, m + 1, e, tgIdx, val);			// ã�� ��ġ�� ������
//	tree[now] = Max(tree[lch], tree[rch]);			// ���� ����� ������ �ִ밪 ������Ʈ
//}
//
//// query (Ʈ����� ��ȣ, ���� ����, ���� ��, ���Ǳ��� ����, ���Ǳ��� ��)
//int query(int now, int s, int e, int fs, int fe) {
//	if (e < fs || fe < s) return 0;				// Ʈ�� ������ ���� ������ ���� X
//	if (fs <= s && e <= fe) return tree[now];	// Ʈ�� ������ ���� ������ ���� O
//	// �Ϻδ� ��ġ�� �Ϻδ� ��ġ�� ����
//	int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
//	int left = query(lch, s, m, fs, fe);
//	int right = query(rch, m + 1, e, fs, fe);
//	return Max(left, right);
//}
//
//int main(void) {
//	scanf("%d %d", &N, &Q);
//	// N���� ������ �̷���� ���� �Է� (1 <= N <= 50000)
//	for (int i = 1; i <= N; i++) {
//		scanf("%d", A + i);
//	}
//	buildTree();
//	// Q���� ���ǿ� ���� �� ���ؼ� ��� (1 <= Q <= 200000)
//	int a, b;
//	for (int i = 0; i < Q; i++) {
//		scanf("%d %d", &a, &b);
//		// ������ ������ ���ӵ� ������ �ִ밪 ���ؼ� ��
//		printf("%d\n", query(1, 1, N, a, b));
//	}
//}