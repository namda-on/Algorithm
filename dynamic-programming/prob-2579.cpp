#include <iostream>
#include <algorithm>

using namespace std;

int n, a[301];
pair<int, int> t[300];

pair<int, int> go(int k){
  if(k == 1) return make_pair(a[1], 0);
  if(k == 2) return make_pair(a[1] + a[2], a[2]);
  if(t[k].first != 0) return t[k];
  t[k].first = go(k-1).second + a[k];
  t[k].second = max(go(k-2).first + a[k], go(k-2).second + a[k]);
  return t[k];
}

int main()
{
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  printf("%d", max(go(n).first, go(n).second));
}