#include <iostream>
#include <algorithm>
#include <vector>

#define INF 100000000

using namespace std;


int dist[101][101];

int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = INF;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int temp;
            scanf("%d", &temp);
            if(temp == 1) dist[i][j] = 1;
        }
    }   



    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


    for(int i=1; i<=n; i++ ){
        for(int j=1; j<=n; j++){
            if(dist[i][j] == INF) printf("0 ");
            else printf("1 ");
        }
        puts("");
    }
}