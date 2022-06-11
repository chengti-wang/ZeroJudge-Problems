#include <iostream>
#include <string.h>

using namespace std;

//char a[1100000];
string a;
int i = -1;

int recursive(int length)
{
  i++;
  if(a[i] == '2')
  {
    //return sum + recursive(i+1) + recursive(i+2) + recursive(i+3) + recursive(i+4);
    int sum = 0;
    for(int j=0; j<4; j++)
    {
      sum += recursive( length / 2 );
    }
    return sum;  
  }
  else
  {
    if(a[i] == '1')
      return (length * length);
    else
      return 0;
  }
}

int main() {
  //scanf("%s", a);
  cin >> a;
  int n;
  scanf("%d", &n);
  int length = n;
  int index = 0;
  int ones = recursive(length);
  printf("%d", ones);
}