#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main()
{
  int n;
  scanf("%d", &n);
  while(n--){
    int d;
    scanf("%d", &d);

    if(d != 0) pq.push(make_pair(abs(d), d));
    if(d == 0) {
      if(pq.empty()){
        printf("0\n");
      }else {
        printf("%d\n", pq.top().second);
        pq.pop();
      }
    }
  }
}