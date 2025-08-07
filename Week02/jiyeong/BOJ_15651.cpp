//N과 M (3) (실버 3)
#include <iostream>

using namespace std;

int n, m;

int permutation[7];		//시간 초과 때문에 벡터 대신 배열 사용...

void dfs(int len) {
	if (len == m) {
		for (int i = 0 ; i < len ; i++)
			cout << permutation[i] << " ";
		cout << '\n';	//시간 초과 땜에 endl 대신 \n 사용
		return;
	}
	for (int i = 1; i <= n; i++) {
		permutation[len] = i;
		dfs(len + 1);
	}
}

int main() {
	cin >> n >> m;

	dfs(0);

	return 0;
}

