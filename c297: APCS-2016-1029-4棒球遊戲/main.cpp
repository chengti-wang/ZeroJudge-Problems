#include <iostream>

int main() {
  char str[9][5][3];
  for(int i=0; i<9; i++)
  {
    int a;
    scanf("%d", &a);
    for(int j=0; j<a; j++)
    {
      scanf("%s", str[i][j]);
    }
  }
  int out_num;
  scanf("%d", &out_num); 

  int base[7] = {0};
  int point = 0;
  int out = 0;
  for(int i=0; i<5; i++)
  {
    for(int j=0; j<9; j++)
    {
      if(str[j][i][0] == '1' || str[j][i][0] == '2' || str[j][i][0] == '3')
      {
        for(int k=2; k>=0; k--)
        {
          base[k+str[j][i][0]-48] += base[k];
          base[k] = 0;
        }
        base[str[j][i][0]-48-1]++;
      }
      
      else if(str[j][i][0] == 'H')
      {
        int count = 0;
        for(int k=2; k>=0; k--)
        {
          if(base[k] == 1)
          {
            count++;
          }
        }
        base[0] = 0;
        base[1] = 0;
        base[2] = 0;
        count++;
        base[3] += count;
      }
      else
      {
        out++;
        if(out%3 == 0)
        {
          base[0] = 0;
          base[1] = 0;
          base[2] = 0;
        }
        if(out == out_num)
        {
          for(int k=3; k<7; k++)
          {
            point += base[k];
          }
          printf("%d", point);
          return 0;
        }
      }
    }
  }
}