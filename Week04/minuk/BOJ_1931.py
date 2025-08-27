"""
끝나는 시간이 제일 짧은 순으로 정렬
가능한 것들을 앞에서부터 채택 !
왜 이게 가능할까?
제일 최선이야 ,,
시작시간과 관계 없이 끝나는 시간이 제일 적어야 다음 선택지가 넓어짐.
즉 가능한 것들 중 가장 빨리 끝나는 애를 채택 !
"""

import sys
input = sys.stdin.readline

n = int(input())
meeting = []

for _ in range(n):
  start, end = map(int, input().split())
  meeting.append((start, end))

meeting.sort(key = lambda x:(x[1], x[0]))

nstart = 0
result = 0
for start, end in meeting:
  if start >= nstart:
    result += 1
    nstart = end

print(result)