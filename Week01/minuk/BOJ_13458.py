import sys
input = sys.stdin.readline

n = int(input())
candidate = [int(input())] if n == 1 else list(map(int, input().split()))
b, c = map(int, input().split())

result = n # 총감독관 무조건 한명씩
for i in range(n):
    if candidate[i] < b: continue # 총감독관 한명으로도 충분한 경우
    candidate[i] -= b
    result += candidate[i] // c
    if candidate[i] % c > 0: result += 1
    
print(result)