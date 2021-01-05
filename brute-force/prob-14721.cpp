#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

pair<int, int> sampleCase[100];
int main()
{
  int n, min=987654321, A, B;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int l, m;
    scanf("%d%d", &l, &m);
    sampleCase[i] = make_pair(l,m);
  }
  for(int a=1; a<=100; a++){
    for(int b=1; b<=100; b++){
      long long rss= 0;
      for(int x=0; x<n; x++){
        rss += pow(sampleCase[x].second - (a * sampleCase[x].first + b), 2);
      }
      if(rss < min) {
        min = rss;
        A = a;
        B = b;
      }
    }
  }
  printf("%d %d", A, B);
}