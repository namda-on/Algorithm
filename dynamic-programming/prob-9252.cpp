// int go(int N, int M){
//     if(N==n || M==m) return 0;
//     int &ret = d[N][M];  //참조
//     if(~ret) return ret;  //-1이 아닐경우 ~는 비트연산
//     ret = max(go(N+1,M), go(N, M+1));
//     if(s[N] == t[M] ) ret=max(ret, 1+go(N+1, M+1));
//     return ret;
// }


#include <bits/stdc++.h>
using namespace std;

char s[1005], t[1005];
int d[1005][1005];
int n, m;

int go(int N, int M){
    if(N==n || M ==m) return 0;
    if(d[N][M] != -1) return d[N][M];
    d[N][M] = max(go(N+1, M), go(N, M+1));
    if(s[N] == t[M] ) d[N][M] = max(d[N][M], 1+go(N+1, M+1));
    return d[N][M];
}


void track(int N, int M){
    if(N==n || M==m) return;
    int ret=go(N,M);
    if(go(N+1,M) == ret){
        track(N+1, M);
        return ;
    }
    if(go(N,M+1) == ret){
        track(N, M+1);
        return ;
    }
    if(s[N]== t[M] && 1+go(N+1, M+1) == ret){
        putchar(s[N]);
        track(N+1, M+1);
        return;
    }
}

int main(){
    memset(d, -1, sizeof(d));
    scanf("%s%s", s,t);
    n=strlen(s), m=strlen(t);
    printf("%d\n", go(0,0));
    track(0,0);
}