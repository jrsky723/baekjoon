import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

INF = int(1e9)
n = int(input())
adj = [list(map(int, input().split())) for _ in range(n)]
dp = [[-1]*(1 << n)for _ in range(n)]

def DFS(st, state):
  if state == (1 << n) - 1:
    if adj[st][0]:
      return adj[st][0]
    else:
      return INF
  
  if dp[st][state] != -1:
    return dp[st][state]

  dp[st][state] = INF
    
  for i in range(1, n):
   if adj[st][i] == 0 or state & (1 << i):
    continue

   dp[st][state] = min(dp[st][state], DFS(i, state | (1 << i)) + adj[st][i])

  return dp[st][state]

print(DFS(0,1))