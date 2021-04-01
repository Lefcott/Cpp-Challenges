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

long long int sumSquares (int n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
	int n;
	long long int ret;
	cin >> n;
	
	forsn(i, 1, n + 1) {
		ret = pow(pow(i, 2) / 2.0 + i / 2.0, 2) * 2 - pow(i, 3) - pow(i, 2) * 5 + i * 12 - 8;
		cout << ret << "\n";
	}
	
	return 0;
}

/*
 * x -> 0
 * 
 * x x -> 6
 * x x
 * 
 * x x x -> 28
 * x x x
 * x x x
 * 
 * x x x x -> 96
 * x x x x
 * x x x x
 * x x x x
 * 
 * x x x x x -> 252
 * x x x x x
 * x x x x x
 * x x x x x
 * x x x x x
 * 
 *                               -8 0   6   28  96   252   550   1056   1848
 *                             16  8  6   22  68  156   298   506    792
 *                           -2  -8 -2  16  46  88   142   208   286
 *                             -6  6  18  30  42  54    66    78
 *                           12  12 12  12  12  12  12    12
 * i    = 1
 * ref1 = [-6, -8, 8, 0]
 * ref2 = [6, -2, 6, 6]
 * ref3 = [18, 16, 22, 28]
 * ref4 = [30, 46, 68, 96]
 * ref5 = [42, 88, 156, 252]
 * ref6 = [54, 142, 298, 550]
 * ref7 = [66, 208, 506, 1056]
 * ->
 * s1  = -6 + 12
 * s2  = -8 + (-6 + 12)
 * s3  = 8  + (-8 + (-6 + 12))
 * ret = 0  + (8  + (-8 + (-6 + 12))) = 6
 * ->
 * i   = 1
 * ret = 12 + ref1[0] + ref1[1] + ref1[2] + ref1[3]
 * ===========================================================
 * i = 5
 * ref[0] = (5 - 1) * 12 - 6
 * ===========================================================
 * ref[1] = -2 + (5 - 1) * 12 - 6 + (4 - 1) * 12 - 6 + (3 - 1) * 12 - 6 + (2 - 1) * 12 - 6 + (1 - 1) * 12 - 6
 * ref[1] = -2 - i * 6 + (i - 1) * ((i - 1) + 1) / 2 * 12
 * ===========================================================
 * ref[2] = pow(i, 3) * 2                                           - pow(i, 2) * 3                                        - i * 7                        + 16
 * ref[3] = pow(i * (i + 1) / 2, 2) * 2                          - pow(i, 3) - pow(i, 2) * 3 / 2 - i / 2            - i * (i + 1) * 7 / 2               + i * 16                 - 8
 * ===========================================================
 * ->
 * ref[0] = i * 12 - 18
 * ref[1] = pow(i, 2) * 6 - i * 12 - 2
 * ref[2] = pow(i, 3) * 2 - pow(i, 2) * 3 - i * 7 + 16
 * ref[3] = pow(pow(i, 2) / 2 + i / 2, 2) * 2 - pow(i, 3) - pow(i, 2) * 5 + i * 12 - 8
 * 
 */
