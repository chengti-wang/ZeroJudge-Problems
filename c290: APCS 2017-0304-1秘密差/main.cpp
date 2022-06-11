#include <iostream>
#include <string.h>
int main() {
  char a[1001];
  scanf("%s", a);
  int sum_a = 0;
  int sum_b = 0;
  for(int i=0; i<strlen(a); i++)
  {
    if(i%2==0)
    {
      sum_a += a[i]-48;
    }
    else
    {
      sum_b += a[i]-48;
    }
  }
  if(sum_a-sum_b >= 0)
  {
    printf("%d", sum_a-sum_b);
  }
  else
  {
    printf("%d", sum_b-sum_a);
  }
}