#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int a[4][n+1];
  a[0][0] = 0;
  a[1][0] = 0;
  a[2][0] = 0;
  a[3][0] = 0;

  for(int i=1; i<n+1; i++)
  {
    scanf("%d", &a[0][i]);
  }
  
  for(int i=1; i<=n; i++)
  {
    // red       blue,    green

    a[1][i] = max(a[2][i-1], a[3][i-1]) - a[0][i];
    a[2][i] = max(a[1][i-1], a[3][i-1]) + a[0][i];
    a[3][i] = max(a[1][i-1], a[2][i-1]); 
  }
  printf("%d", max({a[1][n], a[2][n], a[3][n]}));

  return 0;
} 