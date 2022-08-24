#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K, mid, result = 0;
	cin >> N >> K;

	int start = 1, end = K;

	while (start <= end) {
		int cnt = 0;
		mid = (start + end) / 2;
		for (int i = 1; i <= N; i++) cnt += min(N, mid / i);

		if (cnt < K) start = mid + 1;
		else if (cnt >= K) {
			result = mid;
			end = mid - 1;
		}
	}
	cout << result;
}
