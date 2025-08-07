# 순열

# 방법 1: 재귀적 표현(use temp) P(n,n) = n * (n-1)!
def perm1(r, idx):
    # if r == 0:
    if r == m:
        for t in temp:
            print(t, end=" ")
        print()
    else:
        # 맨 뒤를 빼고, 나머지 n-1개 중에서 순열 (정렬이 뒤죽박죽)
        # for i in range(n-1, -1, -1):
        #     arr[i], arr[n-1] = arr[n-1], arr[i]
        #     temp[r-1] = arr[n-1] 
        #     perm1(n-1, r-1)
        #     arr[i], arr[n-1] = arr[n-1], arr[i]
        for i in range(idx, n):
            arr[i], arr[0] = arr[0], arr[i]
            temp[r] = arr[0]
            perm1(r+1, i+1)
            arr[i], arr[0] = arr[0], arr[i]

        
# 방법 2: temp 사용 x
def perm2(k):
    if k == m:
        for i in range(k):
            print(arr[i], end=" ")
        print()
    else: # 1 2 3 4, 1 3 2 4, 1 4 3 2, .. 앞에 m개만큼 출력
        for i in range(k, n, 1):
            arr[k], arr[i] = arr[i], arr[k]
            perm2(k+1)
            arr[k], arr[i] = arr[i], arr[k]

# 방법 3: 방문표시 왜 ? 방법 2는 직접 배열을 바꾸는거라 안전하지 않음
def perm3(k):
    if k == m:
        for t in temp:
            print(t, end=" ")
        print()
    else:
        for i in range(n):
            if visited[i]: continue # 방문했다면 스킵 !
            temp[k] = arr[i]
            visited[i] = True
            perm3(k+1)
            visited[i] = False
    
            
            
n, m = map(int, input().split())
arr = [i for i in range(1, n+1)]
temp = [0]*m
visited = [False] * n

# perm1(n, m)
perm1(0, 0)
# perm2(0)
# perm3(0)



