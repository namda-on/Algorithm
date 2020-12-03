#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
  return a > b;
}

int N; 
int rope[100000];
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &rope[i]);
  sort(rope, rope+N, compare);
  int result=0, max=0;
  while(N--){
    int next = rope[result];
    result++;
    if(max <= next * result){
      max = next * result;
    }
  }
  printf("%d", max);
}