#include <iostream>

using namespace std;

int main() {
    int t, n, m;
    
    cin >> t;
    
    do {
        cin >> n;
        cin.ignore();
        cin >> m;

        cout << n*(m-1) + m*(n-1) << endl;
    }while(--t);
    
    return 0;
}