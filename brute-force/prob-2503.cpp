#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int N, num, s, b;
stack<string> candidate;

int main() {
  scanf("%d", &N);

  for(int x=1; x<=9; x++){
    for(int y=1; y<=9; y++){
      if(y==x) continue;
      for(int z=1; z<=9; z++){
        if(z==x || z==y) continue;
        string s = to_string(x) + to_string(y) + to_string(z);        
        candidate.push(s);
      }
    }
  }
  while(N--){
    string question;
    stack<string> temp;
    cin >> question >> s >> b;
    int size = candidate.size();
    for(int i=0; i<size; i++ ){
      string now = candidate.top();
      candidate.pop();
      int strike=0, ball=0;
      for(int j=0; j<3; j++){
        if(now[j] == question[j]){
          strike++;
        }else{
          if(j != 0 && now[j] == question[0]) ball++;
          if(j != 1 && now[j] == question[1]) ball++;
          if(j != 2 && now[j] == question[2]) ball++;
        }
      }
      if(strike == s && ball == b) temp.push(now);
    }
    candidate = temp;
  }
  printf("%d", candidate.size());

}