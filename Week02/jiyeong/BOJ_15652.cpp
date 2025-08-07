//N과 M (4) (실버 3)
#include <iostream>

using namespace std;

int n, m;

int permutation[8];

void dfs(int len) {
	if (len == m) {
		for (int i = 0 ; i < len ; i++)
			cout << permutation[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (len == 0 || permutation[len - 1] <= i) {
			permutation[len] = i;
			dfs(len + 1);
		}
	}
}

int main() {
	cin >> n >> m;

	dfs(0);

	return 0;
}

