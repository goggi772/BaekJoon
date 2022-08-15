#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, N, result = 0;
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		int t;
		cin >> t;
		A.push_back(t);
	}
	long long max = *max_element(A.begin(), A.end());
	long long first = 0, end = max;

	while (max != first) {
		int sum = 0;
		for (int j = 0; j < K; j++) sum += A[j] / max;
		if (sum >= N) {
			result = max;
			first = max;
		}
		else if (sum < N) end = max;
		max = (first + end) / 2;
	}
	cout << result;
}
