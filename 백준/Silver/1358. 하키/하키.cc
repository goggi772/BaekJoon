#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int W, H, X, Y, P, result = 0;
	cin >> W >> H >> X >> Y >> P;

	while (P--){
		int x, y;
		cin >> x >> y;

		if (pow(x - X, 2) + pow(y - (Y + H / 2), 2) <= pow(H / 2, 2)) result++;
		else if (X <= x && x <= X + W && Y <= y && y <= Y + H) result++;
		else if (pow(x - (X + W), 2) + pow(y - (Y + H / 2), 2) <= pow(H / 2, 2)) result++;
	}
	cout << result;
}