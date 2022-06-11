#include <iostream>

int main() {
  int n;
  scanf("%d", &n);
  int a[n+1];
  a[0] = 0;
  int sums[n];
  sums[0] = 0;
  int sum = 0;
  for(int i=1; i<n+1; i++)
  {
    scanf("%d", &a[i]);
    sum += a[i];
    sums[i] = sum;
  }
  int l = 1;
  int r = n;
  int l1,l2,r1,r2;
  int m;

  while(1)
  {
    
    int smallest = 1000000;
    int idx = 0;
    for(int i=l; i<=r; i++)
    {
      if(a[i] < smallest)
      {
        smallest = a[i];
        idx = i;
      }
    }
    m = idx;
    l1 = l, r1 = m - 1, l2 = m + 1, r2 = r;
    int l_sum = sums[r1] - sums[l1-1];
    int r_sum = sums[r2] - sums[l2-1];
    if(l_sum > r_sum)
    {
      l = l1;
      r = r1;
    }
    else
    {
      l = l1;
      r = r1;
    }
    printf("l: %d r: %d m; %d l_sum: %d r_sum: %d\n", l, r, m, l_sum, r_sum);
    if(l == r)
    {
      printf("%d", a[l]);
      break;
    }
    
  }
  
}