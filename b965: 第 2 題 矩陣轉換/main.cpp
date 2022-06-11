#include <iostream>

int main() {
  int r, c, m;
  while(scanf("%d %d %d", &r, &c, &m) != EOF)
  {
    int large = r;
    int small = c;
    if(c > r)
    {
      large = c;
      small = r;
    }

    int a[large][large];
    int b[large][large];
     
    int curr = r;
    int curc = c;
    for(int i=0; i<r; i++)
    {
      for(int j=0; j<c; j++)
      {
        scanf("%d", &a[i][j]);
        b[i][j] = 0;
      }
    }
    int c[m];
    for(int i=0; i<m; i++)
    {
      scanf("%d", &c[i]);
    }
    for(int i=m-1; i>=0; i--)
    {
      if(c[i] == 1)
      {
        printf("Flip\n");
        for(int j=0; j<curr; j++)
        {
          for(int g=0; g<curc; g++)
          {
            printf("(%d,%d) -> (%d,%d)\n",curr-j,g, j,g );
            b[j][g] = a[curr-j-1][g];
          }
        }
        for(int j=0; j<curr; j++)
        {
          for(int g=0; g<curc; g++)
          {
            a[j][g] = b[j][g];
            b[j][g] = 0;
          }
        }
      }

      if(c[i] == 0)
      {
        int t=0;
        t = curc;
        curc = curr;
        curr = t;
        printf("Rotate\n");
        for(int j=0; j<curr; j++)
        {
          for(int g=0; g<curc; g++)
          {
            for(int d=0; d<small; d++)
            {
              printf("(%d,%d) -> (%d,%d)\n",g,small-d-1,j,g);
              b[j][g] = a[small-d-1][g];
            }
          }
        }
        for(int j=0; j<curr; j++)
        {
          for(int g=0; g<curc; g++)
          {
            a[j][g] = b[j][g];
            b[j][g] = 0;
          }
        }
        
      }
    }

    for(int i=0; i<curr; i++)
    {
      for(int j=0; j<curc; j++)
      {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  }
}