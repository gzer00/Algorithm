//부분수열의 합 (실버 2)
/*
1. 조합의 개수를 bool 벡터와 next_permutation을 통해 1~n개로 만듦
2. 만들어진 조합의 합을 구해서 s와 비교
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
     
    int n, s, count = 0;    // 수열의 크기, 목표 합, 정답이 되는 부분수열의 개수
    cin >> n >> s;
    vector<int> num(n);
    
    for (int i = 0; i < n; i++)
        cin >> num[i];

    for (int i = 1; i <= n; i++) {
        vector<bool> selected(n - i, false);    //조합을 고르기 위해 false의 개수만큼 벡터 만듦
        selected.insert(selected.end(), i, true);   //뽑을 조합의 수만큼 true를 벡터에 더함
        do {    //selected 벡터의 전체 순열을 만들어가며 조합을 만듦
            int sum = 0; //현재 조합의 합
            for (int j = 0; j < n; j++)
                if (selected[j])    //true면 합에 더함
                    sum += num[j];
            if (sum == s)
                count++;    //일치하면 카운팅
        } while (next_permutation(selected.begin(), selected.end()));
    }
    
    cout << count << "\n";
}
