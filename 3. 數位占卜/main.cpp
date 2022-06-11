m = int(input())
a = []
for i in range(m):
    b = input()
    a.append(b)
sum_ = 0
a = sorted(a, key=lambda ele:len(ele), reverse=True)
for i in range(0, m-1):
    long = a[i]
    length = len(long)
    for j in range(0, length-1//2):
        head = long[:j+1]
        tail = long[length-j-1:]
        if head == tail:
            try:
                if a.index(long[j+1:length-1-j]) != -1:
                    sum_ += 1
            except ValueError:
                pass
print(sum_)
