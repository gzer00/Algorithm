"""
더한 뒤 정렬
다시 작은 숫자!
min heap사용하면 될듯?
"""

import sys
import heapq
input = sys.stdin.readline

n = int(input())
result = 0
card = []

for _ in range(n):
  heapq.heappush(card, int(input()))

while len(card) > 1:
  a = heapq.heappop(card)
  b = heapq.heappop(card)
  result += a + b
  heapq.heappush(card, a+b)

print(result)