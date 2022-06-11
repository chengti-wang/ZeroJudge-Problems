#include <iostream>

int main() {
  int a1, b1, c1, a2, b2, c2;
  scanf("%d %d %d", &a1, &b1, &c1);
  scanf("%d %d %d", &a2, &b2, &c2);
  int n;
  scanf("%d", &n);
  int largest = -1000000000;
  for(int i=0; i<=n; i++)
  {
    int y1 = a1*i*i + b1*i + c1;
    int y2 = a2*(n-i)*(n-i) + b2*(n-i) + c2;
    int sum = y1 + y2;
    if(sum > largest)
    {
      largest = sum;
    }
  }
  printf("%d", largest);
}