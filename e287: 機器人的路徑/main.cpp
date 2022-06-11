#include <iostream>

int main() {
  int n,m;
  scanf("%d %d", &n, &m);
  int a[m+2][n+2];
  int smallest = 1000000;
  int cur_x, cur_y = 0;
  for(int i=0; i<n+2; i++)
  {
    for(int j=0; j<m+2; j++)
    {
      a[j][i] = -1;
    }
  }
  for(int i=1; i<n+1; i++)
  {
    for(int j=1; j<m+1; j++)
    {
      scanf("%d", &a[j][i]);
      if(a[j][i] < smallest)
      {
        cur_x = j;
        cur_y = i;
        smallest = a[j][i];
      }
    }
  }
  int noblock = 0;
  smallest = 1000000000;
  int sum = a[cur_x][cur_y];
  int new_x = cur_x;
  int new_y = cur_y;
  while(1)
  {
    noblock = 1;
    a[cur_x][cur_y] = -1;
    smallest = 1000000000;
    if(a[cur_x][cur_y+1] > 0)
    {
      noblock = 0;
      if(a[cur_x][cur_y+1] < smallest)
      {
        smallest = a[cur_x][cur_y+1];
        new_x = cur_x;
        new_y = cur_y + 1;
      }
    }
    if(a[cur_x][cur_y-1] > 0)
    {
      noblock = 0;
      if(a[cur_x][cur_y-1] < smallest)
      {
        smallest = a[cur_x][cur_y-1];
        new_x = cur_x;
        new_y = cur_y + 1;
      }
    }
    if(a[cur_x+1][cur_y] > 0)
    {
      noblock = 0;
      if(a[cur_x+1][cur_y] < smallest)
      {
        smallest = a[cur_x+1][cur_y];
        new_y = cur_y;
        new_x = cur_x + 1;
      }
    }
    if(a[cur_x-1][cur_y] > 0)
    {
      noblock = 0;
      if(a[cur_x-1][cur_y] < smallest)
      {
        smallest = a[cur_x-1][cur_y];
        new_y = cur_y;
        new_x = cur_x - 1;
      }
    }
    if(noblock == 1)
    {
      break;
    }
    sum += a[new_x][new_y];
    cur_x = new_x;
    cur_y = new_y;
  }
  printf("%d", sum);
}