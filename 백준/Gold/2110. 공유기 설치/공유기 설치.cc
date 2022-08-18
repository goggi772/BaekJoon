#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, C, result = 0;
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		A.push_back(t);
	}
	sort(A.begin(), A.end());
	int gap = A.back() - A.front();
	int start = 1, end = gap;
	while (start <= end) {
		gap = (start + end) / 2;
		int count = 1, tmp = A.front();
		for (int i = 1; i < N; i++) {
			if (A[i] - tmp >= gap) {
				count++;
				tmp = A[i];
			}
		}
		if (count < C) end = gap - 1;
		else if (count >= C) {
			start = gap + 1;
			result = gap;
		}
	}
	cout << result;
}
