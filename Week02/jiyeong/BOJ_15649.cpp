//N과 M (1) (실버 3)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<int> permutation;
vector<bool> used;


void dfs(int len) {
	if (len == m) {	//수열 다 구한 후 출력
		for (int num : permutation)
			cout << num << " ";
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!used[i]) {	//수열에 포함되지 않은 경우
			used[i] = true;
			permutation[len] = i;	//추가
			dfs(len + 1);
			used[i] = false;	//다시 제거 (백트래킹)
		}
}
int main (){
	cin >> n >> m;	//n까지의 수 중 m개의 수열
	permutation = vector<int>(m);	//수열 벡터
	used = vector<bool>(n + 1, false);	//중복 허용하지 않기 위해
	
	dfs(0);

	return 0;
}
