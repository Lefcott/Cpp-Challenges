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
    int max = 1, count = 1;
    string s;
    cin >> s;
    
    forsn(i, 1, (int) s.length()) {
        if (s[i] == s[i - 1]) {
            count++;
            if (count > max)
                max = count;
        } else {
            count = 1;
        }
    }
    cout << max;
    
    return 0;
}
