#include <iostream>
#include <algorithm>
#include <string>
#include <map>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    string p[n + 1];
    map<string, int> book;

    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        p[i] = temp;
        book[temp] = i;
    }

    string question[m];
    for (int i = 0; i < m; i++) {
        cin >> question[i];
    }
    for (int i = 0; i < m; i++) {
        if (isdigit(question[i][0])) {
            cout << p[stoi(question[i])] << '\n';
        }
        else {
            cout << book[question[i]] << '\n';
        }
    }
}