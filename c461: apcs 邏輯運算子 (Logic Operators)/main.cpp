#include <iostream>

int main() {
  int a,b,n;
  scanf("%d %d %d", &a, &b, &n);
  int print = 0;
  if((a && b) == n)
  {
    printf("AND\n");
    print = 1;
  }
  if((a || b) == n)
  {
    printf("OR\n");
    print = 1;
  }

  // bit xor
  if(((a!=0) ^ (b!=0))== n)
//if(((a == b) && (n == 0)) || ((( a == 0 && b != 0 ) || (a != 0 && b == 0 )) && n == 1 ))
  {
    printf("XOR\n");
    print = 1;
  }
  if(print == 0)
  {
    printf("IMPOSSIBLE\n");
  }
}