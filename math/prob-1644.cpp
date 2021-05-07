#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
bool prime[4000001];

void primeNumber(int k){
    int i,j; 
    for(int i=2; i<=k; i++ ){
        if(prime[i]){
            for(j=i<<1; j<= k; j+=i) prime[j] = false;
            v.push_back(i);
        }
    }
}

int main()
{   
    int n;
    scanf("%d", &n);
    for(int i=0; i<=n; i++){
        prime[i] = true;
    }

    primeNumber(n);

    if(n==1){
        puts("0");
        return 0;
    }

    int r=0, l=0, ans =0,sum=v[0];
    while(r<v.size() && l < v.size()){
        if(sum == n) ans++;
        if(sum <= n) sum += v[++r];
        else sum -= v[l++];
        
    }

    printf("%d", ans);


}