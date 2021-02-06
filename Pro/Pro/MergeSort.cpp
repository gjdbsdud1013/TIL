#if 1

// �ð����⵵ : O(nlogn)
#include <stdio.h>

int N, arr[1000001];
int *arr2;

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int left = start, right = mid + 1, i = start;
	while (left <= mid && right <= end) {
		if (arr[left] <= arr[right])
			arr2[i++] = arr[left++];
		else
			arr2[i++] = arr[right++];
	}

	// ���� ������ ���� ��� (������ ������ �� ó����)
	while (left <= mid) arr2[i++] = arr[left++];
	// ������ ������ ���� ��� (���� ������ �� ó����)
	while (right <= mid) arr2[i++] = arr[right++];
	// ����
	for (int i = start; i <= end; i++) arr[i] = arr2[i];
}

void mergeSort(int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	merge(start, end);
}

int main() {

	scanf("%d", &N);
	arr2 = new int[N];
	for (int i = 0; i<N; i++) scanf("%d", &arr[i]);
	mergeSort(0, N - 1);
	for (int i = 0; i<N; i++) printf("%d\n", arr[i]);
	return 0;
}

#endif