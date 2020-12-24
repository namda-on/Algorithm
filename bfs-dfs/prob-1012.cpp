#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool visited[50][50];
vector<pair<int,int>> v[50][50];

void dfs(int x, int y){
  visited[x][y] = true;
  for(pair<int,int> next:v[x][y]){
    if(visited[next.first][next.second] == false){
      dfs(next.first, next.second);
    }
  }
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--){
    int m, n, k, result = 0, a[50][50] ={0};
    scanf("%d%d%d", &m, &n, &k);
    while(k--){
      int x, y;
      scanf("%d%d", &x, &y);
      a[x][y] = 1;
    }

    for(int x=0; x<m; x++){
      for(int y=0; y<n; y++){
        if(x-1 >=0 && a[x-1][y] == 1) v[x][y].push_back(make_pair(x-1,y));
        if(x+1 <m && a[x+1][y] == 1) v[x][y].push_back(make_pair(x+1,y));
        if(y-1 >=0 && a[x][y-1] == 1) v[x][y].push_back(make_pair(x,y-1));
        if(y+1 <n && a[x][y+1] == 1) v[x][y].push_back(make_pair(x,y+1));
      }
    }

    for(int x=0; x<m; x++){
      for(int y=0; y<n; y++){
        if(a[x][y] ==1 && visited[x][y] == false){
          dfs(x,y);
          result++;
        }
      }
    }
    printf("%d\n", result);

    for(int x=0; x<m; x++){
      for(int y=0; y<n; y++){
        visited[x][y]=false;
        v[x][y].clear();
      }
    }
  }

}