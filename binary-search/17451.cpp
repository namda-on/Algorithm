#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
vector<int> v;
int n;

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d", &temp);
    v.push_back(temp);
  }

  double ans = v[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    ans = ceil(ans / v[i]) * v[i];
  }
  printf("%lld", (long long)ans);
}