#include <iostream>

int main() {
  int n, dir;
  scanf("%d", &n);
  scanf("%d", &dir);
  int a[n][n];

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  int mid = n/2;
  printf("%d", a[mid][mid]);
  int cur_x = mid;
  int cur_y = mid;
  int times = 1;
  int f = n*n-2;
  int stop = 0;
  while(f>0)
  {
    for(int g=0; g<2; g++)
    {
      for(int j=0; j<times; j++)
      {
        if(dir==0)
        {
          cur_x--;
          printf("%d", a[cur_y][cur_x]);
        }
        if(dir == 1)
        {
          cur_y--;
          printf("%d", a[cur_y][cur_x]);
        }
        if(dir == 2)
        {
          cur_x++;
          printf("%d", a[cur_y][cur_x]);
        }
        if(dir == 3)
        {
          cur_y++;
          printf("%d", a[cur_y][cur_x]);
        }
        f--;
        if (f < 0)
        {
          stop = 1;
          break;
        }
      }
      dir++;
      if(dir==4)
      {
        dir = 0;
      }
      if(stop==1)
      {
        break;
      }
    }
    times++;
    if(stop==1)
    {
      break;
    }
  }
}
/*
5
0
3 4 2 1 4
4 2 3 8 9
2 1 9 5 6
4 2 3 7 8
1 2 6 4 3
*/