#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;

typedef long long lld;

lld result = 0;


void solver(int row, int column, int n) {
    if (n == 1) {
        if (row == 0 && column == 0) result += 0;
        if (row == 0 && column == 1) result += 1;
        if (row == 1 && column == 0) result += 2;
        if (row == 1 && column == 1) result += 3;
        return;
    }

    lld compare = pow(2, n - 1);
    if (row < compare && column >= compare) result += pow(2, 2 * n) / 4;
    if (row >= compare && column < compare) result += pow(2, 2 * n) / 4 * 2;
    if (row >= compare && column >= compare) result += pow(2, 2 * n) / 4 * 3;

    if (row >= compare) row = row - compare;
    if (column >= compare) column = column - compare;

    solver(row, column, n - 1);

}

int main()
{
    int n, r, c;
    scanf("%d%d%d", &n, &r, &c);
    solver(r, c, n);
    printf("%lld", result);
    return 0;
}