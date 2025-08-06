import sys
input = sys.stdin.readline

def dfs(cnt, idx):
    global result
    
    if cnt == n//2: # 반으로 나뉘면
        link_score = 0
        start_score = 0
        link = list(temp)
        start = list(member - temp) # 이거 때문에 set으로 !
        
        for i in range(cnt-1):
            for j in range(i+1, cnt):
                link_score += score[link[i]][link[j]] + score[link[j]][link[i]]
                start_score += score[start[i]][start[j]] + score[start[j]][start[i]]
        
        result = min(result, abs(link_score-start_score))
        return
    
    for i in range(idx, n): # idx를 통해 중복x (1,2), (2,1) ...
        temp.add(i)
        dfs(cnt+1, i+1)
        temp.remove(i)

n = int(input())
score = [list(map(int, input().split())) for _ in range(n)]

member = {i for i in range(n)} # set으로 만들기
temp = set() # 팀을 잠시 나눌 변수
result = 1e9

dfs(0, 0)

print(result)