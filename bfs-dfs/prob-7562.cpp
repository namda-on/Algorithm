#include<iostream>
#include<algorithm> 
#include<vector>
#include<queue>
using namespace std; 

vector<pair<int, int>> v[300][300];

int bfs(pair<int, int> start, pair<int, int> end){
  bool visited[300][300] = {false};
  int dist[300][300] = {0};
  queue<pair<int,int>> q;
  q.push(start);
  visited[start.first][start.second] = true;
  while(!q.empty()){
    pair<int, int> cur = q.front();
    q.pop();
    for(pair<int, int> next:v[cur.first][cur.second]){
      if(!visited[next.first][next.second]){
        visited[next.first][next.second] = true;
        dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
        q.push(next); 
      }
        if(next.first == end.first && next.second == end.second) goto done;
    }
  }
  done : 
  return dist[end.first][end.second];
}

int n, d, s_x, s_y, e_x, e_y;
int main()
{
  scanf("%d", &n);
  while(n--){
    scanf("%d", &d);
    scanf("%d%d%d%d", &s_x, &s_y, &e_x, &e_y );
    for(int x=0; x<d; x++ ){
      for(int y=0; y<d; y++){
        if(x+2 <d && y+1 <d) v[x][y].push_back(make_pair(x+2,y+1));
        if(x+1 <d && y+2 <d) v[x][y].push_back(make_pair(x+1,y+2));
        if(x+1 <d && y-2 >=0) v[x][y].push_back(make_pair(x+1,y-2));
        if(x+2 <d && y-1 >=0)  v[x][y].push_back(make_pair(x+2,y-1));
        if(x-2 >=0 && y+1 <d) v[x][y].push_back(make_pair(x-2,y+1));
        if(x-2 >=0 && y-1 >=0)  v[x][y].push_back(make_pair(x-2,y-1));
        if(x-1 >=0 && y+2 <d )  v[x][y].push_back(make_pair(x-1,y+2));
        if(x-1 >=0 && y-2 >=0) v[x][y].push_back(make_pair(x-1,y-2));
      }
    }
    printf("%d\n", bfs(make_pair(s_x, s_y), make_pair(e_x,e_y)));
    for(int i=0; i<d; i++){
      for(int j=0; j<d; j++){
        v[i][j].clear();
      }
    }

  }

}