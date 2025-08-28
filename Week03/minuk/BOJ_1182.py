"""

부분 수열의 합
1 ~ n까지 백트래킹으로 조합! 만들기

"""

import sys
input = sys.stdin.readline

# 백트래킹
def dfs(idx, cnt, k):
    global result
    
    # k개가 되면
    if cnt == k:
        if sum(temp) == s:
            result += 1
        return
    
    for i in range(idx, n):
        temp.append(arr[i])
        dfs(i+1, cnt+1, k)
        temp.pop()

# 입력 받기
n, s = map(int, input().split())
arr = list(map(int, input().split()))

# 전역변수 result
result = 0

# 1개부터 n개까지 조합(부분수열) 만들기 * 공집합이 0인줄 알았는데 예제보니까 포함 안하는 듯 !
for k in range(1, n+1):
    temp = []
    dfs(0, 0, k)

print(result)