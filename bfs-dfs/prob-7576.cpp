#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pii;
int a[1001][1001], visited[1001][1001], day=0, dist[1001][1001];
vector<pii> v[1001][1001], tomato;

int isDone(int x, int y){
  int result = 0;
  for(int i=0; i<y; i++){
    for(int j=0; j<x; j++){
      if(dist[i][j] > result) result = dist[i][j];
      if(a[i][j] == 0) {
        result = -1;
        goto done;
      }      
    }
  }
  done : 
  return result;
}

queue<pii> q;
void dfs(){
  while(!q.empty()){
    int cur_x = q.front().first;
    int cur_y = q.front().second;
    q.pop();
    for(pii next:v[cur_x][cur_y]){
      if(!visited[next.first][next.second]){
        visited[next.first][next.second] = true;
        a[next.first][next.second] = 1;
        dist[next.first][next.second] = dist[cur_x][cur_y] + 1;
        q.push(next);
      }else{
        if(dist[next.first][next.second] > dist[cur_x][cur_y] + 1){
          dist[next.first][next.second] = dist[cur_x][cur_y] + 1;
          q.push(next);
        }
      }
    }
  }

}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &a[i][j]);
    }
  }
  if(isDone(n,m) != -1) {
    printf("0");
  }else {
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(a[i][j] != -1){
        if(i+1 < m && a[i+1][j] == 0) v[i][j].push_back(make_pair(i+1,j));
        if(i-1 >= 0 && a[i-1][j] == 0) v[i][j].push_back(make_pair(i-1,j));
        if(j+1 < n && a[i][j+1] == 0) v[i][j].push_back(make_pair(i,j+1));
        if(j-1 >= 0 && a[i][j-1] == 0) v[i][j].push_back(make_pair(i,j-1));
        if(a[i][j] == 1) {
          q.push(make_pair(i,j));
        }
      }
    }
  }
  dfs();
  printf("%d\n", isDone(n,m));
  }
}