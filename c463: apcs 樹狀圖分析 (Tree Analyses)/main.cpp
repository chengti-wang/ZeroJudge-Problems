#include <iostream>
#include <vector>

using namespace std;

typedef struct _NODE
{
  vector<int> child;
  int child_num;
  int isRoot;
  int height;
}NODE;


NODE node[100001];

int recursive(int big_dude)
{
  int largest = 0;
  if(node[big_dude].child_num == 0)
  {
    node[big_dude].height = 0;
    return 0;
  }
  else
  {
    for(int i=0; i<node[big_dude].child_num; i++)
    {
      int child = recursive(node[big_dude].child[i]);
      if(child > largest)
      {
        largest = child;
      }
    }
    node[big_dude].height = largest + 1;
    return node[big_dude].height;
  }
}
int main() 
{
  int n;
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
  {
    node[i].isRoot = 1;
    node[i].child_num = 0;
    node[i].child.clear();
  }

  for(int i=1; i<=n; i++)
  {
    int k;
    scanf("%d", &k);
    int a[k];
    for(int j=0; j<k; j++)
    {
      scanf("%d", &a[j]);
      node[i].child.push_back(a[j]);
      node[i].child_num++;
      node[a[j]].isRoot = 0;
    }
  }
  int root = -1;
  for(int i=1; i<=n; i++)
  {
    if(node[i].isRoot == 1)
    {
      root = i;
    }
  }

  recursive(root);
  long long int sum = 0;
  for(int i=1; i<=n; i++)
  {
    sum += node[i].height;
  }
  printf("%d\n%lld", root, sum);
}