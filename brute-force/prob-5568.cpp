#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

map<string, bool> visited;

int main()
{
  int n, k, card[10], result =0;
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++) scanf("%d", &card[i]);
  sort(card, card+n);
  do
  {
    string s;
    for(int i=0; i<k; i++) s+= to_string(card[i]);
    if(!visited[s]){
      visited[s] = true;
      result++;
    }

  } while (next_permutation(card, card + n));
  
  printf("%d",result);
}