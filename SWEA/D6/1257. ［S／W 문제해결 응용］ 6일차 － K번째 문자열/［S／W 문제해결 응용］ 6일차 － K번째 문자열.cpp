#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int k;
		string word;
		cin >> k >> word;
		unordered_set<string> part;
		for (int i = 1; i <= word.size(); i++) {
			for (int j = 0; j <= word.size() - i; j++)
				part.insert(word.substr(j, i));
		}
		if (part.size() < k) {
			cout << "#" << test_case << " none\n";
			continue;
		};
		vector<string> partV(part.begin(), part.end());
		sort(partV.begin(), partV.end());
		
		cout << "#" << test_case << " " << partV[k-1] << endl;
	}
	return 0;
}