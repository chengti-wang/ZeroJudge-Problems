#include <iostream>

int main() {
  int n,m;
  scanf("%d %d", &n, &m);
  int arr[n][3][4];
  for(int dice=0; dice<n; dice++)
  {
    
    arr[dice][0][0] = 0;
    arr[dice][0][1] = 3;
    arr[dice][0][2] = 0;
    arr[dice][0][3] = 0;
    arr[dice][1][0] = 5;
    arr[dice][1][1] = 1;
    arr[dice][1][2] = 2;
    arr[dice][1][3] = 6;
    arr[dice][2][0] = 0;
    arr[dice][2][1] = 4;
    arr[dice][2][2] = 0;
    arr[dice][2][3] = 0;
  }
  
  for(int i=0; i<m; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a > 0 && b > 0)
    {
      a--;
      b--;
      for(int j=0; j<3; j++)
      {
        for(int k=0; k<4; k++)
        {
          int t;
          t = arr[a][j][k];
          arr[a][j][k] = arr[b][j][k];
          arr[b][j][k] = t;
        } 
      }
    }
    else
    {
      a--;
      if(b == -1)
      {
        int t = arr[a][1][1];
        arr[a][1][1] = arr[a][0][1];
        arr[a][0][1] = arr[a][1][3];
        arr[a][1][3] = arr[a][2][1];
        arr[a][2][1] = t;
      }
      else
      {
        int t = arr[a][1][1];
        arr[a][1][1] = arr[a][1][0];
        arr[a][1][0] = arr[a][1][3];
        arr[a][1][3] = arr[a][1][2];
        arr[a][1][2] = t;
      }
    }
  }

  for(int i=0; i<n; i++)
  {
    printf("%d ", arr[i][1][1]);
  }
}