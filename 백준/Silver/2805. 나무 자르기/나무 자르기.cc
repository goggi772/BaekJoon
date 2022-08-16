#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, result = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		A.push_back(t);
	}
	long long max = *max_element(A.begin(), A.end());
	long long first = 0, end = max;

	while (max != first) {
		long long sum = 0;
		for (int j = 0; j < N; j++) {
			if (A[j] > max) sum += A[j] - max;
		}
		if (sum >= M) {
			result = max;
			first = max;
		}
		else if (sum < M) end = max;
		max = (first + end) / 2;
	}
	cout << result;
}
