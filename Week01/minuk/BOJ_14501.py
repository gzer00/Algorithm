import sys
input = sys.stdin.readline

n = int(input())
counsel = [list(map(int, input().split())) for _ in range(n)]
dp = [0] * (n+2) # n+1일까지 확인해야 돼 !

for i in range(1, n+1):
    day, value = counsel[i-1]
    
    # 상담 안해 !
    dp[i] = max(dp[i], dp[i-1])
    
    # 상담 해 !
    if i+day <= n+1:
        dp[i+day] = max(dp[i+day], dp[i]+value)


print(max(dp))

# import sys
# sys.setrecursionlimit(10**9)
# input = sys.stdin.readline

# def dfs(d, v):
#     if d > n:
#         return v
    
#     return max(dfs(d + counsel[d][0], v + counsel[d][1]) if d + counsel[d][0] <= n+1 else v, dfs(d+1, v))
    
# n = int(input())
# counsel = [[0, 0]]
# for _ in range(n):
#     counsel.append(list(map(int, input().split())))

# print(dfs(1, 0))