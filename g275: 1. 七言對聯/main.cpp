#include <iostream>

int main() {
  int n;
  scanf("%d", &n);
  
  for(int i=0; i<n; i++)
  {
    int a[2][7];
    for(int j=0; j<2; j++)
    {
      for(int k=0; k<7; k++)
      {
        scanf("%d", &a[j][k]);
      }
    }
    int aflag = 0;
    if(!(a[0][1] != a[0][3] && a[1][1] != a[1][3] && a[0][1] == a[0][5] && a[1][1] == a[1][5]))
    {
      printf("A");
      aflag = 1;
    }
    if(!(a[0][6] == 1 && a[1][6] == 0))
    {
      printf("B");
      aflag = 1;
    }
    
    if(!(a[0][1] != a[1][1] && a[0][3] != a[1][3] && a[0][5] != a[1][5]))
    {
      printf("C");
      aflag = 1;
    }
    if(aflag == 0)
    {
      printf("None");
    }
    printf("\n");
  }
}