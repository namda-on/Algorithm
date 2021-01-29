#include <iostream>
#include <algorithm>
using namespace std;


int N, L;
int a[1000];
int main()
{
  scanf("%d%d", &N, &L);
  for(int i=0; i<N; i++) scanf("%d", &a[i]);
  sort(a, a+N);

  int now=0, result= 0;
  for(int i=0; i<N; i++){
    if(a[i] > now){
      result++;
      now = a[i] + L - 1; 
    }
  }
  printf("%d", result);
}