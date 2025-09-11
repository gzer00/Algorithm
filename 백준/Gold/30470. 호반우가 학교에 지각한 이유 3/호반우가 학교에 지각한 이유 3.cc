#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;	//명령어 수
	cin >> n;
	vector<int> tree;	//통나무 합
	for (int i = 0; i < n; i++) {
		int qr, len;
		cin >> qr >> len;
		if (qr == 1) {
			tree.push_back(len);
		}
		else if (qr == 2) {
			if (tree.empty())
				continue;
			int cut = max(tree.back() - len, 0);
			if (cut == 0)		//모든 나무의 길이를 0으로 만들어야할 때
				tree.clear();
			else 
				tree.back() = cut;
		}
	}
	if (tree.empty())	//나무가 0개일 때
		cout << "0\n";
	else if (tree.size() == 1)	//나무의 길이가 1개일 때
		cout << tree[0] << "\n";
	else {
		long long sumT = tree.back();
		for (int i = tree.size() - 2; i >= 0; i--) {
			tree[i] = min(tree[i], tree[i + 1]);
			sumT += tree[i];
		}
		cout << sumT << "\n";
	}
}