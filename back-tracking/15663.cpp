#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> v, e;
bool check[9];

void dfs(int M){
  if(M == m){
    
    for(int x:e){
      printf("%d ", x);
    }
    puts("");
    return;
  }

  int before = -1;
  for(int i=0; i<v.size(); i++){
    if(!check[i] && (i == 0 || before != v[i])){
      before = v[i];
      e.push_back(v[i]);
      check[i] = true;
      dfs(M + 1);
      e.pop_back();
      check[i] = false;
    }
  }
}

int main ()
{
  scanf("%d%d", &n, &m);
  while(n--){
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  dfs(0);

}