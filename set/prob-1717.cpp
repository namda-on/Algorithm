#include <iostream>
#include <algorithm>

using namespace std;

int p[1000001];


int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y){
    x=find(x);
    y=find(y);
    if(x != y) p[y] = x;
}


int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<=n; i++){
        p[i] = i;
    }

    for(int i=0; i<m; i++){
        int temp, a, b;
        scanf("%d%d%d", &temp, &a, &b);

        if(temp==0) merge(a,b);
        else{
            if(find(a) == find(b)) puts("YES");
            else puts("NO");
        }
    }
}