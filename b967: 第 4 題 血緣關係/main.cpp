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
NODE node[100000];

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
  while(scanf("%d", &n) != EOF)
  {
    for(int i=0; i<n; i++)
    {
      node[i].isRoot = 1;
      node[i].child_num = 0;
      node[i].child.clear();
    }

    for(int i=0; i<n-1; i++)
    {
      int a,b;
      scanf("%d %d", &a, &b);
      node[a].child.push_back(b);
      node[a].child_num++;
      node[b].isRoot = 0;
    }

    int root = -1;
    for(int i=0; i<n; i++)
    {
      if(node[i].isRoot == 1)
      {
        root = i;
      }
    }

    recursive(root);
    /*
    printf("\n");
    for(int i=0; i<n; i++)
    {
      printf("Node[%d] = %d, child_num=%d\n", i, node[i].height, node[i].child_num);
    }
    printf("\n");
    */
    int largest = -1;
    
    for(int i=0; i<n; i++)
    {
      int largest1 = -1;
      int largest2 = -1;
      if(node[i].child_num > 1)
      {
        for(int j=0; j<node[i].child_num; j++)
        {
          if(node[node[i].child[j]].height + 1> largest1)
          {
            largest2 = largest1;
            largest1 = node[node[i].child[j]].height + 1;
          }
          else if(node[node[i].child[j]].height + 1> largest2)
          {
            largest2 = node[node[i].child[j]].height + 1;
          }
        }
      }
      if(largest1 + largest2 > largest)
      {
        largest = largest1 + largest2;
      }
    }
    if(node[root].height > largest)
    {
      largest = node[root].height;
    }

    printf("%d\n", largest);
  }
}

/*

 8

 0 1

 0 2

 0 3

 7 0

 1 4

 1 5

 3 6

 4

 0 1

 0 2

 2 3

 

 */