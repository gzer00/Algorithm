import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
conveyer = deque(map(int, input().split()))
robot = deque([0] * n) # 로봇
cnt = 0 # 내구도가 0인 칸 개수
step = 0 # 단계


while cnt < k: # k보다 작으면 계속
    step += 1
    
    # 1단계 deque에 rotate 쓰기
    conveyer.rotate(1)
    robot.rotate(1)
    robot[-1] = 0
    
    # 2단계
    for i in range(n-2, -1, -1):
        if robot[i+1] == 0 and robot[i] == 1 and conveyer[i+1] > 0:
            robot[i+1] = 1
            robot[i] = 0
            conveyer[i+1] -= 1
            # 4단계 한번에 여기서는 어짜피 1->0된 경우만
            if conveyer[i+1] == 0:
                cnt += 1
    robot[-1] = 0
    
    # 3단계
    if conveyer[0] > 0:
        robot[0] = 1
        conveyer[0] -= 1
        if conveyer[0] == 0:
            cnt += 1

print(step)