#include <iostream>

int main() {
  int m,n,h;
  scanf("%d %d %d", &m, &n, &h);
  int a[m][n];
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      a[i][j] = 0;
    }
  }
  int largest = -1;
  for(int i=0; i<h; i++)
  {
    int r,c,t;
    scanf("%d %d %d", &r, &c, &t);
    if(t==0)
    {
      
      if(a[r][c] > 1)
      {
        if(r != 0)
        {
          for(int j=r-1; j>=0; j--)
          {
            if(a[j][c] == 1)
            {
              for(int k=j+1; k<r; k++)
              {
                if(a[k][c] == 2 || a[k][c] == 5) a[k][c] -= 2;
              }
              break;
            }
          }
        }
        if(r != m-1)
        {
          for(int j=r+1; j<m; j++)
          {
            if(a[j][c] == 1)
            {
              for(int k=r+1; k<j; k++)
              {
                if(a[k][c] != 0)
                  if(a[k][c] == 2 || a[k][c] == 5) a[k][c] -= 2;
              }
              break;
            }
          }
        }
        if(c != 0)
        {
          for(int j=c-1; j>=0; j--)
          {
            if(a[r][j] == 1)
            {
              for(int k=j+1; k<c; k++)
              {
                if(a[r][k] != 0)
                  if(a[r][k] == 3 || a[r][k] == 5) a[r][k] -= 3;
              }
              break;
            }
          }
        }
        if(c != n-1)
        {
          for(int j=c+1; j<n; j++)
          {
            if(a[r][j] == 1)
            {
              for(int k=c+1; k<j; k++)
              {
                if(a[r][k] != 0)
                  if(a[r][k] == 3 || a[r][k] == 5) a[r][k] -= 3;
              }
              break;
            }
          }
        }
      }
      
      a[r][c] = 1;
      if(r != 0)
      {
        for(int j=r-1; j>=0; j--)
        {
          if(a[j][c] == 1)
          {
            for(int k=j+1; k<r; k++)
            {
              a[k][c] += 2;
            }
            break;
          }
        }
      }
      if(r != m-1)
      {
        for(int j=r+1; j<m; j++)
        {
          if(a[j][c] == 1)
          {
            for(int k=r+1; k<j; k++)
            {
              a[k][c] += 2;
            }
            break;
          }
        }
      }
      if(c != 0)
      {
        for(int j=c-1; j>=0; j--)
        {
          if(a[r][j] == 1)
          {
            for(int k=j+1; k<c; k++)
            {
              a[r][k] += 3;
            } 
            break;
          }
        }
      }
      if(c != n-1)
      {
        for(int j=c+1; j<n; j++)
        {
          if(a[r][j] == 1)
          {
            for(int k=c+1; k<j; k++)
            {
              a[r][k] += 3;
            }
            break;
          }
        }
      }
    }
    if(t == 1)
    {
      a[r][c] = 0;
      if(r != 0)
      {
        for(int j=r-1; j>=0; j--)
        {
          if(a[j][c] == 1)
          {
            for(int k=j+1; k<r; k++)
            {
              if(a[k][c] == 2 || a[k][c] == 5) a[k][c] -= 2;
            }
            break;
          }
        }
      }
      if(r != m-1)
      {
        for(int j=r+1; j<m; j++)
        {
          if(a[j][c] == 1)
          {
            for(int k=r+1; k<j; k++)
            {
              if(a[k][c] == 2 || a[k][c] == 5) a[k][c] -= 2;
            }
            break;
          }
        }
      }
      if(c != 0)
      {
        for(int j=c-1; j>=0; j--)
        {
          if(a[r][j] == 1)
          {
            for(int k=j+1; k<c; k++)
            {
              if(a[r][k] == 3 || a[r][k] == 5) a[r][k] -= 3;
            }
            break;
          }
        }
      }
      if(c != n-1)
      {
        for(int j=c+1; j<n; j++)
        {
          if(a[r][j] == 1)
          {
            for(int k=c+1; k<j; k++)
            {
              if(a[r][k] == 3 || a[r][k] == 5) a[r][k] -= 3;
            }
            break;
          }
        }
      }
    }
    int sum1 = 0;
    for(int j=0; j<m; j++)
    {
      for(int k=0; k<n; k++)
      {
        // printf("%d ", a[j][k]);
        if(a[j][k] > 0)
          sum1 += 1;
      }
      // printf("\n");
    }
    // printf("\n");
    if(sum1 > largest)
      largest = sum1;
  }
  int sum = 0;
  for(int j=0; j<m; j++)
  {
    for(int k=0; k<n; k++)
    {
      // printf("%d ", a[j][k]);
      if(a[j][k] > 0)
        sum += 1;
    }
    // printf("\n");
  }
  // printf("\n");
  printf("%d\n%d", largest, sum);
} 