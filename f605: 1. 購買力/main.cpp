#include <iostream>

int main() {
  int n,d;
  scanf("%d %d", &n, &d);
  int a[n][3];
  int smallest = 100000;
  int largest = -1;
  int sum = 0;
  int avg = 0;
  int num = 0;
  int big_sum = 0;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<3; j++)
    {
      scanf("%d", &a[i][j]);
      sum += a[i][j];
      if(a[i][j] < smallest)
      {
        smallest = a[i][j];
      }
      if(a[i][j] > largest)
      {
        largest = a[i][j];
      }
    }
    if(largest - smallest >= d)
    {
      num++;
      big_sum += (sum/3);
    }
    sum = 0;
    smallest = 10000;
    largest = -1;
  }
  printf("%d %d", num, big_sum);
}