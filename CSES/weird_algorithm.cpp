#include <iostream>
#define forsn(i, s, n) for(int i = (s); i < (n); ++i)
#define forn(i, n) forsn(i, 0, n)
#define forall(it, g) for(typeof g.begin() it = g.begin(); it != g.end(); ++it)
 
using namespace std;
 
int main() {
    long int n;
    cin >> n;
 
    while(n > 1) {
        cout << n << " ";
        n = n % 2 ? n * 3 + 1 : n / 2;
    }
    cout << n;
 
    return 0;
}
