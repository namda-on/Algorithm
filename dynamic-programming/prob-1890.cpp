#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, a[100][100];
long long dfs[100][100];

int main()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &a[i][j]);
    }
  }

  dfs[0][0] = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(dfs[i][j] == 0 || (i==(n-1) && j==(n-1))) continue;
      if(j + a[i][j] < n) dfs[i][j + a[i][j]] = dfs[i][j + a[i][j]] + dfs[i][j];
      if(i + a[i][j] < n) dfs[i + a[i][j]][j] = dfs[i + a[i][j]][j] + dfs[i][j];
    }
  }

  printf("%lld", dfs[n-1][n-1]);
}