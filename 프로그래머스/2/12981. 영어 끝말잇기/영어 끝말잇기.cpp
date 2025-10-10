#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2, 0);
	set<string> used;
	char pre = words[0][0];
	int fail = -1;
	for (int i = 0; i < words.size(); i++) {
		if (words[i].length() == 1 || pre != words[i][0] || used.find(words[i]) != used.end()) {
			fail = i;
			break;
		}
		used.insert(words[i]);
		pre = words[i].back();
	}
	if (fail != -1) {
        if (++ fail % n == 0) 
            answer = {n, fail/n};
        else
            answer = {fail%n, fail/n+1};
	}

	return answer;
}