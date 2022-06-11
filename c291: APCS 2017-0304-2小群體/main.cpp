#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  vector<int> b;
  int group = 0;
  
  for(int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }
  for(int i=0; i<n; i++)
  {
    int true_ = 0;
    vector<int>::iterator it = find(b.begin(), b.end(), i);
    if(it != b.end())
    {
      true_ = 1;
    }
    if(true_ == 0)
    {
      int start = i;
      int cur = a[i];
      b.push_back(i);
      b.push_back(cur);
      while(cur != i)
      {
        cur = a[cur];
        b.push_back(cur);
      }
      group++;
    }
  }
  printf("%d", group);
}