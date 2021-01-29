#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int n;
vector<pii> a;

bool cmd(pii f, pii s){
  if(f.first == s.first) return f.second < s.second;
  return f.first < s.first;
}

int main()
{
  scanf("%d", &n);
  while(n--){
    int s, e;
    scanf("%d %d", &s, &e);
    a.push_back(make_pair(e,s));
  }
  sort(a.begin(), a.end(), cmd);

  int answer = 1, time = 0;

  for(int i=0; i<a.size(); i++ ){
    if(a[i].second >= time){
      answer++;
      time = a[i].first;
    }
  }
  printf("%d", answer-1);

}