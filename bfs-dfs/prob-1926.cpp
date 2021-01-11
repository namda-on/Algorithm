#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int a[500][500], group[500][500], Acount[250000];
vector<pii> v[500][500];
bool visited[500][500];

void dfs(int i, int j, int g){
  visited[i][j] = true;
  group[i][j] = g;
  for(pii next:v[i][j]){
    if(!visited[next.first][next.second]){
      group[next.first][next.second] = g;
      dfs(next.first,next.second, g);
    }
  }
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &a[i][j]);
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(a[i][j] == 1){
        if(i - 1 >= 0 && a[i-1][j] == 1) v[i][j].push_back(make_pair(i-1, j));
        if(j - 1 >= 0 && a[i][j-1] == 1) v[i][j].push_back(make_pair(i,j-1));
        if(i + 1 < n && a[i+1][j] == 1) v[i][j].push_back(make_pair(i+1, j));
        if(j + 1 < m && a[i][j+1] == 1) v[i][j].push_back(make_pair(i,j+1));
      }
    }
  }

  int ans = 0, gh=1;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(a[i][j] == 1 && !visited[i][j]){
        dfs(i, j, gh);
        ans++;
        gh++;
      }
    }
  }
  printf("%d\n", ans);

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(group[i][j] != 0){
        int b = group[i][j];
        Acount[b]++;
      }
    }
  }

  int maxArea = 0;
  for(int i=0; i<250000; i++){
    if(Acount[i] > maxArea) maxArea = Acount[i];
  }

  printf("%d", maxArea);
}