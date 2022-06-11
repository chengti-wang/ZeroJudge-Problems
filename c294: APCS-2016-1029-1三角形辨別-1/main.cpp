#include <iostream>
#include <algorithm>

int main() {
  int a,b,c;
  scanf("%d %d %d", &a, &b, &c);
  int x[3] = {a,b,c};
  std::sort(x, x+3);
  for(int i=0; i<3; i++)
  {
    printf("%d ", x[i]);
  }
  printf("\n");
  if(a+b <= c)
    printf("No");
  else if(a*a+b*b < c*c)
    printf("Obtuse");
  else if(a*a+b*b == c*c)
    printf("Right");
  else if(a*a+b*b > c*c)
    printf("Acute");
}