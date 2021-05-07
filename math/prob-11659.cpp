#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n+1], s[n+1];
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    s[0] = 0;
    s[1] = a[1];
    for(int i=2; i<=n; i++ ){
        s[i] = s[i-1] + a[i];
    }


    while(m--){
        int i, j;
        scanf("%d%d", &i, &j);
        printf("%d\n", s[j] - s[i-1]);
    }
}