#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n, a[50001], minN;
vector<int> v;

int main(){
  scanf("%d", &n);
  a[0] = 0;
  a[1] = 1;

  for(int i=2; i< 224; i++) v.push_back(i*i);

  for(int i=2; i<=n; ++i){
    minN = 987654321;
    for(int j=0; v[j] <=i; ++j){
      int temp = i - v[j];
      minN = min(minN, a[temp]);
    }
    a[i] = minN + 1;
  }

  printf("%d", a[n]);

}