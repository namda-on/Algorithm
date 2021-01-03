#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
typedef pair<int, int> pi;

stack<pi> st;
int result[10000000], a[10000000];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  
  for(int k=0; k<n; k++){
    while(!st.empty() && st.top().first < a[k]){
      result[st.top().second] = a[k];
      st.pop();
    }
    st.push(make_pair(a[k], k));
  }
  if(!st.empty()){
    while(!st.empty()){
      result[st.top().second] = -1;
      st.pop();
    }
  }
  for(int i=0; i<n; i++) printf("%d ", result[i]);
}