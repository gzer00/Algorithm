#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n, m;	//기타 수, 곡 수
	cin >> n >> m;
	vector<unsigned long long> song(n, 0);	//연주 가능한 곡 비트
	for (int i = 0; i < n; i++) {
		string guitar;
		char play;
		cin >> guitar;
		for (int j = m-1; j >= 0 ; j--) {
			cin >> play;
			if (play == 'Y')
				song[i] |= (1ULL << j);
		}
	}
	int maxS = 0, maxC = 0;
	for (int i = 1; i <= n; i++) {
		vector<bool> selected(n - i, false);
		selected.insert(selected.end(), i, true);
		do {
			unsigned long long goal = 0;
			for (int i = 0; i < n; i++) {
				if (selected[i])
					goal |= song[i];
			}
			if (goal == (1ULL << m) - 1) {
				cout << i << endl;
				return 0;
			}
			int goalB = 0;
			for (int i =  0; i < m; i++) {
				if (goal & (1ULL << i))
					goalB++;
			}
			if (goalB > maxS) {
				maxS = goalB;
				maxC = i;
			}
		} while (next_permutation(selected.begin(), selected.end()));
	}
	if (maxS == 0)
		cout << "-1\n";
	else
		cout << maxC << endl;
}