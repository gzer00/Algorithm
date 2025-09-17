#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> p(n);	//왼쪽에 키가 큰 사람이 몇명 있는지
	vector<int> ans = { n };
	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = n - 2; i >= 0; i--)
		ans.insert(ans.begin() + p[i], 1, i+1);

	for (int per : ans)
		cout << per << " ";
	cout << "\n";
}