n = int(input())
a = input()
a = [int(i) for i in a.split()]
c = [0]
sumall = 0
for i in a:
  sumall += i
  c.append(sumall)
q = int(input())
for i in range(q):
  l,r = map(int,input().split())
  # b = input().split(' ')
  # l = int(b[0])
  # r = int(b[1])
  print(c[r] - c[l-1])
  