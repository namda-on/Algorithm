// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <vector>
#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string T, P;
    getline(cin, T);
    getline(cin, P);

    int N=T.length(), M = P.length();
    int fail[M] = {};

    //fail 함수 계산;
    for(int i=1, j=0; i<M; i++){
        while(j>0 && P[i] != P[j] ) j = fail[j-1];
        if(P[i] == P[j]) fail[i] = ++j;
    }

    vector<int> res;
    for (int i=0, j=0; i<N; i++){
        while(j>0 && T[i] != P[j]) j = fail[j-1];
        
        if(T[i] == P[j]){
            if(j == M - 1){
                res.push_back(i-M+1);
                j = fail[j];
            }else j++;
        }
    }
    cout << res.size() << "\n";
    for(int i=0; i<res.size(); i++){
        
        cout << res[i] + 1 << " ";
    }

}
