#include <iostream>
#include <algorithm>
using namespace std;

int p[10001];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y){
    x=find(x);
    y=find(y);
    if(x != y) p[y] = x;
}

struct edge {
    int u, v, c;
    bool operator < (const edge &o) const {
        return c < o.c;
    }
} e[100001];


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
    }
    sort(e, e+m);

    for(int i=0; i<n; i++)
        p[i] = i;
    
    int result = 0; 
    for(int i=0; i<m; i++){
        int x = e[i].u;
        int y = e[i].v;
        int cost = e[i].c;
        if(find(x) != find(y)){
            merge(x,y);
            result += cost;
        }
    }

    printf("%d", result);

}