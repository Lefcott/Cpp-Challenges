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
    int n;
    cin >> n;
    
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }
    
    for(int i = 2; i <= n; i += 2)
        cout << i << " ";
    
    for(int i = 1; i <= n; i += 2)
        cout << i << " ";
    
    return 0;
}

/*
 * 
 * 1  : 1                    : 1
 * 2  : 1 2                  : NO SOLUTION
 * 3  : 1 2 3                : NO SOLUTION
 * 4  : 1 2 3 4              : 2 4 1 3
 * 5  : 1 2 3 4 5            : 2 4 1 3 5
 * 6  : 1 2 3 4 5 6          : 2 4 6 1 3  5
 * 7  : 1 2 3 4 5 6 7        : 2 4 6 1 3  5 7
 * 8  : 1 2 3 4 5 6 7 8      : 2 4 6 8 1  3 5 7
 * 9  : 1 2 3 4 5 6 7 8 9    : 2 4 6 8 1  3 5 7 9
 * 10 : 1 2 3 4 5 6 7 8 9 10 : 2 4 6 8 10 1 3 5 7 9
 * ...
 * N  : 1 ... N : odd even
 */
