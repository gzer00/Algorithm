#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;
	int ch[26] = { 0 };
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			ch[str[i] - 'a']++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ch[str[i] - 'A']++;
	}
	int maxC = *max_element(ch, ch+26);
	int ind = -1;
	for (int i = 0; i < 26; i++) {
		if (maxC == ch[i]) {
			if (ind != -1) {
				cout << "?\n";
				return 0;
			}
			else
				ind = i;
		}
	}
	char ans = 'A' + ind;
	cout << ans << "\n";
}