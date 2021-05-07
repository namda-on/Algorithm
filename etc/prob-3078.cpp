#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int a[300001];
    k++;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        a[i] = s.length();
    }
    
    long long ans=0;
    int block[21];
    for(int i=0; i<=20; i++) block[i] = 0;

    for(int i=0; i<k-1; i++) {
        ans += block[a[i]];
        block[a[i]]++;
    }
    for(int i=k-1; i<n; i++){
        ans += block[a[i]];
        block[a[i]]++;
        block[a[i-k+1]]--;
    }

    cout<< ans;
}