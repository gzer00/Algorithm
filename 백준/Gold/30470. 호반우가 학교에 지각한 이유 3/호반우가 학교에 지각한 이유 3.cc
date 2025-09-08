#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    using ll = long long;

    vector<ll> treeList;   // 통나무 원래 길이 (1 x)
    vector<int> bornIdx;   // 이 통나무가 세워질 때까지 나온 마법(2 x)의 개수
    vector<ll> cutList;    // 마법이 만든 cut = max(k - x, 0) 들을 시간순으로 기록

    treeList.reserve(n);
    bornIdx.reserve(n);
    cutList.reserve(n);

    ll maxT = 0;   // 현재 계단의 최대 길이(k)
    int have = 0;  // 통나무 개수

    for (int i = 0; i < n; ++i) {
        int query; ll x;
        cin >> query >> x;

        if (query == 1) {
            // 통나무 추가
            treeList.push_back(x);
            bornIdx.push_back((int)cutList.size()); // 지금까지 발생한 마법 개수 기록
            ++have;
            if (x > maxT) maxT = x;                 // 현재 최대값 갱신
        } else {
            // 마법
            if (have == 0) continue;                // 통나무 없으면 무시
            ll cut = max(0LL, maxT - x);            // cut = max(k - m, 0)
            cutList.push_back(cut);                 // cut 기록
            maxT = cut;                             // 현재 최대값도 cut로 내려감
        }
    }

    // cutList의 suffix 최소값 계산
    const ll INF = (ll)4e18;
    int M = (int)cutList.size();
    vector<ll> suffixMin(M + 1, INF);               // suffixMin[i] = cutList[i..]의 최소
    for (int i = M - 1; i >= 0; --i)
        suffixMin[i] = min(cutList[i], suffixMin[i + 1]);

    // 각 통나무 최종 길이 = min(원래 길이, 세운 시점 이후 cut의 최소)
    long long ans = 0;
    for (int i = 0; i < (int)treeList.size(); ++i) {
        ll finalLen = min(treeList[i], suffixMin[bornIdx[i]]);
        ans += finalLen;
    }

    cout << ans << "\n";
    return 0;
}
