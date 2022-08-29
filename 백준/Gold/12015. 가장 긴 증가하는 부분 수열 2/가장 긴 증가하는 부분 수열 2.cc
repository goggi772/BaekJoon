#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	while (N--) {
		int A;
		cin >> A;

		int index = lower_bound(arr.begin(), arr.end(), A) - arr.begin();
		if (arr.size() == index) arr.push_back(A);
		else arr[index] = A;
	}
	cout << arr.size() - 1;
	
}
