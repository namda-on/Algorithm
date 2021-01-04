#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int map[101][101];
char direction = 'R', query[10001];

deque<pii> dq;

void switchDirection(char previous, char q){
  switch (previous)
  {
  case 'U':
    if(q == 'L') direction = 'L';
    if(q == 'D') direction = 'R';
    break;
  case 'D':
    if(q == 'L') direction = 'R';
    if(q == 'D') direction = 'L';
    break;
  case 'R':
    if(q == 'L') direction = 'U';
    if(q == 'D') direction = 'D';
    break;
  case 'L':
    if(q == 'L') direction = 'D';
    if(q == 'D') direction = 'U';
    break;
  default:
    direction = 'A';
  }
}

int main()
{
  int n, k, l;
  scanf("%d", &n);
  scanf("%d", &k);
  for(int i=0; i<k; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    map[a][b] = 1; 
  }
  scanf("%d", &l);
  for(int i=0; i<l; i++){
    int t; 
    char d;
    scanf("%d %c", &t, &d);
    query[t] = d;
  }

  dq.push_back(make_pair(1,1));
  int now = 1;
  while(true){
    deque<pii> temp;
    int x, y;
    switch (direction)
    {
    case 'R':
      if(dq.front().second + 1 > n) goto done;
      x = dq.front().first;
      y = dq.front().second + 1;
      while(!dq.empty()){
        pii element = dq.front();
        if(element.first == x && element.second == y ) goto done;
        dq.pop_front();
        temp.push_back(element);
      }
      if(!temp.empty()) dq = temp;
      dq.push_front(make_pair(x, y));
      if(map[x][y] == 1){
        map[x][y] = 0;
        break;
      } 
      dq.pop_back();
      break;
    case 'L':
      if(dq.front().second - 1 < 1) goto done;
      x = dq.front().first;
      y = dq.front().second -1;
      while(!dq.empty()){
        pii element = dq.front();
        if(element.first == x && element.second == y ) goto done;
        dq.pop_front();
        temp.push_back(element);
      }
      if(!temp.empty()) dq = temp;
      dq.push_front(make_pair(x, y));
      if(map[x][y] == 1){
        map[x][y] = 0;
        break;
      } 
      dq.pop_back();
      break;
    case 'U':
      if(dq.front().first - 1 < 1) goto done;
      x = dq.front().first -1;
      y = dq.front().second;
      while(!dq.empty()){
        pii element = dq.front();
        if(element.first == x && element.second == y ) goto done;
        dq.pop_front();
        temp.push_back(element);
      }
      if(!temp.empty()) dq = temp;
      dq.push_front(make_pair(x, y));
      if(map[x][y] == 1){
        map[x][y] = 0;
        break;
      } 
      dq.pop_back();
      break;
    case 'D':
      if(dq.front().first + 1 > n) goto done;
      x = dq.front().first + 1;
      y = dq.front().second;
      while(!dq.empty()){
        pii element = dq.front();
        if(element.first == x && element.second == y ) goto done;
        dq.pop_front();
        temp.push_back(element);
      }
      if(!temp.empty()) dq = temp;
      dq.push_front(make_pair(x, y));
      if(map[x][y] == 1){
        map[x][y] = 0;
        break;
      } 
        
      dq.pop_back();
      break;
    }
    if(query[now]) switchDirection(direction, query[now]);
    now++;

  }

  done :
    printf("%d", now);
}


