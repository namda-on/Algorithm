#include <iostream>
#include <algorithm>

using namespace std;

#define INF 100000000
int dist[101][101];

int main()
{
    int n, m; 
    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = INF;
            if(i == j) dist[i][j] = 0;
        }
    }

    for(int x=0; x<m; x++){
        int i, j, c;
        scanf("%d%d%d", &i,&j,&c);
        dist[i][j] = min(dist[i][j], c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] == INF) printf("0 ");
            else printf("%d ", dist[i][j]);
        }
        puts("");
    }

}