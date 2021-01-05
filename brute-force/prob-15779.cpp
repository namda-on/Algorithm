#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, L = 2, result = 2;
vector<int> a;

void search(int k, char isIncrease){
  if(k >= n) {
    if(result > L) L = result;
    return;
  }
  char Increase;
  if(a[k] - a[k-1] > 0) Increase = 'I';
  if(a[k] - a[k-1] < 0) Increase = 'D';
  if(a[k] - a[k-1] == 0) Increase = 'E';
  if(isIncrease == Increase || isIncrease == 'E' || Increase == 'E') {
    if(result > L) L = result;
    result = 2;
    search(k+1, Increase);
    return;
  }
  result++;
  search(k+1, Increase);
}
int main()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int x; 
    scanf("%d", &x);
    a.push_back(x);
  }
  char I;
  if(a[1] - a[0] > 0) I = 'I';
  if(a[1] - a[0] < 0) I = 'D';
  if(a[1] - a[0] == 0) I = 'E';
  search(2, I);
  printf("%d", L);
}