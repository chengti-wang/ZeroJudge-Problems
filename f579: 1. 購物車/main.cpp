#include <iostream>

int main() {
  int a,b;
  scanf("%d %d", &a, &b);
  int n;
  scanf("%d", &n);
  int arr[n];
  int sum = 0;
  for(int i=0; i<n; i++)
  {
    int asum = 0;
    int bsum = 0;
    while(1)
    {
      int x = 0;
      scanf("%d", &x);
      if(x == 0)
        break;
      if(x == a)
        asum += a;
      else if(x == a*-1)
        asum -= a;
      if(x == b)
        bsum += b;
      else if(x == b*-1)
        bsum -= b;
    }
    if(asum > 0 && bsum > 0)
      sum++;
  }
  printf("%d", sum);
}