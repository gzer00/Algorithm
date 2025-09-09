#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, maxN=0;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (maxN < num[i])
			maxN = num[i];
	}
	vector<pair<int, int>> count(maxN + 1);
	count[0] = { 1, 0 };
	count[1] = { 0, 1 };
	for (int i = 2; i <= maxN; i++) {
		count[i] = { count[i - 2].first + count[i - 1].first, count[i - 2].second + count[i - 1].second };
	}
	for (int i = 0; i < n; i++)
		cout << count[num[i]].first << " " << count[num[i]].second << "\n";
}