def f():
  pass
def g():
  pass
def h():
  pass

string = input().split()
new_string = 0
if string[0] == 'f':
  ans = f(string, new_string)
elif string[1] == 'g':
  ans = g(string, new_string)
else:
  ans = h(string, new_string)
print(eval("2"))