#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> v;
  while(n--){
    int k; 
    scanf("%d", &k);
    v.push_back(k);
  }
  sort(v.begin(), v.end());
  
  long long int result = 0;
  int active = 1;
  for(int i=1; i<v.size(); i++){
    result += (long long int)active * (long long int) v[i];
    if(active < m){
      active++;
    }
  }
  printf("%lld", result);
}