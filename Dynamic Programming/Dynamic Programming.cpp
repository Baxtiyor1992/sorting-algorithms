/*
 
 Find a way with less amount.
 
 Input:
    n - size of matrix
    n x n -> matrix of way costs
 
 Sample:
 
 3
 1, 4, 3
 6, 1, 7
 3, 8, 5
 
 Way matrix:
 
 1,  5,  8
 7,  6, 13,
 10, 14, 18,
 
 Output: 18
 
 */

#include <iostream>

using namespace std;

const int N = 5;

int map[N][N];
int ways[N][N];

int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			ways[i][j] = 0;
		}
	}

	ways[0][0] = map[0][0];
	for (int i=1; i<n; i++) {
		ways[0][i] = ways[0][i - 1] + map[0][i];
		ways[i][0] = ways[i - 1][0] + map[i][0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (ways[i - 1][j] < ways[i][j - 1]) {
				ways[i][j] = ways[i - 1][j] + map[i][j];
			} else {
				ways[i][j] = ways[i][j - 1] + map[i][j];
			}
		}
	}

	cout << ways[n - 1][n - 1];

	return 0;
}
