"""
n개의 행 (y값) m개의 열(x값)
n+1행에 궁수 3명 배치 (좌표값 3개씩 뽑기)
D에 따라서 범위 나누기
"""

import sys
input = sys.stdin.readline

# 3개 조합하기
def dfs(idx, cnt):
  global result
  if cnt == 3:
    # 임시 적 좌표 배열
    temp_enemy = list(enemy)
    # 몇 명 죽이는지 시뮬
    result = max(result, castle_defence(temp_enemy))
    return
  
  for i in range(idx, m):
    archer.append((i, n))
    dfs(i+1, cnt+1)
    archer.pop()

def castle_defence(eny):
  cnt = 0 # 죽인 적 수
  while eny: # 적이 있으면 계속
    turn = set([]) # 한 턴에 죽일 적 -> 같은 적 죽일 수 있어서 잠시 넣기
    for archer_x, archer_y in archer:
      distance = d # 첫 거리는 최대 거리
      temp = [] # 같은 거리면 왼쪽, 가까운 거리 거르기
      for enemy_x, enemy_y in eny:
        temp_d = abs(archer_x - enemy_x) + abs(archer_y - enemy_y) # 임시 거리
        if temp_d < distance: # 더 가까우면 distance 업데이트, temp 업데이트
          temp = [(enemy_x, enemy_y)]
          distance = temp_d
        elif temp_d == distance: # 같으면 그냥 추가
          temp.append((enemy_x, enemy_y))
      temp.sort(key=lambda x:x[0]) # x좌표 기준으로 정렬 => 첫 번째 요소가 제일 가까운 거리 왼쪽

      if temp:
        turn.add(temp[0]) # 같은 적 죽일 수도 있으니까 turn에 넣어놓기

    # 적 삭제
    for s in turn:
      eny.remove(s)
      cnt += 1

    # 한 칸씩 밑으로 이동, n이 되면 없애기
    eny = [(x, y+1) for (x, y) in eny if y+1 != n]

  return cnt

# 입력 받기
n, m, d = map(int, input().split())
enemy = [] # 적 좌표 배열
result = 0

# 적 좌표 넣기
for y in range(n):
  temp = list(map(int, input().split()))
  for x in range(m):
    if temp[x] == 1:
      enemy.append((x, y))

# 궁수 좌표 -> 백트래킹으로 3개 조합
archer = []
dfs(0, 0)
print(result)