from itertools import combinations as co
h = [int(input()) for _ in range(9)]
occ = list(co(h,7))
for i in occ:
  if sum(i) == 100:
    ans = list(i)
    break
ans.sort()
for i in ans:
  print(i)