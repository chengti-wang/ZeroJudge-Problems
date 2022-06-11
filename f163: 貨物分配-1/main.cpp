#include <iostream>

using namespace std;

typedef struct _NODE
{
  int child_num;
  int child[2];
  int weight;
}NODE;

NODE node[100000*2];

int recursive(int root)
{
  if(node[root].child_num > 0)
  {
    node[root].weight = recursive(node[root].child[0]) + recursive(node[root].child[1]);
    // node[root].weight = node[node[root].child[0]].weight + node[node[root].child[1]].weight;
  }
  return node[root].weight;
}

int main() {
  int n,m;
  scanf("%d %d", &n, &m);
  for(int i=1; i<2*n; i++)
  {
    node[i].child_num = 0;
    node[i].weight = 0;
  }
  for(int i=n; i<=2*n-1; i++)
  {
    scanf("%d", &node[i].weight);
  }
  int bArr[m];
  for(int i=0; i<m; i++)
  {
    scanf("%d", &bArr[i]);
  }

  for(int i=1; i<=n-1; i++)
  {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    node[a].child[0] = b;
    node[a].child[1] = c;
    node[a].child_num = 2;
  }

  recursive(1);
  
  int cur = 1;
  for(int i=0; i<m; i++)
  {
    while(node[cur].child_num != 0)
    {
      if(node[node[cur].child[1]].weight < node[node[cur].child[0]].weight)
      {
        node[node[cur].child[1]].weight += bArr[i];
        cur = node[cur].child[1];
      }
      else
      {
        node[node[cur].child[0]].weight += bArr[i];
        cur = node[cur].child[0];
      }
    }
    printf("%d ", cur);
    cur = 1;
  }

}