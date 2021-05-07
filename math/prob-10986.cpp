#include<iostream>
#include<algorithm>

using namespace std;

int remain[1000];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n+1], s[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    s[0] = a[0] % m;
    remain[s[0]]++;
    for(int i=1; i<n; i++){
        int temp = (s[i-1] + a[i]) % m;
        s[i] = temp; 
        remain[temp]++;
    }


    long long result = remain[0];
    for(int i=0; i<m; i++ ){
        if(remain[i] == 0) continue;
        int k = remain[i];
        result += (long long)k * (k-1) /2;
    }

    printf("%lld", result);

}