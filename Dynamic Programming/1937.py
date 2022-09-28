import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

move = [(0, 1), (1, 0), (0, -1), (-1, 0)]
n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
dp = [[0]*n for _ in range(n)]

def OOB(x, y):
  return x < 0 or x >= n or y < 0 or y >= n

def dfs(x, y):
  if dp[x][y]: 
    return dp[x][y]
  dp[x][y] = 1
  for dx, dy in move:
    nx = x + dx; ny = y + dy
    if OOB(nx, ny) or board[x][y] >= board[nx][ny]:
        continue
    dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1)

  return dp[x][y]

ans = 0
for i in range(n):
  for j in range(n):
    ans = max(ans, dfs(i,j))

print(ans)