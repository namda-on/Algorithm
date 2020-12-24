#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;


int m, n, a[1000][1000];
string r;
vector<pair<int,int>> v[1001][1001];
bool visited[1001][1001], result;

void dfs(int x, int y){
  visited[x][y] =true;
  for(pair<int, int> next:v[x][y]){
    if(visited[next.first][next.second] == false){
      dfs(next.first, next.second);
    }
  }
}

int main()
{
  scanf("%d%d", &m, &n);
  for(int i=0; i<m; i++){
    cin >> r;
    for(int j=0; j<n; j++){
      a[i][j] = r[j] - '0';      
    }
  }

  for(int x=0; x<m; x++){
    for(int y=0; y<n; y++){
      if(a[x][y] == 0){
        if(x+1 < m && a[x+1][y] == 0) v[x][y].push_back(make_pair(x+1,y));
        if(y-1 >= 0 && a[x][y-1] == 0) v[x][y].push_back(make_pair(x,y-1));
        if(y+1 < n && a[x][y+1] == 0) v[x][y].push_back(make_pair(x,y+1));
        if(x-1 >= 0 && a[x-1][y] == 0) v[x][y].push_back(make_pair(x-1,y));
      }
    }
  }  
  for(int t=0; t<n; t++){
    if(a[0][t] == 0) dfs(0, t);
  }
  for(int k=0; k<n; k++) {
    if(visited[m-1][k]) {
      result = true;
    }
  }

  if(result){
    printf("YES");
  }else{
    printf("NO");
  }
}