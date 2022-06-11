#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n ,&m, &k);
  int a[k][4];
  for(int i=0; i<k; i++)
  {
    scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
  }
  int gone = 0;
  int board[n][m];
  int dead[k];
  for(int i=0; i<k; i++)
  {
    dead[i] = 0;
  }
  int sum = 0;
  while(gone == 0)
  {
    vector<int> bomb[2];
    for(int i=0; i<k; i++)
    {
      if(dead[i] == 0)
      {
        board[a[i][0]][a[i][1]] = 1;
      }
    }
    for(int i=0; i<k; i++)
    {
      if(dead[i] == 0)
      {
        
        a[i][0] += a[i][2];
        a[i][1] += a[i][3];
        if(a[i][0] >= n || a[i][1] >= m || a[i][0] < 0 || a[i][1] < 0)
        {
          dead[i] = 1;
        }
        else if(board[a[i][0]][a[i][i]] == 1)
        {
          dead[i] = 1;
          bomb[0].push_back(a[i][0]);
          bomb[1].push_back(a[i][1]);
        }
      }
    }
    for(int j=0; j<bomb[0].size(); j++)
    {
      board[bomb[0][j]][bomb[1][j]] = 0;
    }
    int surviveflag = 0;
    for(int j=0; j<k; j++)
    {
      if(dead[j] == 0)
        surviveflag = 1;
    }
    
    if(surviveflag == 0)
    {
      gone = 1;
      for(int j=0; j<n; j++)
      {
        for(int k=0; k<m; k++)
        {
          if(board[j][k] == 1)
          {
            sum++;
          }
        }
      }
      break;
    }
  }
  printf("%d", sum);
}