#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, s, count = 0;
	cin >> n >> s;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) {
				sum += num[j];
			}
		if (sum == s)
			count++;
	}
	cout << count << "\n";
	return 0;
}