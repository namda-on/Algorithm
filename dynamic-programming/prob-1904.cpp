#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

int a[1000001];

int dfs(int k){
  if(k == 1) return 1;
  if(k == 2) return 2;
  if(a[k] != -1) return a[k];
  a[k] = (dfs(k-1) + dfs(k-2)) % 15746;
  return a[k];
}

int main()
{
  memset(a, -1, sizeof(a));
  int n;
  scanf("%d", &n);
  printf("%d", dfs(n));
}