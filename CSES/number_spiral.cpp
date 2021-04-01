#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cassert>
#include <map>
#include <iterator>
#include <cmath>
#define forsn(i, s, n) for(int i = (s); i < (n); ++i)
#define forn(i, n) forsn(i, 0, n)
#define forall(it, g) for(typeof g.begin() it = g.begin(); it != g.end(); ++it)

using namespace std;

long long int powLongInt(long long int b, int e) {
	long long int ret = b;
	forn(i, e - 1)
		ret *= b;
	return ret;
}

int main() {
	long long int n;
	cin >> n;
	long long int m[2][n];
	
	forn(i, n)
		forn(j, 2)
			cin >> m[j][i];
	
	forn(i, n) {
		long long int x = m[1][i];
		long long int y = m[0][i];
		long long int number;
		
		if (x <= y) {
			long long int yCenterNumber = y + powLongInt(y - 1, 2);
			if (y % 2 == 1)
				number = yCenterNumber - (y - x);
			else
				number = yCenterNumber + (y - x);
		} else {
			long long int xCenterNumber = x + powLongInt(x - 1, 2);
			if (x % 2 == 1) {
				number = xCenterNumber + (x - y);
			}
			else
				number = xCenterNumber - (x - y);
		}
		
		cout << number << "\n";
	}
	
	return 0;
}

/*
 * x y   result
 * 1 1 --> 1
 * |
 * |
 * |
 * 2 1 --> 2
 * 2 2 --> 3
 * ---------
 * 1 2 --> 4
 *   |
 *   |
 *   |
 * 1 3 --> 5
 * 2 3 --> 6
 * 3 3 --> 7
 * ---------
 * 3 2 --> 8
 * 3 1 --> 9
 * |
 * |
 * |
 * 4 1 --> 10
 * 4 2 --> 11
 * 4 3 --> 12
 * 4 4 --> 13
 * ----------
 * 3 4 --> 14
 * 2 4 --> 15
 * 1 4 --> 16
 *   |
 *   |
 *   |
 * 1 5 --> 17
 * 2 5 --> 18
 * 3 5 --> 19
 * 4 5 --> 20
 * 5 5 --> 21
 * ----------
 * 5 4 --> 22
 * 5 3 --> 23
 * 5 2 --> 24
 * 5 1 --> 25
 * 
 * x: 1 2 2 1 1 2 3 3 3 4 4 4 4 3 2 1 1 2 3 4 5 5 5 5 5
 * 
 * (x, y):
 * (1, 1) -> 1
 * (2, 2) -> 1 + ((1) + 1)
 * (3, 3) -> 1 + ((1) + 1) + ((1 + 2) + 1)
 * (4, 4) -> 1 + ((1) + 1) + ((1 + 2) + 1) + ((2 + 3) + 1)
 * (5, 5) -> 1 + ((1) + 1) + ((1 + 2) + 1) + ((2 + 3) + 1) + ((3 + 4) + 1)
 * (6, 6) -> 1 + ((1) + 1) + ((1 + 2) + 1) + ((2 + 3) + 1) + ((3 + 4) + 1) + ((4 + 5) + 1)
 * 
 * ->
 * (x, y):
 * (1, 1) -> 1    |         |         |         |         |      = 1
 * (2, 2) -> 1 + (1 + 1)    |         |         |         |      = 3
 * (3, 3) -> 1 + (1 + 1) + (3 + 1)    |         |         |      = 7
 * (4, 4) -> 1 + (1 + 1) + (3 + 1) + (5 + 1)    |         |      = 13
 * (5, 5) -> 1 + (1 + 1) + (3 + 1) + (5 + 1) + (7 + 1)    |      = 21
 * (6, 6) -> 1 + (1 + 1) + (3 + 1) + (5 + 1) + (7 + 1) + (9 + 1) = 31
 * 
 * -> y + pow(y - 1, 2)
 * 
 */
