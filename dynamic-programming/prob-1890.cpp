#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, a[100][100];
long long k[100][100];

int main()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &a[i][j]);
    }
  }

  k[0][0] = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(k[i][j] == 0 || (i==(n-1) && j==(n-1))) continue;
      if(j + a[i][j] < n) k[i][j + a[i][j]] = k[i][j + a[i][j]] + k[i][j];
      if(i + a[i][j] < n) k[i + a[i][j]][j] = k[i + a[i][j]][j] + k[i][j];
    }
  }

  printf("%lld", k[n-1][n-1]);
}