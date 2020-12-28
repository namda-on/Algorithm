#include<iostream>
#include<algorithm>
using namespace std;

int n, a[10000001]; 
int main()
{
  scanf("%d", &n);
  a[1]=1, a[2]=2;
  for(int i=3; i<=n; i++){
    a[i] = (a[i-2] + a[i-1]) % 10;
  }
  printf("%d", a[n]);
}
