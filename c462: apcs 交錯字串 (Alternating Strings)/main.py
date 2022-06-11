k = int(input())
s = input()

largest = 0;
cur = s[0].islower()
length = 1;
a = []
for i in s[1:]:
  if i.islower() == cur:
    length += 1;
  else:
    a.append(length)
    length = 1;
  cur = i.islower()
a.append(length)

con = 0
length = 0
for i in a:
  if i == k:
    length += k
    if length > largest:
      largest = length
  elif i < k:
    if length > largest:
      largest = length
    length = 0
  else:
    length += k
    if length != 0:
      if length > largest:
        largest = length
      length = k
print(largest)