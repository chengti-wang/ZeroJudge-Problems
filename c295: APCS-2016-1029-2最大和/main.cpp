#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n,m;
  scanf("%d %d", &n, &m);
  int a[n][m];
  int sum = 0;
  vector<int> b;
  for(int i=0; i<n; i++)
  {
    int largest = -1;
    for(int j=0; j<m; j++)
    {
      scanf("%d", &a[i][j]);
      if(a[i][j] > largest)
        largest = a[i][j];
    }
    b.push_back(largest);
    sum += largest;
  }
  printf("%d\n", sum);
  int something = 0;
  for(int i=0; i<b.size(); i++)
  {
    if(sum % b[i] == 0)
    {
      something = 1;
      printf("%d ", b[i]);
    }
  }
  if(something == 0)
  {
    printf("-1");
  }
}