#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cassert>
#include <map>
#define forsn(i, s, n) for(int i = (s); i < (n); ++i)
#define forn(i, n) forsn(i, 0, n)
#define forall(it, g) for(typeof g.begin() it = g.begin(); it != g.end(); ++it)
 
using namespace std;
 
int main() {
    long int n;
    map<int,bool> mappedNumbers;
    cin >> n;
    vector<int> v(n - 1);
 
    forn(i, n - 1) {
        cin >> v[i];
        mappedNumbers[v[i]] = true;
    }
    
    forn(i, n) {
        if (!mappedNumbers[i + 1]) {
            cout << i + 1;
            return 0;
        }
    }
 
    return 0;
}
