#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int change, len;
string maxN;
vector<unordered_set<string>> numList;

void dfs(string num, int count) {
	if (count == change) {
		if (maxN < num)
			maxN = num;
		return;
	}
	if (numList[count].find(num) != numList[count].end())
		return;
	numList[count].insert(num);
	for (int i = 0 ; i < num.size() -1 ; i++)
		for (int j = i + 1; j < num.size(); j++) {
			swap(num[i], num[j]);
			dfs(num, count + 1);
			swap(num[i], num[j]);
		}
	
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string num;
		cin >> num >> change;
		numList = vector<unordered_set<string>>(change + 1);
		maxN = "0";
		dfs(num, 0);
		cout << "#" << test_case << " " << maxN << endl;
	}
	return 0;
}