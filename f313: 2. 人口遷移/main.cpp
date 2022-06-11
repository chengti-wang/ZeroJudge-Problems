#include <iostream>

int main() {
  int r,c, q,m;
  scanf("%d %d %d %d", &r, &c, &q, &m);
  int a[r+2][c+2];
  int b[r+2][c+2];
  for(int i=0; i<r+2; i++)
  {
    for(int j=0; j<c+2; j++)
    {
      if(i == 0 || i == r+1 || j == 0 || j == c+1)
      {
        a[i][j] = -1;
      }
      else
      {
        scanf("%d", &a[i][j]);
      }
      b[i][j] = 0;
    }
  }
  for(int i=0; i<m; i++)
  {
    for(int j=1; j<r+1; j++)
    {
      for(int k=1; k<c+1; k++)
      {   
        if(a[j][k] != -1)
        {
          int move = a[j][k] / q;
          if(a[j][k+1] != -1)
          {
            b[j][k+1] += move;
            b[j][k] -= move;
          }
          if(a[j][k-1] != -1)
          {
            b[j][k-1] += move;
            b[j][k] -= move;
          }
          if(a[j+1][k] != -1)
          {
            b[j+1][k] += move;
            b[j][k] -= move;
          }
          if(a[j-1][k] != -1)
          {
            b[j-1][k] += move;
            b[j][k] -= move;
          }
        }
      }
    }
    for(int j=1; j<r+1; j++)
    {
      for(int k=1; k<c+1; k++)
      {
        if(a[j][k] != -1)
          a[j][k] += b[j][k];
        b[j][k] = 0;
      }
    }
  }
  int smallest = 1000000;
  int biggest = -1;
  for(int i=1; i<r+1; i++)
  {
    for(int j=1; j<c+1; j++)
    {
      if(a[i][j] > 0  && a[i][j] < smallest)
      {
        smallest = a[i][j];
      }
      if(a[i][j] > biggest)
      {
        biggest = a[i][j];
      }
    }
  }
  printf("%d\n%d", smallest, biggest);
}