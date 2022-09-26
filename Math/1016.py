import sys
input = sys.stdin.readline

min, max = map(int, input().split())
li = [1]*(max - min + 1)
for i in range(2, int(max**0.5) + 1):
  sq = i**2
  for j in range(min//sq*sq, max + 1, sq):
    if j - min >= 0 and li[j - min]:
      li[j - min] = 0
print(li.count(1))
