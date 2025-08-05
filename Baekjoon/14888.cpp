//연산자 끼워넣기
//연산자 끼워넣기 (실버 1)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
	int n, ans;  //숫자의 개수와 계산 결과를 저장할 변수
	long int max = numeric_limits<int>::min();
	long int min = numeric_limits<int>::max();
	cin >> n;
	vector<int> number(n), symbol;  //숫자를 저장할 벡터와 연산자를 저장할 벡터 (0 = +, 1 = -, 2 = *, 3 = /)
	int m;  //연산자의 개수
	for (int i = 0; i < n; i++)
		cin >> number[i];
	for (int i = 0; i < 4; i++) { 
		cin >> m;
		for (int j = 0; j < m; j++)  //개수(m)만큼 연산자 저장
			symbol.push_back(i);
	}
	do {  //symbol 벡터를 순열을 통해 순서를 바꿔가며 최댓값과 최솟값 찾기
		ans = number[0];
		for (int i = 0; i < n - 1; i++) {
			switch (symbol[i]) {
			case 0: { 
				ans += number[i + 1];
				break;
			}
			case 1: { 
				ans -= number[i + 1];
				break;
			}
			case 2: { 
				ans *= number[i + 1];
				break;
			}
			case 3: {
				ans /= number[i + 1];
				break;
			}
			}
		}
		if (ans > max)
			max = ans;
		if (ans < min)
			min = ans;
	} while (next_permutation(symbol.begin(), symbol.end()));  //다음 순열이 있으면 true 반환 (중복x)
	cout << max << endl;
	cout << min;
	return 0;
}
