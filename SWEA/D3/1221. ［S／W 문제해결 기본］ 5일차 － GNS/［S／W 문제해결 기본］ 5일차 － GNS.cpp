#include <iostream>
#include <string>

using namespace std;

string strList[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV","SIX", "SVN", "EGT", "NIN" };

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
		int n;
		cin >> num;
		cin >> n;
		int numCount[10] = { 0 };
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (num == "ZRO")
				numCount[0]++;
			else if (num == "ONE")
				numCount[1]++;
			else if (num == "TWO")
				numCount[2]++;
			else if (num == "THR")
				numCount[3]++;
			else if (num == "FOR")
				numCount[4]++;
			else if (num == "FIV")
				numCount[5]++;
			else if (num == "SIX")
				numCount[6]++;
			else if (num == "SVN")
				numCount[7]++;
			else if (num == "EGT")
				numCount[8]++;
			else if (num == "NIN")
				numCount[9]++;
		}
		cout << "#" << test_case << endl;
		for (int i = 0; i < 10; i++)
			for (int j = 0 ; j < numCount[i] ; j++)
				cout << strList[i] << " ";
		cout << endl;
	}
	return 0;
}