#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int a[n];
  for(int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    printf("%d", a[i]);
  }
  for(int i=0; i<n; i++)
  {
    printf("%d", a[i]);
  }
  sort(a, a+n);

  
  if(k == 1)
  {
    printf("%d", a[n-1]-a[0]);
  }
  else
  {
    int diameter = 1;

    while(1)
    {
      vector<int> covered;
      int start = a[0];
      int index = 0;
      int inrange = 0;
      int base_num = 0;
      int success = 0;
      while(1)
      {
        // printf("BASE NUM: %d START: %d SUCCESS: %d\n", a[index], start, success);
        covered.push_back(a[index]);
        if(a[index] - start > diameter)
        {
          inrange = 0;
          start = a[index];
          base_num++;
        }
        if(base_num == k || index < n)
        {
          if(covered[covered.size()-1] == a[n-1])
          {
            success = 1;
          }
          break;
        }
        index++;
      }
      if(success == 1)
      {
        printf("%d", diameter);
        break;
      }    
      diameter++;
    }
  }
}