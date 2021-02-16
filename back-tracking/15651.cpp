#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;

vector<int> v;
int n,m;

void dfs(int M){
  if(M==m){
    for(int x:v){
      printf("%d ", x);
    }
    puts("");
    return;
  }
  for(int i=1;i<=n; i++){
    v.push_back(i);
    dfs(M+1);
    v.pop_back();
  }
}

int main ()
{
  scanf("%d %d", &n, &m);
  dfs(0);
}