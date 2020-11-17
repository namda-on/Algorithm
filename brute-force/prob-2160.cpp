#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

vector<vector<string>> A;
vector<string> B;
string line;
int N, m,n, dif=350, temp=0;
int main()
{
	scanf("%d", &N);
	for (int x=0; x < N; x++) {
		for (int y=0; y < 5; y++) {
			cin >> line;
			B.push_back(line);
		}
		A.push_back(B);
		B.clear();
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int x = 0; x < 5; x++) {
				for (int y = 0; y < 7; y++) {
					if (A[i][x][y] != A[j][x][y]) temp++;
				}
			}


			if (dif > temp) {
				m = i;
				n = j;
				dif = temp;
			}
			temp = 0;
		}
	}
	printf("%d %d", m+1, n+1);

}