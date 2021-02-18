#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> v, e;

void dfs(int M){
  if(M == m){
    if(e.size() == m){
      for(int x:e){
        printf("%d ", x);
      }
      puts("");
    }
    return;
  }
  for(int i=0; i<v.size(); i++){
    bool isDone = false;
    if(e.empty()){
      e.push_back(v[i]);
      isDone = true;
    }else {
      int back = e.back();
      if(v[i] >= back){
        e.push_back(v[i]);
        isDone = true;
      }
    }
    dfs(M + 1);
    if(isDone){
      e.pop_back();
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