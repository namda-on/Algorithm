#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[1001], edge[101];
int indegree[1001];

int main ()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        int t; 
        scanf("%d", &t);
        for(int k=0; k<t; k++){
            int temp;
            scanf("%d", &temp);
            edge[i].push_back(temp);
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<edge[i].size() -1; j++){
            int s = edge[i][j];
            int e = edge[i][j+1];
            v[s].push_back(e);
            indegree[e]++;
        }
    }

    queue<int> q, test;
    for(int i=1; i<=n;  i++ ){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int x = q.front();
        test.push(x);
        q.pop();
        for(int y : v[x]){
            indegree[y]--;
            if(indegree[y] == 0){
                q.push(y);
            }
        }
    }
    if(test.size() != n)printf("0");
    else {
        for(int i=0; i<n; i++){
            int temp = test.front();
            printf("%d\n", temp);
            test.pop();
        }
    }
    
}