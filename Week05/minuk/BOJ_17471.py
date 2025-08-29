"""
ex) 7개
1 6 / 2 5 / 3 4

틀림 ㅠㅠ
"""

import sys
from collections import deque
input = sys.stdin.readline

def canDivide(a):
  if len(a) == 1:
    return 1
  
  temp = list(a)
  q = deque([temp[0]])
  temp.remove(temp[0])
  while q:
    curr = q.popleft()
    for g in graph[curr]:
      if g in temp:
        temp.remove(g)
        q.append(g)
  
  return 1 if len(temp) == 0 else 0

def dfs(cnt, idx, k):
  global result
  if cnt == k:
    gukminuihim = list(set([i for i in range(n)]) - set(minjudang))
    
    if canDivide(minjudang) and canDivide(gukminuihim):
      a = 0
      b = 0
      for m in minjudang:
        a += population[m]
      for g in gukminuihim:
        b += population[g]
      
      result = min(result, abs(a-b))

    return
  
  for i in range(idx, n):
    minjudang.append(i)
    dfs(cnt+1, i+1, k)
    minjudang.pop()
  
  

result = 1e9
n = int(input())
population = list(map(int, input().split()))
graph = [[] for _ in range(n)]

for i in range(n):
  temp = list(map(int, input().split()))
  if temp[0] != 0:
    graph[i].extend(temp[1:])

minjudang = []
gukminuihim = []

for i in range(1, n//2+1):
  dfs(0, 0, i)

print(result if result != 1e9 else -1)