#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M, k[101];
vector<int> v[101];

int bfs(int start, int end) {
  bool visited[101] ={false};
  int dist[101] ={0,};
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int next:v[cur]){
      if(!visited[next]){
        visited[next] = true;
        dist[next] = dist[cur] + 1;
        q.push(next);
      }
    }
  } 

  return dist[end];
}


int main(){
  scanf("%d%d", &N, &M);
  while(M--){ 
    int a,b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }

  for(int i=1; i<=N; i++){
    int result = 0;
    for(int j=1; j<=N; j++){
      if(i==j) continue;
      result += bfs(i,j);
    }
    k[i] = result;
  }

  int min=5000, ans=0;
  for(int i=1; i<=N; i++){
    if(k[i] < min){
      min = k[i];
      ans = i;
    }
  }

  printf("%d",ans);
  return 0;
}