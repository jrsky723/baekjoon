import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

INF = int(1e9)
n = int(input())
adj = [list(map(int, input().split())) for _ in range(n)]
dp = [[0]*(1 << n)for _ in range(n)]

def dfs(cur, route):
  if dp[cur][route]:
    return dp[cur][route]

  if route == (1 << n) - 1:
    if adj[cur][0] : return adj[cur][0]
    else : return INF
  
  dp[cur][route] = INF
  for i in range(1, n):
    if route & (1 << i) : continue
    if adj[cur][i] == 0 : continue
    dp[cur][route] = min(dp[cur][route], dfs(i, route | (1 << i)) + adj[cur][i])

  return dp[cur][route]

print(dfs(0,1))