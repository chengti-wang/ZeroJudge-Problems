#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }
  int sum = 0;
  for(int i=0; i<n; i++)
  {
    if(a[i] == 0)
    {
      if(i == 0)
      sum += a[i+1];
      else if(i==n-1)
        sum += a[n-2];
      else
        sum += min(a[i-1],a[i+1]);
    }
  }
  printf("%d", sum);
} 