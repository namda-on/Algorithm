#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;

vector<int> v;
int n,m;

void dfs(int M){
  if(M==m){
    if(v.size() == m){
      for(int x:v){
      printf("%d ", x);
    }
    puts("");
    }
    return;
  }
  for(int i=1;i<=n; i++){
    bool check = false;
    int back;
    if(!v.empty()){
      back = v.back();
      if(i >= v.back()){
        v.push_back(i);
        check = true;
      }
    }else{
        v.push_back(i);
        check = true;
    }
    dfs(M+1);
    if(check){
      v.pop_back();
    }
  }
}

int main ()
{
  scanf("%d %d", &n, &m);
  dfs(0);
}