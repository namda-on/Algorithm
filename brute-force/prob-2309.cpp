#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int a[9], total=0, minus, x,y;
  for(int i=0; i<9; i++) {
    scanf("%d", &a[i]);
    total +=a[i];
  }
  
  minus = total - 100;
  for(int i=0; i<9; i++){
    for(int j=i+1; j<9; j++){
      if(minus == (a[i] + a[j])){
        x=a[i];
        y=a[j];
        goto done;
      }
    }
  }
  done :
  sort(a, a+9);
  for(int i=0; i<9; i++){
    if(a[i] == x || a[i]== y) continue;
    printf("%d\n", a[i]);
  }
}