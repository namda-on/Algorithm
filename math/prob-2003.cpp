#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[10000], n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int r=0, l=0, sum=a[0], result=0;
    while(r<n){
        if(sum==m) result++;
        if(sum<=m) sum +=a[++r];
        else sum -=a[l++];
    }

    printf("%d", result);
}