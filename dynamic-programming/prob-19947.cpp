#include<iostream>
#include<algorithm>

using namespace std;

int h, y;
int dps[11];

int go(int x, int money ){
  if(x == 0) return 0;
  if(x == 1) return money + 0.05 * money;   
  if(x == 3) return money + 0.2 * money;
  if(x == 5) return money + 0.35 * money;
  if(dps[x] != 0) return dps[x];
  if(x < 3) dps[x] = go(x-1, money) + go(x-1, money) * 0.05;
  if(x >3 && x < 5 ) dps[x] = max(go(x-1, money) + go(x-1, money) * 0.05, go(x-3, money) + go(x-3, money) * 0.2);
  if(x > 5) dps[x] = max({go(x-1, money) + go(x-1, money) * 0.05, go(x-3, money) + go(x-3, money) * 0.2, go(x-5, money) + go(x-5, money) * 0.35 });
  return dps[x];
}


int main()
{
  scanf("%d%d", &h, &y);
  printf("%d", go(y,h));
}