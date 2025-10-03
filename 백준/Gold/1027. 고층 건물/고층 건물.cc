#include <iostream>
#include <algorithm>

using namespace std;

int height[50];
int cnt[50];
int n;

void canSee(int a, int b) {
	double diff = double(height[b] - height[a]) / double(b - a);
	for (int i = a+1; i < b; i++) {
		double stand = height[a] + diff * (i - a);
		if ((double)height[i] >= stand)
			return;
	}
	cnt[a]++;
	cnt[b]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height[i];
		cnt[i] = 0;
	}
	
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n; j++)
			canSee(i, j);
	int maxH = *max_element(cnt, cnt+n);
	cout << maxH << "\n";
}