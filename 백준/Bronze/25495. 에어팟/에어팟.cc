#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, link = 0, result = 0, cnt = 1;
	cin >> N;

	while (N--){
		int A;
		cin >> A;

		if (link != A) {
			cnt = 1;
			link = A;
		}
		cnt *= 2;
		result += cnt;

		if (result >= 100) {
			cnt = 1;
			result = 0;
		}
	}
	cout << result;
}
