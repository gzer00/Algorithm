#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n;
	cin >> t;
	int method[11];
	method[1] = 1;
	method[2] = 2;
	method[3] = 4;
	for (int i = 4; i <= 10; i++)
		method[i] = method[i - 1] + method[i - 2] + method[i - 3];
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << method[n] << endl;
	}
}