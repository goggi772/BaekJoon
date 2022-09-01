#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	while (N--){
		int x;
		cin >> x;

		if (x != 0) {
			arr.push_back(x);
			int i = arr.size() - 1;
			while (i != 0) {
				if (arr[(i - 1) / 2] > arr[i]) swap(arr[(i - 1) / 2], arr[i]);
				else break;
				i = (i - 1) / 2;
			}
		}
		else {
			if (arr.empty()) cout << 0 << "\n";
			else {
				cout << arr.front() << "\n";
				arr[0] = arr.back();
				arr.pop_back();
				int t = 0;
				while (true) {
					int left = t * 2 + 1, right = t * 2 + 2;
					if (left >= arr.size()) break;

					int idx = t;
					if (arr[left] < arr[idx]) idx = left;
					if (right < arr.size() && arr[right] < arr[idx]) idx = right;
					if (idx == t) break;

					swap(arr[idx], arr[t]);
					t = idx;
				}
			}
		}
	}
}
