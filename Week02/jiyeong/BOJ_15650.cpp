//N과 M (2) (실버 3)
#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> permutation;
vector<bool> used;


void dfs(int len) {
	if (len == m) {	
		for (int num : permutation)
			cout << num << " ";
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!used[i]) 	
			if (len == 0 || permutation[len - 1] < i) { //수열이 0개이거나 오름차순을 만족하는 경우
				used[i] = true;
				permutation[len] = i;	
				dfs(len + 1);
				used[i] = false;	
			}
	return;
}
int main (){
	cin >> n >> m;
	permutation = vector<int>(m);	
	used = vector<bool>(n + 1, false);	
	
	dfs(0);

	return 0;
}
