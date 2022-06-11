#include <iostream>

int main() {
  int a[4][4];
  int asum = 0;
  int bsum = 0;
  int win = 0;
  for(int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
    {
      scanf("%d", &a[i][j]);
      if(i%2==0)
      {
        asum += a[i][j];
      }
      else
        bsum += a[i][j];
    }
    if(i == 1)  
    {
      printf("%d:%d\n", asum, bsum);
      if(asum > bsum)
      {
        win++;
      }
      asum = 0 ;
      bsum=0;
    }
  }
  printf("%d:%d\n", asum, bsum);
  if(asum > bsum)
  {
    win++;
  }
  if(win==2)
    printf("Win");
  else if(win==1)
    printf("Tie");
  else
    printf("Lose");
}