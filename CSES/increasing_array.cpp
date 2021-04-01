#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cassert>
#include <map>
#include <iterator>
#define forsn(i, s, n) for(int i = (s); i < (n); ++i)
#define forn(i, n) forsn(i, 0, n)
#define forall(it, g) for(typeof g.begin() it = g.begin(); it != g.end(); ++it)

using namespace std;

int main() {
	long long int moves = 0;
    int n, current;
    cin >> n;
    vector<int> v(n);
    
    forn(i, n)
		cin >> v[i];
	
	current = v[0];
	
	forsn(i, 1, n) {
		int diff = current - v[i];
		if (diff > 0)
			moves += diff;
		current = current > v[i] ? current : v[i];
	}
	
    cout << moves;
    
    return 0;
}

