#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		A.push_back(t);
	}
	sort(A.begin(), A.end());
	cin >> M;
	
	while (M--) {
		int m;
		cin >> m;
		cout << binary_search(A.begin(), A.end(), m) << "\n";
	}
}
