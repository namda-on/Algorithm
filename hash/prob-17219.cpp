#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

map<string, string> memo;
string input[100000];
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    string site, pwd; 
    cin >> site >> pwd;
    memo[site] = pwd;
  }

  
  for(int j=0; j<m; j++){
    string site;
    cin >> site;
    cout << memo[site] << endl;
  }
}