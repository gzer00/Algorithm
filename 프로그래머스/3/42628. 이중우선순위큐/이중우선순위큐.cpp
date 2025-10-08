#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    set<int> pq;
    map<int, int> cnt;
    int num;
    for (string s : operations) {
        if (s[0] == 'I') {
            stringstream ss(s);
            char i;
            ss >> i >> num;
            if (cnt.find(num) == cnt.end()) {
                pq.insert(num);
                cnt[num] = 1;
            }
            else
                cnt[num]++;
        }
        else if (pq.empty()) continue;
        if (s == "D 1") {
            num = *prev(pq.end());
            if (cnt[num] == 1) {
                pq.erase(num);
                cnt.erase(num);
            }
            else
                cnt[num]--;
        }
        else if (s == "D -1") {
            num = *pq.begin();
            if (cnt[num] == 1) {
                pq.erase(num);
                cnt.erase(num);
            }
            else
                cnt[num]--;
        }
    }
    if (pq.empty())
        answer = { 0, 0 };
    else
        answer = { *prev(pq.end()), *pq.begin() };
    return answer;
}